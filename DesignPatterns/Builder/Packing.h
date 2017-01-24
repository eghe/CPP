#ifndef __PACKING_H__
#define __PACKING_H__

#include <string>

class Packing {
public:
    virtual std::string pack() const = 0;
    virtual ~Packing()
    {
    }
};

class Bottle: public Packing {
public:
    std::string pack() const
    {
        return "Bottle";
    }
    ~Bottle()
    {
    }
};

class Wrapper: public Packing {
public:
    std::string pack() const
    {
        return "Wrapper";
    }
    ~Wrapper()
    {
    }
};
#endif
