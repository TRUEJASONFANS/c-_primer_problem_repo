//
// Created by zhxie on 5/31/2022.
//
#include <iostream>

using std::cout;
using std::endl;

int main() {
    unsigned char x = 128;
    unsigned char* xp = &x;

    char* yp = reinterpret_cast<char*> (xp);
    std::string s(yp);

    cout << x << endl;
    cout << *yp << endl;
    cout << s << endl;
    return 0;
}