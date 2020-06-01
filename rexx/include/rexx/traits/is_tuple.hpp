#ifndef REXX_TRAITS_IS_TUPLE_HPP
#define REXX_TRAITS_IS_TUPLE_HPP

#include <tuple>

namespace rexx::traits {

    template<typename T>
    struct is_tuple {
        static constexpr bool value = false;
    };

    template<typename... Ts>
    struct is_tuple<std::tuple<Ts...>> {

    };

}

#endif
