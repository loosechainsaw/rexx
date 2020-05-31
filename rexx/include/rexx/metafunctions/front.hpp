#ifndef REXX_FRONT_HPP
#define REXX_FRONT_HPP

#include <tuple>

namespace rexx::metafunctions {

    template<typename TTuple>
    struct front;

    template<typename T, typename... Ts>
    struct front<std::tuple<T, Ts...>> {
        using type = T;
    };
}

#endif
