#ifndef __GENERIC_SMART_POINTER_H
#define __GENERIC_SMART_POINTER_H

template <typename T>
class SP {
    T *p;
public:
    SP(T *ptr): p(ptr) {}

    T operator*() {
        return *p;
    }

    T* operator->() {
        return p;
    }

    ~SP() {
        std::cout << "~SP" << std::endl;
        delete p;
    }
};

#endif
