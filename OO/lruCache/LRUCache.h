//
// Created by zhxie on 6/13/2022.
//

#ifndef C___PRIMER_PROBLEMS_LRUCACHE_H
#define C___PRIMER_PROBLEMS_LRUCACHE_H
#include <list>
#include <unordered_map>
#include <iostream>

using std::list;

class LRUCache {
    std::list<int> dq;
    std::unordered_map<int, list<int>::iterator> ma;
    int csize;
public:
    LRUCache(int);
    void refer(int);
    void display();

};
LRUCache::LRUCache(int n) {
    csize = n;
}

void LRUCache::refer(int key) {
    if (ma.find(key) == ma.end()) {
        if (dq.size() == csize) {
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    } else {
        dq.erase(ma[key]);
    }
    dq.push_front(key);
    ma[key] = dq.begin();
}

void LRUCache::display() {
    for(auto it = dq.begin(); it != dq.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout <<  std::endl;
}

#endif //C___PRIMER_PROBLEMS_MAIN_H
