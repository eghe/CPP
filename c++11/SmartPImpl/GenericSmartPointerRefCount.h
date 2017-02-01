#ifndef __GENERIC_SMART_POINTER_REF_COUNT_H
#define __GENERIC_SMART_POINTER_REF_COUNT_H

#include <iostream>

class Reference {
    int count;
public:
    Reference(int c = 0): count(c) {}

    void addReference() {count++;}
    int releaseReference() {return --count;}

    int getReference() { return count; }
};

template <typename T>
class SP {
    T *data;
    Reference *ref;
public:
    SP(): data(0), ref(0) {
        ref = new Reference(0);
        ref->addReference();    
    }

    SP(T *p): data(p), ref(0) {
        ref = new Reference(0);
        ref->addReference();
    }

    SP(const SP<T> &p): data(p.data), ref(p.ref) {
        ref->addReference();
    }

    T& operator*() {
        return *data;
    }

    T* operator->() {
        return data;
    }

    SP<T>& operator=(const SP<T> &p) {
        // avoid self assignment
        if(this != &p)
        {
            // decrement ref count for current obj
            if(ref->releaseReference() == 0)
            {
                delete data;
                delete ref;
            }

            data = p.data;
            ref = p.ref;
            ref->addReference();
        }
    }

    ~SP()
    {
        if(ref->releaseReference() == 0)
        {
            delete data;
            delete ref;
        }
    }
    
    int getRefCount() { return ref->getReference(); }
};

#endif
