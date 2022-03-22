//
// Created by zhxie on 3/21/2022.
//

#ifndef C___PRIMER_PROBLEMS_UNIQUEPTRTEST_H
#define C___PRIMER_PROBLEMS_UNIQUEPTRTEST_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;
class Tony {
public:
    string GetFullName(){
        return "Tony " + last_name_;
    }
    void SetLastName(string lastname) {
        last_name_ = lastname;
    }
private:
    std::string last_name_;
};
#endif //C___PRIMER_PROBLEMS_UNIQUEPTRTEST_H
