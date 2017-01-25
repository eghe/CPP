#include <iostream>

/*
    1. Enums are not type safe
       Enums export their enumerators outside their scope. If there are two enumerators with the same name, it will be a collision (None). To fix this, put the enumerations in different namespaces
*/

enum Color { None, Red, Blue};

// Colision, None is also in color
enum Shape {/*None,*/ Circle, Square};

namespace NSColor {
    enum Color_ {None, Red, Blue};
};

namespace NSShape {
    enum Shape_ {None, Circle, Square};
};

/*
    2. Underlying types - default is int
       If a enumerator has a value bigger than an int, the bwhaviour si compiler dependent.
       Specify a underlying type
*/

enum Nums {A = 0, B = 0xFFFF0000U};
/*
namespace NSNums {
    // not allowd in gcc, allowed in > VC5
    enum Nums_ : unsigned int {
        A = 0, B = 0xFFFF0000U  
    };
};*/

/*
    3. Forward declaration not allowed, because we don't know the underlying size of the enumerator
*/

/*
error - use of enum without previous declaration

enum Cars;

void g(Cars c) {
    std::cout << "Car: " << c << std::endl;
}

enum Cars {BMW, VW, Audi};
*/

enum Empty{};

////////////////////////////
/*
    C++11 - strongly typed enums
*/

enum class Cars {Ferrary, Porche, MiniCooper};

void f(int x)
{
    std::cout << x << std::endl;
}

int main() {
    // 1.
    //Color c1 = Color::Red; // error - color not class or namespace
    Color c = Red;
    f(1);
    f(Blue); // implicit conversion to int
    std::cout << "size(color) " << sizeof(Color) << std::endl;
    std::cout << "size(empty) " << sizeof(Empty) << std::endl;
    std::cout << "size(nums) " << sizeof(Nums) << std::endl;

    NSColor::Color_ c_ = NSColor::Blue;
    f(c_); 

    f(B); // prints -65536 - B is bigger than int
    //NSNums::Nums_ num = NSNums::B;

    //g(VW);

    ///////// C++11
    Cars car = Cars::Ferrary;
    std::cout << "size(cars) " << sizeof(Cars) << " c: " << std::endl;

    //f(car); // error cannot convert cars to int

    return 0;
}
