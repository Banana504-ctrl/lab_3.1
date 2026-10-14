#include <iostream>

/*class xray {
    public:
    xray() {
        std::cout<< __PRETTY_FUNCTION__ <<std::endl;
    }

    xray(const xray &) {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;

    }

    xray(int, int) {
        std::cout<< __PRETTY_FUNCTION__ << std::endl;
    }; 

    ~xray() {
        std::cout<< __PRETTY_FUNCTION__ <<std::endl;
    }
};*/

template<typename T> 

class smart_ptr {

    T* ptr;
    int *counter;

    public:
    smart_ptr(T *p) : ptr{p}, counter{new int{1}} {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    };

    smart_ptr(const smart_ptr &u) : ptr{u.ptr}, counter{u.counter} {
        std::cout<< __PRETTY_FUNCTION__ <<std::endl;
        ++ *counter;
    };

    smart_ptr(smart_ptr &&u) : ptr{u.ptr}, counter{u.counter} {
        std::cout<< __PRETTY_FUNCTION__ <<std::endl;
        u.counter = nullptr; 
    }

    /*auto get() {
        return ptr;
    }*/

    auto use_count() {
        return *counter;
    }
    
    ~smart_ptr() {
        std::cout<< __PRETTY_FUNCTION__ <<std::endl;
        if (counter && (--*counter == 0 )) { 
            delete ptr;
            delete counter;
        }
    }
};
