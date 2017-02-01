#ifndef __STRATEDY_H
#define __STRATEDY_H

#include <iostream>

class Strategy {
public:
    virtual void doOperation() = 0;
};

class StrategyAdd: public Strategy {
public:
    virtual void doOperation() {
        std::cout << "Add" << std::endl;
    }
};

class StrategySub: public Strategy {
public:
    virtual void doOperation() {
        std::cout << "Sub" << std::endl;
    }
};

class Context {
    Strategy *s;
public:
    Context(Strategy *s_): s(s_) {}

    void executeStrategy() {
        s->doOperation();   
    }
};

#endif

