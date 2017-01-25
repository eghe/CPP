#ifndef __COMPOSITE_H_
#define __COMPOSITE_H_

#include <string>
#include <vector>
#include <iostream>

class CompositeBase {
public:
    virtual void printData() const = 0;
    virtual ~CompositeBase() 
    {
    }
};

class Composite: public CompositeBase {
    std::string data;
    std::vector<CompositeBase*> list;
public:
    Composite(std::string d): data(d) {}
    void printData() const
    {
        std::cout << "Comp " << data << std::endl;
        for(int i = 0; i < list.size(); i++)
        {
            std::cout << "   - ";
            list[i]->printData();
            std::cout << std::endl;
        }
    }
    
    void add(CompositeBase *item)
    {
        list.push_back(item);
    }

    ~Composite()
    {
        for(std::vector<CompositeBase*>::iterator it = list.begin(); it != list.end(); it++)
        {
            delete *it;
        }
    }
};

class Leaf: public CompositeBase {
    std::string data;
public:
    Leaf(std::string d): data(d) {}
    void printData() const
    {
        std::cout << "Leaf " << data << std::endl;
    }
    ~Leaf()
    {
    }
};

#endif
