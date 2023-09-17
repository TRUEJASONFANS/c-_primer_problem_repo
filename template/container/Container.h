//
// Created by Administrator on 2023/9/10.
//

#ifndef C___PRIMER_PROBLEMS_CONTAINER_H
#define C___PRIMER_PROBLEMS_CONTAINER_H

#include <type_traits>
#include <cstdio>
#include <string>

template<typename  T>
struct has_type{
    using type = T;
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// IF_ /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template<bool condition, typename  THEN, typename ELSE>
struct if_;

template<typename  THEN, typename ELSE>
struct if_<true, THEN, ELSE>: has_type<THEN>{};

template<typename  THEN, typename ELSE>
struct if_<false, THEN, ELSE>: has_type<ELSE>{};

static_assert(std::is_same_v<typename if_<(10>5), int, bool>::type, int>);
static_assert(std::is_same_v<typename if_<(10<5), int, bool>::type, bool>);

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// TYPE LIST MANIPULATION ////////////////////////////
///////////////////////////////////////////////////////////////////////////////


template<typename...>
struct type_list{};


/////////////////////////////////// FRONT /////////////////////////////////////
template<typename LIST>
struct front;

template<template<typename ...> class LIST, typename T0, typename ...T1toN>
struct front<LIST<T0,T1toN...>>:has_type<T0>{};

template<typename LIST>
using front_t = typename front<LIST>::type;

static_assert(std::is_same_v<front_t<type_list<int,bool, float>>, int>);

///////////////////////////////// POP_FRONT ///////////////////////////////////

template<typename LIST>
struct pop_front {};

template<template<typename ...> class LIST, typename T0, typename  ...T1toN>
struct  pop_front<LIST<T0, T1toN...>> : has_type<type_list<T1toN...>>{};

template<typename LIST>
using pop_front_t = typename pop_front<LIST>::type;
static_assert(std::is_same_v<pop_front_t<type_list<int,bool, float>>, type_list<bool, float>>);


/////////////////////////////////// BACK //////////////////////////////////////
template<typename LIST>
struct back:has_type<typename back<pop_front_t<LIST>>::type>{};

template<template<typename...> class LIST, typename T0>
struct back<LIST<T0>> : has_type<T0>{};

template<typename LIST>
using back_t = typename back<LIST>::type;

static_assert(std::is_same_v<back_t<type_list<int, bool, float>>, float>);
static_assert(std::is_same_v<back_t<type_list<int, bool>>, bool>);

///////////////////////////////// PUSH_BACK ///////////////////////////////////
template<typename LIST, typename T>
struct push_back;

template<template<typename ...> class LIST, typename ... T0toN, typename T>
struct push_back<LIST<T0toN...>,T>:has_type<LIST<T0toN..., T>> {};


template<typename LIST, typename T>
using push_back_t = typename push_back<LIST, T>::type;

static_assert(std::is_same_v<push_back_t<type_list<>, int>, type_list<int>>);
static_assert(std::is_same_v<push_back_t<type_list<int, bool>, float>, type_list<int, bool, float>>);

////////////////////////////////// POP_BACK ///////////////////////////////////
template<typename LIST, typename RET_LIST = type_list<>>
struct pop_back;

template<template<typename ...> class LIST, typename T0,  typename RET_LIST>
struct pop_back<LIST<T0>, RET_LIST>: has_type<RET_LIST>{};


template<template<typename...> class LIST, typename T0, typename T1, typename... T2toN, typename RET_LIST>
struct pop_back<LIST<T0, T1, T2toN...>, RET_LIST> : pop_back<LIST<T1, T2toN...>, push_back_t<RET_LIST, T0>>{};

template<typename LIST>
using pop_back_t = typename pop_back<LIST>::type;

static_assert(std::is_same_v<pop_back_t<type_list<int>>, type_list<>>);
static_assert(std::is_same_v<pop_back_t<type_list<int, bool, float>>, type_list<int, bool>>);
static_assert(std::is_same_v<pop_back_t<type_list<int, bool>>, type_list<int>>);

//////////////////////////////////// AT ///////////////////////////////////////


template<typename LIST, size_t index>
struct at:has_type<typename at<pop_front_t<LIST>, index-1>::type>{};

template<typename LIST>
struct at<LIST, 0> : has_type<front_t<LIST>>{};

template<typename LIST, size_t index>
using at_t = typename at<LIST, index>::type;

static_assert(std::is_same_v<at_t<type_list<int, bool, float>, 1>, bool>);
static_assert(std::is_same_v<at_t<type_list<int, bool, float>, 2>, float>);

//////////////////////////////////// ANY //////////////////////////////////////

template<template<typename> class PREDICATE, typename LIST>
struct any;

template<template<typename> class PREDICATE, template<typename...> class LIST>
struct any<PREDICATE, LIST<>> : std::false_type{};

template<template<typename> class PREDICATE, typename LIST>
struct any : if_< // if predicate matches first type
                PREDICATE<front_t<LIST>>::value,
                // then
                std::true_type,
                // else
                typename any<PREDICATE, pop_front_t<LIST>>::type
                >::type{};

template<template<typename> class PREDICATE, typename LIST>
static constexpr bool any_v = any<PREDICATE, LIST>::value;
static_assert(any_v<std::is_integral, type_list<int, double, std::string>>);
static_assert(any_v<std::is_integral, type_list<std::string, double, int>>);
static_assert(!any_v<std::is_integral, type_list<std::string, double, float>>);

/////////////////////////////// CONTAINS_TYPE /////////////////////////////////

template<typename T>
struct same_as_pred{
    template<typename U>
    struct predicate : std::is_same<T, U>{};
};

template<typename SEARCH, typename LIST>
static constexpr bool contains_type_v = any<same_as_pred<SEARCH>::template predicate, LIST>::value;

static_assert(contains_type_v<int, type_list<int, bool, float>>);
static_assert(contains_type_v<float, type_list<int, bool, float>>);
static_assert(contains_type_v<double, type_list<int, bool, float>> == false);

///////////////////////////////////////////////////////////////////////////////


class Container {

};


#endif //C___PRIMER_PROBLEMS_CONTAINER_H