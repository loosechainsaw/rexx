#ifndef REXX_NONE_OF_HPP
#define REXX_NONE_OF_HPP

#include <tuple>

namespace rexx::metafunctions {

    template<typename TTuple, template<class> class P>
    struct none_of;

    template< template<class> class P>
    struct none_of<std::tuple<>, P> {
        static constexpr bool value = true;
    };

    template<typename T, typename... Ts, template<class> class P>
    struct none_of<std::tuple<T, Ts...>, P> {
        static constexpr bool value = !P<T>::value && !none_of<std::tuple<Ts...>, P>::value;
    };
}

#endif
