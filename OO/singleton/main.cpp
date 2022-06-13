//
// Created by zhxie on 6/13/2022.
//


#include <iostream>
#include <map>

using std::cout;
using std::string;
using std::map;

class Singleton {
public :
    static const Singleton* getInstance() {
        static Singleton s;
        x = 3;
        return &s;
    }
    static  int* const X() {
        return &x;
    }
    map<string, string>* keyVal2;
    static int x;
private:
    map<string, string> keyVal;
    static int result;
};

int Singleton::x = 3;


int main() {
    const Singleton *a = Singleton::getInstance();
    *(a->X()) = 3;
    int * x  = a->X();
    int q = 5;
    x = &q;

    cout << *x;
    return 0;
}