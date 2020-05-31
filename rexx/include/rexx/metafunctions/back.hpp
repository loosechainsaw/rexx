#ifndef REXX_BACK_HPP
#define REXX_BACK_HPP

#include <tuple>
#include <rexx/utility/null_type.hpp>

namespace rexx::metafunctions {

    template<typename TTuple>
    struct back;

    template<typename T>
    struct back<std::tuple<T>> {
        using type = T;
    };

    template<>
    struct back<std::tuple<>> {
        using type = rexx::utility::null_type;
    };

    template<typename T, typename... Ts>
    struct back<std::tuple<T, Ts...>> {
        using type = typename back<std::tuple<Ts...>>::type;
    };

}

#endif
