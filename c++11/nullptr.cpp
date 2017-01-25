#include <iostream>

void fct(int *p)
{
}

int main()
{
    int *p1 = NULL;
    int *p2 = nullptr;
    
    /*
    nullptr allows conversions to bool and to NULL but not implicit conversions to int
    */

    if(p1 == p2)
        std::cout << "p1 == p2" << std::endl;

    if(!p2)     
        std::cout << "p2 is null " << std::endl;

    int x1 = NULL; 
    std::cout << x1 << std::endl; // print 0
      
    // error, can not convert nullptr_t to int  
    //int x2 = nullptr;   
      
    bool b = nullptr;
        
    return 0;
}
