#include <iostream>
#include "Singleton.h"

using namespace std;

int main()
{
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();
    
    s1.print();
    s2.print();

    return 0;
}
