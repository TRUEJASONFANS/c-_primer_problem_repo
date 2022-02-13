#include <iostream>
#include "MSharePtr.h"
#include "template/debug.h"
using namespace  std;
int main() {

    MSharePtr<string> m1;
    int a[] = {1, 2 ,3};

    //
    string s = "xx111";
    string *p = &s;
    cout<< debug_rep(p);
    return 0;
}
