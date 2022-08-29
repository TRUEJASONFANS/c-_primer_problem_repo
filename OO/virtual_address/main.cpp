//
// Created by zhxie on 4/27/2022.
//
#include<iostream>
using std::cout;
using std::endl;

struct Base
{
    virtual void func1() = 0;

    virtual void func2() = 0;

    virtual void func3() = 0;

    virtual void func4() = 0;
};



class A : public Base
{
public:
    A() = default;;

    virtual ~A() = default;

    void func1() override {
        cout << "func1" << endl;
    };

    void func2() override {
        cout << "func2" << endl;
    };

    void func3() override {
        cout << "func3" << endl;
    };

    void func4() override {
        cout << "func4" << endl;
    };


};


typedef void(*Fun)();

int main() {

    void* pObject = new A();
    Fun fp = nullptr;

    cout << "virtual function address" << &pObject << endl;
    cout << "virtual function address" << reinterpret_cast<long*>(*static_cast<long*>(pObject)) << endl;

    for (int i= 0; i < 4; i++) {
        fp = (Fun)*((long *) *(long *) &pObject + i);
        fp();
    }
    return 0;
}
