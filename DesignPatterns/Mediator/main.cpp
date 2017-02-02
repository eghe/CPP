#include <iostream>
#include "Mediator.h"

int main() {
    IMediator *mediator = new ConcreteMediator();
    IColleague *c1 = new ConcreteColleague();
    IColleague *c2 = new ConcreteColleague();
    IColleague *c3 = new ConcreteColleague();

    mediator->registerColleague(c1);
    mediator->registerColleague(c2);
    mediator->registerColleague(c3);

    c1->sendMessage(mediator, "Hello from c1");
    c2->sendMessage(mediator, "Hello from c2");
    c3->sendMessage(mediator, "Hello from c3");

    return 0;
}
