//
// Created by Administrator on 2023/9/10.
//

#include <tuple>
#include  "Container.h"

template<typename...>
struct LIST2{};



int main(){
    container::type_list<int, float, bool> l;
    static_assert(std::is_same_v<typename container::front<decltype(l)>::type, int>);

    std::tuple<int, float, bool> t;
    container::front_t<decltype(t)> first;

    LIST2<int, bool, bool> a;
    container::front_t<decltype(a)> first2;

    bool b = container::contains_type_v<bool, decltype(t)>;
}