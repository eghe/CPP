#include <memory>
#include <cstdlib>
#include <ctime>
#include <iostream>

void f(int *p)
{
    std::cout << *p << std::endl;
}

void g(int *p, int init)
{
    std::cout << *p << " " << init << std::endl;
}

int h() throw()
{
    throw 10;
    return 1;
}

int main()
{
    std::shared_ptr<int> p1 = std::make_shared<int>(10);
    std::shared_ptr<int> p2(new int(20));
    std::shared_ptr<int> p3 = p1;
    f(p1.get());
    f(p2.get());
    f(p3.get());
    
    /*
        make_share is a template function, is safer than using new
        if rand throws an exception here, mem leaks occur
        make_share is used to replace the init of a shared ptr through constructor.
        make_share is safer because it performs a single allocation, compared to shared_ptr(new int(10)) - which has 2 allocations, one allocation new int and another when the shared_ptr constructor is called
        in the g function, memory leak can occur if new int(10) is called then rand throws an exception before calling shared_ptr constructor
    */

   // g(std::shared_ptr<int>(new int(10)).get(), h());
    g(std::shared_ptr<int>(new int(10)).get(), rand());

    return 0;
}
