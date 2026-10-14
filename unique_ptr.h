#include <iostream>
#include <utility>
#include <stdio.h>

//закинь это дерьмо на гит

/*class xray {
    public: 
    xray() {
        std::cout<< __PRETTY_FUNCTION__ << std::endl;
    };

    xray(const xray &) {
        std::cout<< __PRETTY_FUNCTION__ << std::endl;
    }; 

    xray(int, int) {
        std::cout<< __PRETTY_FUNCTION__ << std::endl;
    }; 
    
    ~xray() {
        std::cout<< __PRETTY_FUNCTION__ << std::endl;
    }; 
};*/

struct DefaultDeleter {
    template<typename T>
    void operator()(T *p) {
        delete p;
    }
};

template<typename T, typename D=DefaultDeleter>
class UnqPtr {
    T *ptr; 
    D d;

    public: 

    UnqPtr(T *p) : ptr{p} {
        std::cout<< __PRETTY_FUNCTION__ << std::endl;
    }

    UnqPtr(UnqPtr &u) = delete; 
    
    UnqPtr(UnqPtr &&u) : ptr{u.ptr} {
        std::cout<< __PRETTY_FUNCTION__ << std::endl;
        u.ptr = nullptr;
    }

    T *get() {
        return ptr; 
    }

    ~UnqPtr() {
        std::cout<< __PRETTY_FUNCTION__ << std::endl;
        d(ptr);
    }

};

template<typename T, typename... Args>
UnqPtr<T> make_UnqPtr(Args &&... args) {
    return UnqPtr<T>(new T(std::forward<Args>(args)...));
}