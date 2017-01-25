#ifndef __SHAPE_DECORATO_H
#define __SHAPE_DECORATO_H

#include <iostream>

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle final: public Shape {
public:
    virtual void draw() const override {
        std::cout << "Draw circle" << std::endl;
    }
};

class Square final: public Shape {
public:
    virtual void draw() const override {
        std::cout << "Draw square" << std::endl;
    }
};

class ShapeDecorator: public Shape {
protected:    
    Shape *shape;
public:
    ShapeDecorator(Shape *parent = nullptr) {
        shape = parent;    
    }
    
    // override the draw from shape
    virtual void draw() const override {
        if(shape)
            shape->draw();
        dDraw();
    };

    virtual void dDraw() const {
    }
};

class RedShapeDecorator: public ShapeDecorator {
public:
    RedShapeDecorator(Shape *parent) {
        shape = parent;    
    }

    virtual void dDraw() const override {
        std::cout << "Red decorator" << std::endl;
    }
};

class BlueShapeDecorator: public ShapeDecorator {
public:
    BlueShapeDecorator(Shape *parent) {
        shape = parent;    
    }

    virtual void dDraw() const override {
        std::cout << "Blue decorator" << std::endl;
    }
};
#endif
