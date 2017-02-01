#include <iostream>
#include "Command.h"

int main() {
    Stock s;
    
    Order *bs = new BuyStock(s);
    Order *ss = new SellStock(s);
    
    Broker b;
    b.takeOrder(bs);
    b.takeOrder(ss);

    b.placeOrders();

    delete bs;
    delete ss;

    return 0;
}
