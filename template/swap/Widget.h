//
// Created by zhxie on 2022/5/4.
//

#ifndef C___PRIMER_PROBLEMS_WIDGET_H
#define C___PRIMER_PROBLEMS_WIDGET_H

#include <vector>
#include <iostream>
namespace  WidgetStuff {
    template<typename T>
    class WidgetImpl {
    public:
        WidgetImpl(T t) {
            v.push_back(t);
        }
        void print() {
            for (auto i : v) {
                std::cout<< i;
            }
        }
    private:
        std::vector<T> v;
    };

    template<typename T>
    class Widget {
    public:
        Widget(T t) {
            pImpl = new WidgetImpl<T>(t);
        }

        void swap(Widget &other) {
            using std::swap;
            swap(pImpl, other.pImpl);
        }

        void print() {
            pImpl->print();
        }

    private:
        WidgetImpl<T> *pImpl;

    };

    template<typename  T>
    void swap(Widget<T>& a, Widget<T>& b) {
        a.swap(b);
    }
}

#endif //C___PRIMER_PROBLEMS_WIDGET_H
