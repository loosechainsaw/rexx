#ifndef REXX_REMOVE_HPP
#define REXX_REMOVE_HPP

#include <rexx/metafunctions/prepend.hpp>

namespace rexx::metafunctions {

    template<typename TTuple, typename R>
    struct remove;

    template<typename R>
    struct remove<std::tuple<>, R> {
        using type = std::tuple<>;
    };

    template<typename T, typename... Ts, typename R>
    struct remove<std::tuple<T, Ts...>, R> {
        using type = typename prepend<typename remove<std::tuple<Ts...>, R>::type, T>::type;
    };

    template<typename T, typename... Ts>
    struct remove<std::tuple<T, Ts...>, T> {
        using type = typename remove<std::tuple<Ts...>, T>::type;
    };
}

#endif
