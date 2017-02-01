#include <iostream>
#include "GenericSmartPointerRefCount.h"

using namespace std;

int main() {
    SP<int> p1(new int(10));
    SP<int> p3(new int(11));

    { 
        SP<int> p2 = p1;
        cout << *p1 << " " << *p2 << endl;
        cout << "p1 ref " << p1.getRefCount() << std::endl;
        cout << "p2 ref " << p2.getRefCount() << std::endl;
    }

    cout << "p1 ref " << p1.getRefCount() << std::endl;
   
    SP<int> p2;
    p2 = p3;
    cout << "p2 ref " << p2.getRefCount() << std::endl;
    cout << "p3 ref " << p3.getRefCount() << std::endl;

    p2 = p1;
    cout << "p2 ref " << p1.getRefCount() << std::endl;
    cout << "p2 ref " << p2.getRefCount() << std::endl;
    cout << "p3 ref " << p3.getRefCount() << std::endl;

    return 0;
}
