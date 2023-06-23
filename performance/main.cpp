//
// Created by zhxie on 11/7/2022.
//

#include <vector>
#include <chrono>
#include <iostream>
#include <cassert>

using namespace std;

int main() {

    std::vector<int> a= {1, 2, 3};
    std::vector<int> b= {23, 2, 32};
    auto aa = a;
    auto bb = b;

    double t = 0.;
    for (int i = 0 ; i < 1 ; i++) {
        a = aa;
        b = bb;
        assert(a.size() == 3);
        assert(b.size() == 3);
        auto start = std::chrono::steady_clock::now();
        a.insert(a.end(), b.begin(), b.end());
        auto end =std::chrono::steady_clock::now();
        t = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count() + t;
    }

    cout<<"time = "<< t / 100.0;  //输出时间（单位：ｓ）

    auto t2 = 0.;
    for (int i =0;  i < 1; i++) {
        a = aa;
        b = bb;
        assert(a.size() == 3);
        assert(b.size() == 3);
        auto start = std::chrono::steady_clock::now();
        for (const auto&  j : b) {
            a.emplace_back(j);
        }
        auto end =std::chrono::steady_clock::now();

        t2 = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count() + t2;
    }



    cout<<"time = "<< t2/ 100.0<<endl;  //输出时间（单位：ｓ）

    for (const auto&  j : b) {
        cout << j << " ";
    }
    return 0;
}