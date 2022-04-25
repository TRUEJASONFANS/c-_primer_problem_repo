//
// Created by zhxie on 4/24/2022.
//

#include <iostream>

using std::cout;
using std::endl;


class X1 {
public:

    X1() {
        cout<< "invoke constructor" << endl;
    };

    explicit X1(const X1 &obj)  {   //拷贝构造函数
        cout << "invoke copy constructor" << endl;
    };

    X1(X1&& obj)  {
        cout << "invoke move constructor" << endl;
    };

    X1& operator=(const X1 &obj) {
        cout << "invoke value assign constructor " << endl;
        if(this == &obj) {
            return *this;
        }
        return *this;
    };

    X1& operator=(const X1 && obj) {
        cout << "invoke move value assign constructor " << endl;
        if(this == &obj) {
            return *this;
        }
        return *this;

    };

    ~X1() {
        cout << "invoke deconstruct" << endl;
    };



};

int main() {
//    X1 l1(1);
//    X1 l3(2);
    X1 l4 = X1();

    return 0;
}