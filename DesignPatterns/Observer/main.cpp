#include <iostream>
#include "Observer.h"

int main() {
    Subject *s = new Subject();
    
    Observer *a = new ObserverA(s);  
    Observer *b = new ObserverB(s);  
    
    s->setState(1);
    s->setState(2);

    return 0;
}
