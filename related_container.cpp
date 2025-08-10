#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <tuple>

int main()
{
    std::set<int> s{1, 1, 1, 2, 3, 4};
    for (auto i : s)
        std::cout << i << " ";
    std::cout << std::endl;

    std::multiset<int, std::greater<int>> ms{1, 1, 1, 2, 3, 4};
    for (auto i : ms)
        std::cout << i << " ";
    std::cout << std::endl;

    std::map<std::string, int> mp{
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4}};
    for (auto i : mp)
        std::cout << i.first << " " << i.second << std::endl;
    std::cout << std::endl;
    mp.insert({"four", 4});
    for (auto i : mp)
        std::cout << i.first << " " << i.second << std::endl;
    std::cout << std::endl;

    bool exist = mp.find("four") == mp.end();
    if (exist)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    exist = mp.find("five") == mp.end();
    if (exist)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    mp["five"] = 5;
    for (auto i : mp)
        std::cout << i.first << " " << i.second << std::endl;
    std::cout << std::endl;

    std::multimap<std::string, int> mmp{
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
    };
    for (auto i : mmp)
        std::cout << i.first << " " << i.second << std::endl;
    std::cout << std::endl;

    mmp.insert({"four", -4});
    for (auto i : mmp)
        std::cout << i.first << " " << i.second << std::endl;
    std::cout << std::endl;

    std::cout << mp.find("four")->second << std::endl;
    std::cout << mp.lower_bound("four")->second << std::endl;
    std::cout << (--mp.upper_bound("four"))->second << std::endl;
    std::cout << mmp.lower_bound("four")->second << std::endl;
    std::cout << (--mmp.upper_bound("four"))->second << std::endl;

    std::multimap<std::string, int>::iterator lower, upper;
    std::tie(lower, upper) = mmp.equal_range("four");
    bool eq = (lower == upper);
    if (eq)
        std::cout << "range is empty" << std::endl;
    else
        std::cout << "range is not empty" << std::endl;
    std::cout << lower->second << std::endl;
    std::cout << (--upper)->second << std::endl;
}