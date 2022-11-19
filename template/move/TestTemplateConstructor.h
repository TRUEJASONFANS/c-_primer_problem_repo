//
// Created by zhxie on 2022/9/13.
//

#ifndef C___PRIMER_PROBLEMS_TESTTEMPLATECONTRUTOR_H
#define C___PRIMER_PROBLEMS_TESTTEMPLATECONTRUTOR_H

using std::cout;
using std::endl;

class B {
public:
    B(int a) {
        this->a = a;
        cout << "constructor" << endl;
    }

    B(B&& b2) {
        a = std::move(b2.a);
        cout << "move constructor" << endl;
    }
private:
    int a;

};
class A {
public:
    template<class T>
    A (T&& t):b_(std::move(t))
    {

    }

private:
    B b_;
};

#endif //C___PRIMER_PROBLEMS_TESTTEMPLATECONTRUTOR_H
