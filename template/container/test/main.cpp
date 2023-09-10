//
// Created by Administrator on 2023/9/10.
//

#include <tuple>
#include  "Container.h"

template<typename...>
struct LIST2{};



int main(){
    type_list<int, float, bool> l;
    static_assert(std::is_same_v<typename front<decltype(l)>::type, int>);

    std::tuple<int, float, bool> t;
    front_t<decltype(t)> first;

    LIST2<int, bool, bool> a;
    front_t<decltype(a)> first2;

    bool b = contains_type_v<bool, decltype(t)>;
}