//
// Created by zhxie on 2022/3/29.
//

#include <iostream>
#include <memory>
#include "enable_if.h"
using namespace  std;
int main() {

    int *p = new int(3);
    std::shared_ptr<int> sp = std::make_shared<int>(3);
    check(sp);
    check(p);
    delete p;

    return 0;
}
