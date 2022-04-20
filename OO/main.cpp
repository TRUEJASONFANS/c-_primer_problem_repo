//
// Created by zhxie on 4/19/2022.
//
//#include "abstrctc1.h"
#include <iostream>
using namespace  std;

class Abstract1 {

public:
    virtual void  foo() = 0;
};

class Sub1: Abstract1 {

public:
    Abstract1* a1;
    void foo () {
        //std::cout <<"foo" << std::endl;
        a1->foo();
    }
    void setAbstract(Sub1* p) {
        a1 = p;
    }
};

int main() {
    Sub1* s1 = new Sub1();
    s1->setAbstract(s1);
    s1->foo();
    return 0;
}