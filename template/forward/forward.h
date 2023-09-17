//
// Created by Administrator on 2023/9/17.
//

#ifndef C___PRIMER_PROBLEMS_FORWARD_H
#define C___PRIMER_PROBLEMS_FORWARD_H

#include <iostream>

class forward {

public:


    template<typename T>
    void wrapper(T&& arg) {
        std::cout << typeid(arg).name() << std::endl;

        // arg will be a lvalue
        process(std::forward<T>(arg));
    }


    void process(int& value) {
        value = 3;
        std::cout << "Lvalue reference: " << value << std::endl;
        std::cout << &value << std::endl;
    }

    void process(int&& value) {
        std::cout << "Rvalue reference: " << value << std::endl;
    }

};


#endif //C___PRIMER_PROBLEMS_FORWARD_H
