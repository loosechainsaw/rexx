#ifndef REXX_TAKE_HPP
#define REXX_TAKE_HPP

#include <rexx/metafunctions/append.hpp>

namespace rexx::metafunctions {

    namespace detail {
        template<typename TTuple1, size_t N, typename TTuple2>
        struct take;

        template<typename T, typename... Ts, typename TTuple2>
        struct take<std::tuple<T, Ts...>, 0, TTuple2> {
            using type = TTuple2;
        };

        template<typename T, typename... Ts>
        struct take<std::tuple<>, 0, std::tuple<T, Ts...>> {
            using type = std::tuple<T, Ts...>;
        };

        template<size_t N, typename TTuple2>
        struct take<std::tuple<>, N, TTuple2> {
            using type = std::tuple<>;
        };

        template<typename T, typename... Ts, size_t N, typename TTuple2>
        struct take<std::tuple<T, Ts...>, N, TTuple2> {
            using type = typename detail::take<std::tuple<Ts...>, N - 1, typename append<TTuple2, T>::type>::type;
        };


    }

    template<typename TTuple, size_t N>
    struct take;

    template<typename... Ts, size_t N>
    struct take<std::tuple<Ts...>, N > {
        using type = typename detail::take<std::tuple<Ts...>, N, std::tuple<>>::type;
    };

}

#endif
