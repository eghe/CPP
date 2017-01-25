#include "Decorator.h"
#include "ShapeDecorator.h"

int main()
{
    BaseDecorator *base = new Decorator1(new Decorator2(new Decorator1(new BaseDecorator())));
    base->doSmth();


    ShapeDecorator *dec = new RedShapeDecorator(new BlueShapeDecorator(new Circle()));
    dec->draw();
    return 0;
}
