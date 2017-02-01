#include <iostream>
#include "GenericSmartPointer.h"

class Test {
public:
    int getTest() {return 0;}
    Test* getThis() {return this;}

    ~Test() {
        std::cout << "~Test" << std::endl;
    }
};

int main()
{
    SP<int> p1(new int(11));
    std::cout << *p1 << std::endl;
    
    SP<Test> p2(new Test());
    std::cout << p2->getTest() << std::endl;
    std::cout << p2->getThis() << std::endl;

    /*
        For GenericSmartPoiter: problem
        When p3 goes out of the scope, p3 is destroyed, p2 will b invalid
        need to implement reference counting
    */

    {
        SP<Test> p3 = p2;
        std::cout << p3->getTest() << std::endl;
        std::cout << p3->getThis() << std::endl;
    }
    std::cout << p2->getTest() << std::endl;
    std::cout << p2->getThis() << std::endl;

    // double free corruption

    return 0;
}
