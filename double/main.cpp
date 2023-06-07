#include <iostream>
#include <iomanip>
#include <limits>

using std::cout;
using std::endl;
int main() {
    double a = 123456789;
    double b = 123456789.123456789123456789;
    double c = 0.123456789123456789;

    double zero = 0.;

    cout << std::numeric_limits<double>::digits10 + 1 << endl;
    cout << sizeof(a) << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << b - a << endl;

    cout << std::setprecision (std::numeric_limits<double>::digits10 + 1)  << c << endl;;

    return 0;
}