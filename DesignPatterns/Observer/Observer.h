#ifndef __OBSERVER_H
#define __OBSERVER_H

#include <iostream>
#include <vector>

class Subject;

class Observer {
protected:
   Subject *subj;   
public:
    virtual void update() {};
};

class Subject {
    std::vector<Observer*> obs;
    int state;
public:
    Subject(): state(0) {}
    
    void attach(Observer *o) {
        obs.push_back(o);
    }

    void setState(int s) {
        state = s;
        notifyAll();
    }

    void notifyAll() {
        for(std::vector<Observer*>::iterator it = obs.begin(); it != obs.end(); it++)
        {
           (*it)->update();
        }
    }
    
    int getState() { return state; }
};


class ObserverA: public Observer {
public:    
    ObserverA(Subject *s) {
        subj = s;
        s->attach(this);
    }

    virtual void update() {
        std::cout << "Update A, state subj: " << subj->getState() << std::endl;    
    }
};

class ObserverB: public Observer {
public:
    ObserverB(Subject *s) {
        subj = s;
        s->attach(this);
    }
    
    virtual void update() {
        std::cout << "Update B, state subj: " << subj->getState() << std::endl;
    }
};
#endif
