#ifndef REXX_FILL_N_HPP
#define REXX_FILL_N_HPP

#include <rexx/metafunctions/append.hpp>

namespace rexx::metafunctions {

    namespace detail {

        template<typename T, size_t N, typename TResult>
        struct fill_n {
            using type = typename detail::fill_n<T, N - 1, typename append<TResult, T>::type>::type;
        };

        template<typename T, typename TResult>
        struct fill_n<T, 0, TResult> {
            using type = TResult;
        };
    }

    template<typename T, size_t N>
    struct fill_n {
        using type = typename detail::fill_n<T, N, std::tuple<>>::type;
    };

}

#endif

