#include "Widget.h"

using namespace WidgetStuff;

int main() {

    Widget<double> w1(1.0);
    Widget<double> w2(2.0);
    swap(w1, w2);
    w1.print();
    return 0;
}