//
// Created by zhxie on 3/21/2022.
//

#ifndef C___PRIMER_PROBLEMS_MOVIE_H
#define C___PRIMER_PROBLEMS_MOVIE_H
#include "UniquePtrTest.h"

class Movie {
public:
    std::unique_ptr<Tony> addTony()
    {
        std::unique_ptr<Tony> tony( new Tony);
        attachActor(std::move(tony));
        cout << "addTony back" << endl;
        cout << tony->GetFullName();
        cout << "addTony leave" << endl;
        return tony;
    }
    void attachActor(std::unique_ptr<Tony>&& u) {
        // take the unique_ptr by r-value reference,
        // and then don't move from it, leaving the
        // original intact
        cout << "attachActor enter" << endl;
        cout << u->GetFullName();
        cout << "attachActor leave" << endl;
    }
};

#endif //C___PRIMER_PROBLEMS_MOVIE_H
