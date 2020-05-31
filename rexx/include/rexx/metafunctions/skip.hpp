#ifndef REXX_SKIP_HPP
#define REXX_SKIP_HPP

#include <tuple>

namespace rexx::metafunctions {

    namespace detail {

        template<typename TTuple, size_t N>
        struct skip;

        template<typename T, typename... Ts>
        struct skip<std::tuple<T, Ts...>, 0 > {
            using type = std::tuple<T, Ts...>;
        };

        template<typename T, typename... Ts, size_t N>
        struct skip<std::tuple<T, Ts...>, N> {
            using type = typename detail::skip<std::tuple<Ts...>, N - 1>::type;
        };

        template<size_t N>
        struct skip<std::tuple<>, N> {
            using type = std::tuple<>;
        };
    }

    template<typename TTuple, size_t N>
    struct skip;

    template<typename... Ts, size_t N>
    struct skip<std::tuple<Ts...>, N> {
        using type = typename detail::skip<std::tuple<Ts...>, N>::type;
    };


}

#endif
