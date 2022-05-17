//
// Created by zhxie on 5/17/2022.
//

#ifndef C___PRIMER_PROBLEMS_IS_SUBCLASS_H
#define C___PRIMER_PROBLEMS_IS_SUBCLASS_H

#define is_subclass(x, y) ( (bool) CheckInheritance<x,y>::result )

template<typename  Sub,typename Base>
class CheckInheritance {

    typedef char Convertable;
    class NotConvertable {char isConvert[64];};

    static Convertable test(const Base&);
    static NotConvertable test(...);
    static Sub makeTesting();

public:

    enum {
        result = sizeof (test(makeTesting())) == sizeof(Convertable)
    };
};


#endif //C___PRIMER_PROBLEMS_IS_SUBCLASS_H
