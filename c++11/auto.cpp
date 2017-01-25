#include <iostream>
#include <vector>

int fct1()
{
    // auto i = "Aaa"; -compilation error
    auto i = 10; // ok
    return i;
}

// add trailing return typr
auto fct2(int x, int y) -> decltype(x + y)
{
    return x + y;
}

int main()
{
    auto i = 10;
    std::vector<int> v(10);
    for(auto it = v.begin(); it != v.end(); it++)
        std::cout << *it << " " ;
    
    std::cout << std::endl;
    std::cout << fct1() << std::endl;    
    std::cout << fct2(1, 2) << std::endl;    

    return 0;
}
