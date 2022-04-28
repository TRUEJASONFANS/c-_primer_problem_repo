//
// Created by zhxie on 4/27/2022.
//
#include<iostream>
using std::cout;
using std::endl;

struct IMyInterface
{
    virtual void func1() = 0;

    virtual void func2() = 0;

    virtual void func3() = 0;

    virtual void func4() = 0;
};

class S1 {

public :
    const int a = 1;
};

class CMyClass : public IMyInterface
{
public:
    CMyClass() {
    };

    virtual ~CMyClass() = default;

    virtual void func1() override {
        cout << "func1" << endl;
    };

    virtual void func2() override {
        cout << "func2" << endl;
    };

    virtual void func3() override {
        cout << "func3" << endl;
    };

    virtual void func4() override {
        cout << "func4" << endl;
    };
    static void f1(const ) {
        return;
    }
    static CMyClass* s;
    static CMyClass m;
    int a = 1;
};

CMyClass* CMyClass::s = new CMyClass();
CMyClass CMyClass::m;

typedef void(*Fun)(void);

int main() {
    cout << CMyClass::s->a << endl;
    cout << CMyClass::m.a << endl;
    IMyInterface * pObject = new CMyClass();
    Fun fp = nullptr;

    cout << "virtual function address" << &pObject << endl;
    cout << "virtual function address" << (long*) *(long *) &pObject << endl;
    cout << "virtual function address" << (long *) *(long *) &pObject << endl;

    for (int i= 0; i < 4; i++) {
        fp = (Fun)*((long *) *(long *) &pObject + i);
        fp();
    }
    return 0;
}
