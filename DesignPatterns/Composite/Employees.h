#ifndef __EMPLOYEES_H
#define __EMPLOYEES_H

#include <iostream>
#include <string>
#include <vector>

class Employees {
    std::string name;
    std::string department;
    std::vector<Employees> list;
public:
    Employees(std::string name_, std::string dep_): name(name_), department(dep_) {}
    void addSubEmployee(Employees &emp)
    {
        list.push_back(emp);
    }
    void print()
    {
        std::cout << "name: " << name << std::endl;
        for(int i = 0; i < list.size(); i++)
        {
            std::cout << "   - " << list[i].name << std::endl; 
        }
    }
};

#endif
