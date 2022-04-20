#include <iostream>

typedef std::pair<int, double> Dir;

class B {

};

class A {
private:
    Dir d; //16
    int i; // 4
    bool b1; // 4(1)

};

class C {
    double d1;
    Dir d;
};


using std::cout;
using std::string;
using std::endl;

int main() {
    Dir d;
    cout << "Dir sizeof:" << sizeof(d) << endl;
    A a;
    cout << "a sizeof:" << sizeof(a) << endl;
    cout << "B*: sizeof" << sizeof(B*) << endl;
    cout << "C: sizeof" << sizeof(C) << endl;

    string s;
    cout << "string sizeof: " << sizeof(s);
    s = "123456789";
    cout << "string sizeof: " << sizeof(s);
    return 0;
}
