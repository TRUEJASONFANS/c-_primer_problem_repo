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
    const std::string s = "x";
};

class A : public Base
{
public:
    void fun2() override { cout << "A::fun2" << endl; }
};


typedef void(*Fun)();

int main() {
    typedef void (*F)();
    Base* base = new Base();
    cout << "base pointer:" << base<< endl;
    intptr_t* p1 = (intptr_t*)base; // 虚表 指针， *p1 是虚表地址
    cout << "virtual pointer address:" << *p1 << endl;
    intptr_t p2 = *(intptr_t*)(*p1);
    cout << p2 << endl;
    for (int i = 0; i < 3; ++i) {
        void* funcAddr = (intptr_t*)p2 + sizeof(intptr_t) * i;
        cout << funcAddr << ' ';
        ((F)(funcAddr))();
    }
    cout << endl;// p2[0], p2[1], p2[2]

//    A* a = new A();
//    long* p3 = (long*)a;
//    long* p4 = (long*)(*p3);
//    for (int i = 0; i < 3; ++i) {
//        cout << p4[i] << ' ';
//    }
//    cout << endl; // p4[0] == p4[0] , p4[1], p2[2] == p4[2]


//    a = new A();
//    long* p5 = (long*)a;
//    long* p6 = (long*)(*p3);
//    F f4 = (F)p6[0];
//    F f5 = (F)p6[1];
//    F f6 = (F)p6[2];
//
//    f4(); //Base::fun1
//    f5(); //A::fun2`
//    f6(); //Base::fun3
    return 0;
}
