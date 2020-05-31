#ifndef REXX_ANY_OF_HPP
#define REXX_ANY_OF_HPP

#include <tuple>

namespace rexx::metafunctions {

    template<typename TTuple, template<class> class P>
    struct any_of;

    template< template<class> class P>
    struct any_of<std::tuple<>, P> {
        static constexpr bool value = false;
    };

    template<typename T, template<class> class P>
    struct any_of<std::tuple<T>, P> {
        static constexpr bool value = P<T>::value;
    };

    template<typename T, typename... Ts, template<class> class P>
    struct any_of<std::tuple<T, Ts...>, P> {
        static constexpr bool value = P<T>::value || any_of<std::tuple<Ts...>, P>::value;
    };
}

#endif
