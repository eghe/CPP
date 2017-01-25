#ifndef __DECORATOR_H
#define __DECORATOR_H

#include <iostream>

/*
    Generic implementation of the Decorator pattern
*/

class Base {
public:
    virtual void doSmth() const = 0;
};

class BaseDecorator: public Base {
protected:
    Base *parent;    
public:
    BaseDecorator(Base *base = nullptr): parent(base) {}

    virtual void doSmth() const override {
        if(parent)
            parent->doSmth();
        doSmthMore();    
    }

    virtual void doSmthMore() const {
        std::cout << "BaseDecorator do smth" << std::endl;
    }
};

class Decorator1: public BaseDecorator {
public:
    Decorator1(Base *base) {
        parent = base;    
    }

    virtual void doSmthMore() const override {
        std::cout << "Decorator1" << std::endl; 
    }
};

class Decorator2: public BaseDecorator {
public:
    Decorator2(Base *base) {
        parent = base;    
    }

    virtual void doSmthMore() const override {
        std::cout << "Decorator2" << std::endl; 
    }

};

#endif
