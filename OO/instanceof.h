//
// Created by zhxie on 4/20/2022.
//

#ifndef C___PRIMER_PROBLEMS_INSTANCEOF_H
#define C___PRIMER_PROBLEMS_INSTANCEOF_H

namespace OO {
    template<typename Base, typename T>
    inline bool instanceof(const T *ptr) {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
}

namespace OO {
    namespace TEST {
        class GaugeBase {
            protected:
            virtual ~GaugeBase() = default;
        };

        class Gauge: public GaugeBase {
        };

        class GaugeGroup: public GaugeBase {

        };
    }
}

#endif //C___PRIMER_PROBLEMS_INSTANCEOF_H
