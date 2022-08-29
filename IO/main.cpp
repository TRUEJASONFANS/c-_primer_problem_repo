//
// Created by zhxie on 6/23/2022.
//
#include <string>
#include <fstream>
#include "iostream"
#include "ofstream.h"


void dumpGaugeOffset(std::string directory) {

    std::string dumpGaugeName = directory  + "gaugeOffsetInfo.gauge";
    std::ofstream ofs(dumpGaugeName.c_str(), std::ios::out | std::ios::app);
    if (ofs.is_open()) {
        ofs << "name" << std::endl;
        ofs << "jason" << std::endl;
    }
    ofs.close();

}

int main() {
    dumpGaugeOffset("C:\\Users\\zhxie\\tmp\\");
    std::cout << "finished";
    return 0;
}
