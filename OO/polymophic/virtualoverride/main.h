//
// Created by zhxie on 9/20/2022.
//

#ifndef C___PRIMER_PROBLEMS_VIRTRUAL_OVERIDE_H
#define C___PRIMER_PROBLEMS_VIRTRUAL_OVERIDE_H

#include <iostream>
using std::cout;
using std::endl;

class A {

public:
    A() {
        cout<< "A construct " << endl;
    }
    virtual  ~A() {
        cout<< "A destruct " << endl;
    }
};

class B : public A{
public:
    B() {
        cout<< "B construct " << endl;
    }
    ~B() override {
        cout<< "B destruct " << endl;
    }

};

class C : public B {
public:
    C() {
        cout<< "C construct " << endl;
    }
    ~C() override {
        cout<< "C destruct " << endl;
    }
};


#endif //C___PRIMER_PROBLEMS_MAIN_H
