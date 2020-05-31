#ifndef REXX_BACK_HPP
#define REXX_BACK_HPP

#include <tuple>

namespace rexx::metafunctions {

    template<typename TTuple>
    struct back;

    template<typename T>
    struct back<std::tuple<T>> {
        using type = T;
    };

    template<typename T, typename... Ts>
    struct back<std::tuple<T, Ts...>> {
        using type = typename back<std::tuple<Ts...>>::type;
    };

}

#endif
