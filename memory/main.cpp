//
// Created by zhxie on 3/31/2022.
//

#include <iostream>
#include <memory>
#include "UniquePtrTest.h"

using  std::cout;
using std::string;
int main() {
    auto nullPtr = std::unique_ptr<string>(nullptr);

    // 创建初始ptr
    std::unique_ptr<int> ptr(new int(10));

    // 1 传引用
    std::cout << asRef(ptr) << std::endl;

    // 2 移交所有权
    /*
        作为参数传入时release
        一定要取得返回值，否则内存泄漏
    */
    int re =  asOwner(std::move(ptr));

    std::cout << re << std::endl;

    return 0;
}
