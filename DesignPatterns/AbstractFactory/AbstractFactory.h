#ifndef __ABSTRACT_FACTORY__H
#define __ABSTRACT_FACTORY__H

#include <cstring>
#include "Shape.h"
#include "Color.h"

class AbstractFactory
{
public:
    virtual Shape* getShape(const char* shape) const = 0;
    virtual Color* getColor(const char* color) const = 0;
};


class ShapeFactory: public AbstractFactory
{
public:
   Shape* getShape(const char* shape) const
   {
        if(strcmp(shape, "circle") == 0)
            return new Circle();
        if(strcmp(shape, "rectangle") == 0)
            return new Rectangle();
        return NULL;         
   }
   Color* getColor(const char* color) const {return NULL;}
};

class ColorFactory: public AbstractFactory
{
public:
   Shape* getShape(const char *shape) const {return NULL;}

   Color* getColor(const char* color) const
   {
        if(strcmp(color, "red") == 0)
            return new Red();
        if(strcmp(color, "blue") == 0)
            return new Blue();
        return NULL;         
   }
};

class FactoryProducer
{
public:
    static AbstractFactory* getFactory(const char* factory)
    {
        if(strcmp(factory, "shape") == 0)
            return new ShapeFactory();
        if(strcmp(factory, "color") == 0)
            return new ColorFactory();    
    }
};

#endif
