//
// Created by 中威谢 on 2022/2/20.
//

#ifndef C___PRIMER_PROBLEMS_REMOVE_REFERENCE_H
#define C___PRIMER_PROBLEMS_REMOVE_REFERENCE_H
template <class T> struct remove_reference {
    typedef  T type;
};
template <class T> struct remove_reference<T&> {
    typedef  T type;
};
template <class T> struct remove_reference<T&&> {
    typedef  T type;
};

#endif //C___PRIMER_PROBLEMS_REMOVE_REFERENCE_H
