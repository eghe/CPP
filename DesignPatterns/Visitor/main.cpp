#include <iostream>
#include "Visitor.h"

int main() {
    IVisitor *v1 = new TaxVisitor();
    IVisitor *v2 = new TaxHolidayVisitor();

    Tabaco *t = new Tabaco(15.5);
    Chocolate *c = new Chocolate(3.5);
    Liquor *l = new Liquor(20.5);
    
    std::cout << "tabaco " << t->accept(v1) << std::endl;
    std::cout << "chcolate " << c->accept(v1) << std::endl;
    std::cout << "liquor " << l->accept(v1) << std::endl;

    return 0;
}
