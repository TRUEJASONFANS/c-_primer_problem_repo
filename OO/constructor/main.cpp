//
// Created by zhxie on 8/9/2022.
//

#include <iostream>
#include <map>

class C {
public:
    explicit C(int i)
    {   j = i;
        std::cout << "constructor called for "<<j << std::endl;;
    }
    C(const C& c1) {
        std::cout << "copy constructor called for "<<j << std::endl;;
        this->j = c1.j;
    }
    ~C()
    { std::cout << "destructor called for "<<j<< std::endl; }



private:
    int j;
public:
    static std::map<int, C>  c_map;
};

class D {
public:
    D(int i1, int i2)
    {
        this->j1 = i1;
        this->j2 = i2;

        std::cout << "D constructor called for "<<j1 <<" "<< j2 << std::endl;;
    }
    D(const D& d1) {
        std::cout << "copy constructor called for "<<j1 <<" "<< j2 << std::endl;;
        this->j1 = d1.j1;
        this->j2 = d1.j2;
    }
    ~D()
    { std::cout << "destructor called for "<<j1 <<" "<< j2 << std::endl; }


private:
    int j1, j2;
public:
    static std::map<int, D>  d_map;
};

std::map<int,C> C::c_map;
std::map<int,D> D::d_map;

int main() {

    //C c1(1);
    //C::c_map.insert(std::map<int, C>::value_type(1, c1));
    //C::c_map.insert(std::pair<int, C>(1, c1));
    //C::c_map.emplace(1, 1);

    D::d_map.emplace(1, D(2,3));
}