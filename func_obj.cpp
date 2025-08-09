#include <algorithm>  // std::sort
#include <functional> // std::less/greater/hash
#include <iostream>   // std::cout/endl
#include <string>     // std::string
#include <vector>     // std::vector

int main()
{
    std::vector<int> v{13, 6, 4, 11, 29};
    for (auto const &i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::sort(v.begin(), v.end());
    for (auto const &i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::sort(v.begin(), v.end(), std::greater<int>());
    for (auto const &i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto hp = std::hash<int *>();
    std::cout << "hash(nullptr) = " << hp(nullptr) << std::endl;
    std::cout << "hash(v.data()) = " << hp(v.data()) << std::endl;
    std::cout << "v.data() = " << static_cast<void *>(v.data()) << std::endl;

    auto hs = std::hash<std::string>();
    std::cout << "hash(\"hello\") = " << hs(std::string{"hello"}) << std::endl;
    std::cout << "hash(\"help\") = " << hs(std::string{"help"}) << std::endl;
}