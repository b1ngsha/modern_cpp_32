#include <complex>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

namespace std
{
    template <typename T>
    struct hash<std::complex<T>>
    {
        size_t operator()(const std::complex<T> &v) const noexcept
        {
            hash<T> h;
            return h(v.real()) + h(v.imag());
        }
    };
}

int main()
{
    std::unordered_set<int> s{
        1, 1, 2, 3, 5, 8, 13, 21};
    for (auto i : s)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::unordered_map<std::complex<double>, double> umc{{{1.0, 1.0}, 1.4142}, {{3.0, 4.0}, 5.0}};
    for (auto i : umc)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }
    std::cout << std::endl;
}