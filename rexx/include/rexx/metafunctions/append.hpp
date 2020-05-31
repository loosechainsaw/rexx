#ifndef REXX_APPEND_HPP
#define REXX_APPEND_HPP

#include <tuple>

namespace rexx::metafunctions {

    template<typename TTuple, typename A>
    struct append;

    template<typename... Ts, typename A>
    struct append<std::tuple<Ts...>, A> {
        using type = std::tuple<Ts..., A>;
    };

}

#endif
