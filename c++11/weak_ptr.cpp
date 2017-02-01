#include <iostream>
#include <memory>

/*
    weak_ptr is used to break the circular references.
    Ex A has reference to B and B to A. Both obects own each other so deconstructors are not called
*/

struct B;
struct A {
    std::shared_ptr<B> b;
    ~A() {
        std::cout << "~A" << std::endl;
    }
};

struct B {
    // std::shared_ptr<A> a; - circual dep
    std::weak_ptr<A> a;
    ~B() {
        std::cout << "~B" << std::endl;
    }
};

int main()
{
    std::shared_ptr<int> p = std::make_shared<int>(10);
    std::weak_ptr<int> wp = p;

    // std::cout << wp.get() << std::endl; - can not make get on wp
    std::cout << *p << std::endl;
    {

        if(auto q = wp.lock())
             // q is a shared_ptr, copy wp to a shared ptr before usage
            std::cout << *q << std::endl;
        else
            std::cout << "wp is expired";    
    }

    if(wp.expired())
        std::cout << "wp expired" << std::endl;

    p.reset();

    // after reset, wp will be expired
    if(wp.expired())
        std::cout << "wp expired" << std::endl;

    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();   

    // deconstructor of A and B not called, circullar dep
    /*
    a->b = b;
    b->a = a;
    */

    // make B have a weak_ptr to A
    a->b = b;
    b->a = a;
}
