#ifndef REXX_CONSTEXPR_ALL_OF_HPP
#define REXX_CONSTEXPR_ALL_OF_HPP

#include <type_traits>
#include <tuple>

namespace rexx::cexpr {

    namespace detail {
        template<typename... Ts, typename P, size_t... Is>
        constexpr bool all_of(std::tuple<Ts...> const& tuple, P&& predicate, std::index_sequence<Ts...> _ ) {
            return std::get<Is>(tuple)
        }
    }

    template<typename... Ts, typename P>
    constexpr bool all_of(std::tuple<Ts...> const& tuple, P&& predicate ) {
    }
}

#endif
