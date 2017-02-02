#ifndef __VISITOR_H
#define __VISITOR_H

class Tabaco;
class Chocolate;
class Liquor;

class IVisitor {
public:
    virtual double visit(Tabaco *tabaco) = 0;
    virtual double visit(Chocolate *chocolate) = 0;
    virtual double visit(Liquor *liquor) = 0;
};

class IVisitable {
public:
   virtual double accept(IVisitor *visitor) = 0; 
};


class Tabaco: public IVisitable {
   double price;
public:
   Tabaco(double p): price(p) {}
   virtual double accept(IVisitor *visitor) {
       return visitor->visit(this);
   }
   double getPrice() { return price; } 
};

class Chocolate: public IVisitable {
   double price;
public:
   Chocolate(double p): price(p) {}
   virtual double accept(IVisitor *visitor) {
       return visitor->visit(this);
   }
   double getPrice() { return price; } 
};

class Liquor: public IVisitable {
   double price;
public:
   Liquor(double p): price(p) {}
   virtual double accept(IVisitor *visitor) {
       return visitor->visit(this);
   }
   double getPrice() { return price; } 
};

class TaxVisitor: public IVisitor {
public:
    virtual double visit(Tabaco *tabaco) {
        return tabaco->getPrice() * 1.24;
    }
    virtual double visit(Chocolate *chocolate) {
        return chocolate->getPrice() * 1.10;
    }
    virtual double visit(Liquor *liquor) {
        return liquor->getPrice() * 1.18;
    }
};

class TaxHolidayVisitor: public IVisitor {
public:
    virtual double visit(Tabaco *tabaco) {
        return tabaco->getPrice() * 1.28;
    }
    virtual double visit(Chocolate *chocolate) {
        return chocolate->getPrice() * 1.16;
    }
    virtual double visit(Liquor *liquor) {
        return liquor->getPrice() * 1.22;
    }
};

#endif
