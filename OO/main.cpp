//
// Created by zhxie on 4/19/2022.
//
#include "abstrctc1.h"
#include "instanceof.h"
#include <iostream>
using std::cout;
using std::endl;

using namespace  OO::TEST;
using namespace OO;

int main() {
    Sub1* s1 = new Sub1();
    s1->setAbstract(s1);
    //s1->foo();

    using OO::instanceof;
    GaugeBase* g1 = new Gauge();
    GaugeBase* g2 = new GaugeGroup;
    if(instanceof<Gauge>(g1)) {
        std::cout << "g1 is a gauge class" << endl;
    }
    if(instanceof<GaugeGroup>(g2)) {
        std::cout << "g2 is a gaugegroup class" << endl;
    }
    return 0;
}

