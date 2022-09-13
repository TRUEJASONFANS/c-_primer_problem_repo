//
// Created by zhxie on 2022/6/20.
//

#ifndef C___PRIMER_PROBLEMS_STACK_H
#define C___PRIMER_PROBLEMS_STACK_H
#include <deque>

template <typename T, template <typename > class CONST = std::deque>
class Stack {

private:
    CONST<T> elems;

public:
    void push(const T &t);
    void pop();
    T top() const;
    bool empty() const {
        return elems.empty();
    }
};


#endif //C___PRIMER_PROBLEMS_STACK_H
