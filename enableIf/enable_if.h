//
// Created by zhxie on 2022/3/29.
//

#ifndef C___PRIMER_PROBLEMS_ENABLE_IF_H
#define C___PRIMER_PROBLEMS_ENABLE_IF_H

#include <type_traits>
#include <memory>

template <typename _Tp>
struct Smart_pointer : public std::false_type {};

template <typename _Tp>
struct Smart_pointer<std::weak_ptr<_Tp>> : public std::true_type {};
template <typename _Tp>
struct Smart_pointer<std::shared_ptr<_Tp>> : public std::true_type {};

template <typename _Tp>
struct is_smart_pointer : public Smart_pointer<typename std::remove_cv<_Tp>::type>{};

template <typename _Tp>
typename std::enable_if<is_smart_pointer<_Tp>::value,void>::type check(_Tp p){
    std::cout << "is smart pointer" << std::endl;
}
template <typename _Tp>
typename std::enable_if<!is_smart_pointer<_Tp>::value,void>::type check(_Tp p){
    std::cout << "not smart pointer" << std::endl;
}

#endif //C___PRIMER_PROBLEMS_ENABLE_IF_H
