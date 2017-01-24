#include "Meal.h"

int main()
{
    MealBuilder mb;
    Meal mv = mb.buildVegMeal();
    Meal mm = mb.buildMeatMeal();

    double costV = mv.getCost();
    mv.printItems();
    std::cout << costV << std::endl;

    double costM = mm.getCost();
    mm.printItems();
    std::cout << costM << std::endl;
    return 0;
}
