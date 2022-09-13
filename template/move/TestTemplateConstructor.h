//
// Created by zhxie on 2022/9/13.
//

#ifndef C___PRIMER_PROBLEMS_TESTTEMPLATECONTRUTOR_H
#define C___PRIMER_PROBLEMS_TESTTEMPLATECONTRUTOR_H

class B {

};
class A {
public:
    template<class T>
    A (T&& t):b_(std::move(t))
    {}

private:
    B b_;
};

#endif //C___PRIMER_PROBLEMS_TESTTEMPLATECONTRUTOR_H
