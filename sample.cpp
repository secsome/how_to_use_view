// Author : secsome
// Last Updated : 2021/07/06 Tue 13:42
// Tested Environment : VS2022 Preview 1.1 with /std:c++20

#include <iostream>
#include <sstream>
#include <ranges>
#include <vector>

void view_all();
void view_iota();
void view_counted();
void view_take();
void view_takewhile();
void view_drop();
void view_dropwhile();
void view_split();
void view_join();
void view_keys();
void view_values();
void view_reverse();
void view_transform();
void view_filter();
void view_istream();
void view_elements();

int main()
{
    view_all();
    view_iota();
    view_counted();
    view_take();
    view_takewhile();
    view_drop();
    view_dropwhile();
    view_split();
    view_join();
    view_keys();
    view_values();
    view_reverse();
    view_transform();
    view_filter();
    view_istream();
    view_elements();
}

void view_all()
{
    std::cout << __FUNCTION__ << "\n";

    std::vector<int> ints{ 1,3,8,4,6,9 };
    auto nums = std::views::all(ints);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";

}

void view_iota()
{
    std::cout << __FUNCTION__ << "\n";

    auto nums = std::views::iota(0, 6);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_counted()
{
    std::cout << __FUNCTION__ << "\n";

    std::vector<int> ints{ 1,3,8,4,6,9 };

    auto nums = std::views::counted(ints.begin(), 4);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_take()
{
    std::cout << __FUNCTION__ << "\n";

    auto nums =
        std::views::iota(0, 6) |
        std::views::take(4);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_takewhile()
{
    std::cout << __FUNCTION__ << "\n";

    auto check = [](int x)
    {
        return x <= 5 || x % 4 != 0;
    };

    auto nums =
        std::views::iota(0, 20) |
        std::views::take_while(check);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_drop()
{
    std::cout << __FUNCTION__ << "\n";

    auto nums =
        std::views::iota(0, 6) |
        std::views::drop(4);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_dropwhile()
{
    std::cout << __FUNCTION__ << "\n";

    auto check = [](int x)
    {
        return x <= 5 || x % 4 != 0;
    };

    auto nums =
        std::views::iota(0, 20) |
        std::views::drop_while(check);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_split()
{
    std::cout << __FUNCTION__ << "\n";

    auto split_view = std::views::iota(0, 10) | std::views::split(5);
    for (auto const& split : split_view) 
    {
        for (auto x : split)
            std::cout << x << " ";
        std::cout << "\n";
    }

    std::cout << "\n\n\n";
}

void view_join()
{
    std::cout << __FUNCTION__ << "\n";

    const std::vector<std::vector<int>> v{ {1,2}, {3,4,5}, {6}, {7,8,9} };
    auto nums = std::views::join(v);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_keys()
{
    std::cout << __FUNCTION__ << "\n";

    std::vector<std::pair<int, std::string>> src{ {12, "one"},{114,"two"},{2, "three"},{984, "FoUR"},{9115, "Fifth"},{1,"666"} };

    for (auto x : src | std::views::keys)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_values()
{
    std::cout << __FUNCTION__ << "\n";

    std::vector<std::pair<int, std::string>> src{ {12, "one"},{114,"two"},{2, "three"},{984, "FoUR"},{9115, "Fifth"},{1,"666"} };

    for (auto x : src | std::views::values)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_reverse()
{
    std::cout << __FUNCTION__ << "\n";

    auto nums = std::views::iota(0, 6) | std::views::reverse;

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_transform()
{
    std::cout << __FUNCTION__ << "\n";

    auto work = [](int x) {return x *= x; };
    auto nums = std::views::iota(0, 6) | std::views::transform(work);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_filter()
{
    std::cout << __FUNCTION__ << "\n";

    auto check = [](int x) {return x % 2 == 0; };
    auto nums = std::views::iota(0, 6) | std::views::filter(check);

    for (auto x : nums)
        std::cout << x << " ";
    std::cout << "\n\n\n";
}

void view_istream()
{
    std::cout << __FUNCTION__ << "\n";

    std::istringstream iss{ "Hello View World !" };
    auto strs = std::ranges::istream_view<std::string>(iss);

    for (auto x : strs)
        std::cout << x << "\n";
    std::cout << "\n\n\n";
}

void view_elements()
{
    std::cout << __FUNCTION__ << "\n";

    std::vector<std::tuple<int, double, std::string>> src{ {1, 3.1, "A"} ,{-3, 3.1415, "B"}, {2147, 1000.2, "c!"} };

    for (auto x : src | std::views::elements<0>)
        std::cout << x << " ";
    std::cout << "\n";
    for (auto x : src | std::views::elements<1>)
        std::cout << x << " ";
    std::cout << "\n";
    for (auto x : src | std::views::elements<2>)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "\n\n\n";
}
