#include<iostream>
#include "Composite.h"

int main()
{
    Composite c("item1");
    Composite *c2 = new Composite("item2");
    c.add(new Leaf("leaf1"));
    c.add(new Leaf("leaf2"));
    c.add(c2);
    c2->add(new Leaf("leaf3"));
    
    c.printData();
      
    return 0;
}
