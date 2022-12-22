//
// Created by zhxie on 10/24/2022.
//

#include <string>
#include <iostream>
#include <typeinfo>
#include <tuple>
#include <array>

using Types = std::tuple<float, int, double, std::string, char>;

template<std::size_t N>
using AttributeType = typename std::tuple_element<N, Types>::type;

constexpr bool strings_equal(const char* a, const char* b) {
    return *a == *b && (*a == '\0' || strings_equal(a + 1, b + 1));
}

constexpr std::size_t getTypeIndex(const char* name)
{
    return strings_equal(name, "float") ? 0:
           strings_equal(name, "int") ? 1:
           strings_equal(name, "double") ? 2:
           strings_equal(name, "std::string") ? 3:
           strings_equal(name, "char") ? 4:
           5; // compilation error
}


constexpr const char* FLOAT_TYPE = "float";
constexpr const char* INT_TYPE = "int";
constexpr const char* DOUBLE_TYPE = "double";
constexpr const char* STRING_TYPE = "std::string";
constexpr const char* CHAR_TYPE = "char";

constexpr std::array<std::pair<const char*, const char*>, 6> attribute2type = {{
                                                                                       {"gender", CHAR_TYPE},
                                                                                       {"age", INT_TYPE},
                                                                                       {"height", FLOAT_TYPE},
                                                                                       {"IQ", INT_TYPE},
                                                                                       {"name", STRING_TYPE},
                                                                                       {"weight", DOUBLE_TYPE},
                                                                               }};


template <typename T>
void print(const char* attribute) {
    std::cout << "attribute = " << attribute << ",type=" <<  typeid(T).name() << std::endl;
}


constexpr size_t LAST_INDEX = attribute2type.size() - 1;

template <size_t T=LAST_INDEX>
struct PrintHelper {

public:
    PrintHelper() {
        doPrint<T>();
    }
private:

    template <size_t N>
    void doPrint() {
        constexpr auto index = getTypeIndex(std::get<N>(attribute2type).second);
        using attribute_type = AttributeType<index>;

        print<attribute_type>(std::get<N>(attribute2type).first);

        doPrint<N-1>();

    }

};

template <>
template <>
void PrintHelper<LAST_INDEX>::doPrint<0>() {

    constexpr auto index = getTypeIndex(std::get<0>(attribute2type).second);
    using attribute_type = AttributeType<index>;

    print<attribute_type>(std::get<0>(attribute2type).first);
}


int main() {

    PrintHelper<>();

    return 0;
}