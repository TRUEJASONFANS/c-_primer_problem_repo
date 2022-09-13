//
// Created by zhxie on 5/5/2022.
//

#ifndef C___PRIMER_PROBLEMS_SUBTEMPLATE_H
#define C___PRIMER_PROBLEMS_SUBTEMPLATE_H

template<class T>
class Base {
    T t;
};

template<class T>

class Sub : public Base<T> {
    T t2;
};


#endif //C___PRIMER_PROBLEMS_SUBTEMPLATE_H
