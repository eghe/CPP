#ifndef __SINGLETON_H_
#define __SINGLETON_H_

#include <iostream>

class Singleton
{
    static Singleton *instance;
    Singleton() {}
    Singleton(const Singleton &s) {}
    Singleton& operator=(const Singleton &s) {}

public:
    static Singleton& getInstance() 
    {
        if(!instance)
        {
            instance = new Singleton();
        }
        return *instance;
    }

    void print()
    {
        std::cout << "Instnce  " << instance << std::endl;
    }
};

Singleton* Singleton::instance = NULL;

#endif
