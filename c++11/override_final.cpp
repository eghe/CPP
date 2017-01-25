#include <iostream>

/*
    override - to indicate that a method is an override not an overload of a 
    method from a base class
    final - use if we don't want to overload a method down the hierarchy
*/

class A {
public:
    // whithowt override - the methds from B are overloaded
    virtual void f1(short x)
    {
        std::cout << "A: f1 " << x << std::endl;
    }
    virtual void f2(int x) const
    {
        std::cout << "A: f2 " << x << std::endl;
    }

    //////////////////////////////////////////////////////
    virtual void f3(int x)
    {
        std::cout << "A: f3 " << std::endl;
    }
    virtual void f4(int x) final
    {
        std::cout << "A: f4 " << std::endl;
    }
};

class B final: public A {
public:
    virtual void f1(int x)
    {
        std::cout << "B: f2 " << x << std::endl;
    }
    virtual void f2(int x)
    {
        std::cout << "B: f2 " << x << std::endl;
    }

    //////////////////////////////////////////////////////
    // virtual void f3(short x) override - error, should have same signature as A
    virtual void f3(int x) override final
    {
        std::cout << "B: f3 " << x << std::endl;
    }

    // error can not override final method
    //virtual void f4(int x) {}
};

// C can not dereive from B, B is final
//class C: public B {
//};

int main()
{
    A *obj = new B();
    B b;

    obj->f1(1); // will call A::f1 because B::f1 is an overload not override
    b.f1(2); // will call B::f1

    obj->f2(1); // call A::f2
    b.f2(2); // B::f2
    
    const A *obj1 = new B(); // A::f2
    obj1->f2(1);

    obj->f3(5);
        
    return 0;
};


