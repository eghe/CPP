#ifndef __MEAL_H__
#define __MEAL_H__
#include <iostream>
#include <vector>
#include "Item.h"
#include "Packing.h"

class Meal {
    std::vector<Item*> items;
public:
    void addItem(Item *item)
    {
        items.push_back(item);
    }

    double getCost() const
    {
        double cost = 0;
        for(int i = 0; i < items.size(); i++)
        {
            cost += items[i]->price();
        }
        return cost;
    }

    void printItems() const
    {
        for(int i = 0; i < items.size(); i++)
        {
            std::cout << "-----" << std::endl;
            std::cout << "Name: " << items[i]->name() << std::endl;
            std::cout << "Pack: " << items[i]->packing()->pack() << std::endl;
            std::cout << "Price: " << items[i]->price() << std::endl;
        }
    }

    ~Meal()
    {
        for(std::vector<Item*>::iterator it = items.begin(); it != items.end(); it++ )
        {
            delete *it;
        }
        items.clear();
    }
};

class MealBuilder {
public:
    Meal buildVegMeal() const
    {
        Meal meal;
        meal.addItem(new VegBurger());
        meal.addItem(new Coke());
        return meal;
    }
    Meal buildMeatMeal() const
    {
        Meal meal;
        meal.addItem(new ChickenBurger());
        meal.addItem(new Pepsi());
        return meal;
    }
};

#endif

