//
// Created by zhxie on 3/31/2022.
//

#include <iostream>
#include <memory>
#include <cassert>

using  std::cout;
using std::string;
int main() {
    auto nullPtr = std::unique_ptr<string>(nullptr);
    assert(nullPtr);
    return 0;
}
