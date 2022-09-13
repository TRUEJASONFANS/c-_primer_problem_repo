//
// Created by zhxie on 7/7/2022.
//

#include <iostream>

class C {
public:
    explicit C(int i)
    {   j = i;
        std::cout << "constructor called for "<<j << std::endl;;
    }
    ~C()
    { std::cout << "destructor called for "<<j<< std::endl;; }

private:
    int j;
};

int main() {


    C c3(3);
    C c4(4);
}