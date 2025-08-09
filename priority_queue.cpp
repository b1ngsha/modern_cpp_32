#include <functional> // std::greater
#include <iostream>   // std::cout/endl
#include <memory>     // std::pair
#include <queue>      // std::priority_queue

int main()
{
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    pq.push({1, 1});
    pq.push({2, 2});
    pq.push({0, 3});
    pq.push({9, 4});

    while (!pq.empty())
    {
        std::cout << pq.top().first << " " << pq.top().second << std::endl;
        pq.pop();
    }
}