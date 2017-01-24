#ifndef __ITEM_H_
#define __ITEM_H_

#include <string>
#include "Packing.h"

class Item {
public:    
    virtual std::string name() const = 0;    
    virtual Packing* packing() const = 0;
    virtual double price() const = 0;

    virtual ~Item()
    {
    }
};

class Burger: public Item {
    Packing *p;
public:
   Burger(): p(new Wrapper()) {}
   Packing* packing() const
   {
        return p;   
   }
   ~Burger()
   {
       delete p;
   }
};

class VegBurger: public Burger {
public:
    std::string name() const
    {
        return "VegBurger";
    }
    double price() const
    {
        return 1.2;
    }
    ~VegBurger()
    {
    }
};

class ChickenBurger: public Burger {
public:
    std::string name() const
    {
        return "ChickenBurger";
    }
    double price() const
    {
        return 2.2;
    }
   ~ChickenBurger()
   {
   }
};

class ColdDrink: public Item {
    Packing *p;
public:
    ColdDrink(): p(new Bottle()) {}
    Packing* packing() const
    {
        return p;
    }
   ~ColdDrink()
   {
       delete p;
   }
};

class Coke: public ColdDrink
{
public:
    std::string name() const
    {
        return "Cola";   
    }
    double price() const
    {
        return 1.5;
    }
   ~Coke()
   {
   }
};

class Pepsi: public ColdDrink
{
public:
    std::string name() const
    {
        return "Pepsi";
    }
    double price() const
    {
        return 1.45;
    }
   ~Pepsi()
   {
   }
};

#endif

