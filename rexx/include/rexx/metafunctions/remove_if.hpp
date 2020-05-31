#ifndef REXX_REMOVE_IF_H
#define REXX_REMOVE_IF_H

#include <rexx/metafunctions/prepend.hpp>

namespace rexx::metafunctions {

    namespace detail {

        template<typename TTuple, template<class> class P>
        struct remove_if;

        template<template<class> class P>
        struct remove_if<std::tuple<>, P> {
            using type = std::tuple<>;
        };

        template<typename T, typename... Ts, template<class> class P>
        struct remove_if<std::tuple<T, Ts...>, P> {
            using type = typename std::conditional<P<T>::value,
                                                   typename detail::remove_if<std::tuple<Ts...>, P>::type,
                                                   typename prepend<typename detail::remove_if<std::tuple<Ts...>, P>::type, T>::type>::type;
        };
    }

    template<typename TTuple, template<class> class P>
    struct remove_if;

    template<typename... Ts, template<class> class P>
    struct remove_if<std::tuple<Ts...>, P> {
        using type = typename detail::remove_if<std::tuple<Ts...>, P>::type;
    };


}


#endif
