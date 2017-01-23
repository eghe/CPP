#ifndef __SHAPE__H_
#define __SHAPE__H_

#include <cstring>

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {};
};

class Circle: public Shape {
public:
    void draw() const
    {
        std::cout << "Draw circle" << std::endl;
    }

    ~Circle() {};
};

class Rectangle: public Shape {
public:
    void draw() const
    {
        std::cout << "Draw rectangle" << std::endl;
    }
    
    ~Rectangle() {};
};

class ShapeFactory {
public:
    Shape* getShape(const char *shape)
    {
        if(strcmp(shape, "circle") == 0)
            return new Circle();
        if(strcmp(shape, "rectangle") == 0)
            return new Rectangle();    
        return NULL;    
    }
};

class ShapeFactoryDemo {
public:
   void demo()
   {
        ShapeFactory fact;
        Shape *s1 = fact.getShape("circle");   
        Shape *s2 = fact.getShape("rectangle");
        
        s1->draw();
        s2->draw();   
   }
};
#endif


