#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>

class Color
{
public:
    virtual void fill() = 0;
};

class Red: public Color
{
public:
    void fill()
    {
        std::cout << "Fill with red" << std::endl;
    }
};

class Blue: public Color
{
public:
    void fill()
    {
        std::cout << "Fill with blue" << std::endl;
    }
};

#endif

