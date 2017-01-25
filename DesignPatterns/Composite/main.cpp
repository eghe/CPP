#include <iostream>
#include "Employees.h"

int main()
{
    Employees emp1("gigi", "mgt");
    Employees emp2("ion", "sales");
    Employees emp3("radu", "account");

    emp1.addSubEmployee(emp2);
    emp1.addSubEmployee(emp3);

    emp1.print();
    
    return 0;
}
