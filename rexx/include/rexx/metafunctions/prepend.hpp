#ifndef REXX_PREPEND_HPP
#define REXX_PREPEND_HPP

#include <tuple>

namespace rexx::metafunctions {

    template<typename TTuple, typename A>
    struct prepend;

    template<typename... Ts, typename A>
    struct prepend<std::tuple<Ts...>, A> {
        using type = std::tuple<A, Ts...>;
    };

}

#endif
