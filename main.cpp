#include <iostream>
#include "MSharePtr.h"
#include "template/debug.h"
#include "memory/UniquePtrTest.h"
#include "memory/Movie.h"

using namespace  std;
int main() {

    MSharePtr<string> m1;
    int a[] = {1, 2 ,3};


    //
    string s = "xx111";
    string *p = &s;
    cout<< debug_rep(p) << endl;

    // test UniquePtr
    unique_ptr <Movie> movie(new Movie());
    auto tony = movie->addTony();
    cout << tony->GetFullName();

    return 0;
}
