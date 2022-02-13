//
// Created by zhxie on 2022/2/10.
//

#ifndef  SP_H
#define SP_H
#include <iostream>
using namespace  std;


template <typename  T>
class MSharePtr {
public:
    MSharePtr():p(nullptr), use(nullptr) {}
    explicit MSharePtr(T* pt): p(pt), use(new size_t(1)) {}
    MSharePtr(const MSharePtr &ms) : p(ms.p), use(ms.use) {
        if (use) ++*use;
    }
    MSharePtr& operator=(const MSharePtr&);
    ~MSharePtr();
    T& operator*() {return *p;};
    T& operator*() const  {
        return *p;
    }

private:
    T *p;
    size_t *use;
};

template <typename  T>
MSharePtr<T>::~MSharePtr(){
    if (use &&  --*use==0) {
        delete p;
        delete use;
    }
}
template <typename T>
MSharePtr<T>& MSharePtr<T>::operator=(const MSharePtr<T> &rhs){
    if (rhs.use) {
        ++*rhs.use;
    }
    if (use && --*use == 0) {
        delete p;
        delete use;
    }
    p = rhs.p;
    use  = rhs.use;
    return *this;
}

template <typename  T, class... Args>
MSharePtr<T> make_MSharePtr(Args &&... args) {
    return MSharePtr<T>(new T(std::forward<Args>(args)...));
}





#endif