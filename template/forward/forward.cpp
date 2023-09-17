//
// Created by Administrator on 2023/9/17.
//

#include "forward.h"
int main() {
    int x = 42;
    forward f;
    f.wrapper(x);           // 调用 process(int& value)，输出 "Lvalue reference: 42"
    std::cout << x << std::endl ;
    f.wrapper(123);         // 调用 process(int&& value)，输出 "Rvalue reference: 123"
    f.process(42);
}