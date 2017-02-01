#include <memory>
#include <iostream>

void f(int *p)
{
    std::cout << *p << std::endl;
}

int main()
{
    std::unique_ptr<int> p1(new int(10));  
    f(p1.get());
    std::unique_ptr<int> p2 = std::move(p1);

    if(p1)
        f(p1.get());
    else 
        std::cout << "p1 null" << std::endl; // enters here, due to move    

    f(p2.get());

    return 0;
}
