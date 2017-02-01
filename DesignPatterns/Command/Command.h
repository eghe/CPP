#ifndef __COMMAND_H
#define __COMMAND_H

#include <iostream>
#include <vector>

// request
class Stock {

public:
    void buy() {
       std::cout << "buy stock" << std::endl; 
    }

    void sell() {
       std::cout << "sell stock" << std::endl; 
    }
};

class Order {

public:
    virtual void execute() = 0;
};

class BuyStock : public Order {
    Stock stock;
public:
    BuyStock(Stock &s) {
        stock = s;
    }

    virtual void execute() {
        stock.buy();
    }
};

class SellStock : public Order{
    Stock stock;
public:
    SellStock(Stock &s) {
        stock = s;
    }

    virtual void execute() {
        stock.sell();
    }
};

class Broker {
    std::vector<Order*> orders;
public:
    void takeOrder(Order *order) {
        orders.push_back(order);        
    }

    void placeOrders() {
        for(std::vector<Order*>::iterator it = orders.begin(); it != orders.end(); it++)
        {
            (*it)->execute();
        }
    }
};

#endif
