#ifndef REXX_FRONT_HPP
#define REXX_FRONT_HPP

#include <tuple>
#include <rexx/utility/null_type.hpp>

namespace rexx::metafunctions {

    template<typename TTuple>
    struct front;

    template<>
    struct front<std::tuple<>> {
        using type = rexx::utility::null_type;
    };

    template<typename T, typename... Ts>
    struct front<std::tuple<T, Ts...>> {
        using type = T;
    };
}

#endif
