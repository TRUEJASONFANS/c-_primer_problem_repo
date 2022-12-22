//
// Created by zhxie on 5/17/2022.
//

#include "stow_private.h"


int main()
{
    A a;

    // Use the stowed private member pointer
    std::cout << a.*stowed<A_x>::value << std::endl;
};