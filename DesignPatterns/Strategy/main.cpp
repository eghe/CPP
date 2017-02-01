#include <iostream>
#include "Strategy.h"

int main() {
    Strategy *add = new StrategyAdd();
    Strategy *sub = new StrategySub();
    Context c1(add);
    Context c2(sub);

    c1.executeStrategy(); 
    c2.executeStrategy(); 
    
    return 0;
}
