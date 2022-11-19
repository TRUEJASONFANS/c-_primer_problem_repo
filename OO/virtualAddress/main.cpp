//
// Created by zhxie on 4/27/2022.
//
#include<iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual void fun1() { cout << "Base::fun1" << endl; }
    virtual void fun2() { cout << "Base::fun2" << endl; }
    virtual void fun3() { cout << "Base::fun3" << endl; }
};

class A : public Base
{
public:
    void fun2() override { cout << "A::fun2" << endl; }
};


typedef void(*Fun)();

int main() {

    Base* base = new Base();
    long* p1 = (long*)base; // 虚表 指针， *p1 是虚表地址
    long* p2 = (long*)(*p1);
    for (int i = 0; i < 3; ++i) {
        cout << p2[i] << ' ';
    }
    cout << endl;// p2[0], p2[1], p2[2]

    A* a = new A();
    long* p3 = (long*)a;
    long* p4 = (long*)(*p3);
    for (int i = 0; i < 3; ++i) {
        cout << p4[i] << ' ';
    }
    cout << endl; // p4[0] == p4[0] , p4[1], p2[2] == p4[2]


    typedef void (*F)();

    F f1 = (F)p2[0];
    F f2 = (F)p2[1];
    F f3 = (F)p2[2];
    f1(); //Base::fun1
    f2(); //Base::fun2
    f3(); //Base::fun3

    a = new A();
    long* p5 = (long*)a;
    long* p6 = (long*)(*p3);
    F f4 = (F)p6[0];
    F f5 = (F)p6[1];
    F f6 = (F)p6[2];

    f4(); //Base::fun1
    f5(); //A::fun2`
    f6(); //Base::fun3
    return 0;
}
