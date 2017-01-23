#ifndef __DEMO_H_
#define __DEMO_H_

#include "AbstractFactory.h"

class DemoAbstractFactory
{
public:
    void demo()
    {
        AbstractFactory *fctS = FactoryProducer::getFactory("shape");
        AbstractFactory *fctC = FactoryProducer::getFactory("color");

        Shape *s1 = fctS->getShape("circle");
        Shape *s2 = fctS->getShape("rectangle");

        s1->draw();
        s2->draw();

        Color *c1 = fctC->getColor("red");
        Color *c2 = fctC->getColor("blue");

        c1->fill();
        c2->fill();
    }
};

#endif
