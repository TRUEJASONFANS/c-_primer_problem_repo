//
// Created by zhxie on 5/11/2022.
//

#ifndef C___PRIMER_PROBLEMS_STDFUNCTION_H
#define C___PRIMER_PROBLEMS_STDFUNCTION_H
#include <functional>
#include <iostream>
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};

void print_num(int i)
{
    std::cout << i << '\n';
}

struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

#endif //C___PRIMER_PROBLEMS_STDFUNCTION_H
