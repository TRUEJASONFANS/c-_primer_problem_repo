//
// Created by zhxie on 4/19/2022.
//

#ifndef C___PRIMER_PROBLEMS_ABSTRCTC1_H
#define C___PRIMER_PROBLEMS_ABSTRCTC1_H

#include <iostream>

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
};

#endif //C___PRIMER_PROBLEMS_ABSTRCTC1_H
