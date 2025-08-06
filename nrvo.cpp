#include <iostream>
#include <utility>

class Obj
{
public:
    Obj()
    {
        std::cout << "Obj()" << std::endl;
    }

    Obj(const Obj &)
    {
        std::cout << "Obj(const Obj&)" << std::endl;
    }

    Obj(const Obj &&)
    {
        std::cout << "Obj(const Obj&&)" << std::endl;
    }
};

Obj simple()
{
    Obj obj;
    // return single object (nrvo)
    return obj;
}

Obj simple_with_move()
{
    Obj obj;
    // move will ban nrvo
    return std::move(obj);
}

Obj complicated(int n)
{
    Obj obj1;
    Obj obj2;
    // return multiple object (no nrvo)
    if (n % 2 == 0)
    {
        return obj1;
    }
    else
    {
        return obj2;
    }
}

int main()
{
    std::cout << "*** 1 ***" << std::endl;
    auto obj = simple();
    std::cout << "*** 2 ***" << std::endl;
    auto obj2 = simple_with_move();
    std::cout << "*** 3 ***" << std::endl;
    auto obj3 = complicated(42);
}