#ifndef __MEDIATOR_H
#define __MEDIATOR_H

#include <iostream>
#include <vector>

class IMediator;

class IColleague {
public:
    virtual void sendMessage(IMediator *mediator, const std::string &str) = 0;
    virtual void receiveMessage(std::string msg) = 0;
};


class IMediator {
protected:    
    std::vector<IColleague*> colleagues;
public:
    virtual void distributeMessage(IColleague *colleague, const std::string &str) = 0;
    virtual void registerColleague(IColleague *colleague) = 0;
};

class ConcreteMediator: public IMediator {
public:
    virtual void distributeMessage(IColleague *colleague, const std::string &str) {
        for(std::vector<IColleague*>::iterator it = colleagues.begin(); it != colleagues.end(); it++) {
            if(*it != colleague)
                (*it)->receiveMessage(str);
        }
    }
    virtual void registerColleague(IColleague *colleague) {
        colleagues.push_back(colleague);   
    }
};

class ConcreteColleague: public IColleague {
public:
    virtual void sendMessage(IMediator *mediator, const std::string &str) {
        mediator->distributeMessage(this, str);
    }
    virtual void receiveMessage(std::string msg) {
        std::cout << "Received: " << msg << std::endl;
    }
};

#endif
