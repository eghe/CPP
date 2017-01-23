#include <iostream>
#include "Shape.h"

int main()
{
    Circle c;
    Shape *s = new Circle();
    s->draw();

    ShapeFactoryDemo demo;
    demo.demo();

    /*
    char *x = new char[10];
    std::cout << x << " " << &x << std::endl;
    x = "aaa";
    std::cout << x << " " << &x << std::endl;
    delete x;
    // invalid free
    */
    // fix:
    const char *x = "aa";
    std::cout << x << " " << &x << std::endl;

    //delete s;

    return 0;
}
