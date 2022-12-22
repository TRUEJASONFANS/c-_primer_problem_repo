//
// Created by zhxie on 2022/9/13.
//
#include <iostream>
#include <utility>
#include "TestTemplateConstructor.h"

int main() {
    B b(2);
    A a(b);

    B && b1 =  B(1);


}