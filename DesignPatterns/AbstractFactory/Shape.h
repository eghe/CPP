#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <iostream>

class Shape
{
public:
    virtual void draw() const = 0;
};

class Circle: public Shape
{
public:
    void draw() const
    {
        std::cout << "Draw circle" << std::endl;    
    }
};

class Rectangle: public Shape
{
public:
    void draw() const
    {
        std::cout << "Draw rectangle" << std::endl;
    }
};

#endif

