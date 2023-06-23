#include <iostream>
#include "MSharePtr.h"
#include "template/debug.h"
#include "memory/Movie.h"

using std::string;
using std::cout;
using std::endl;

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
