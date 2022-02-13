//
// Created by zhxie on 2022/2/13.
//

#ifndef C___PRIMER_PROBLEMS_DEBUG_H
#define C___PRIMER_PROBLEMS_DEBUG_H
#include <iostream>
#include <sstream>

template <typename  T> std::string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename  T> std::string debug_rep(T *t) {
    ostringstream ret;
    ret << "pointer:" << t;
    if (t)
        ret << " "<< debug_rep(*t);
    else
        ret << "null pointer";
    return ret.str();

}
#endif //C___PRIMER_PROBLEMS_DEBUG_H
