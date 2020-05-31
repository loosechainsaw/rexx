#ifndef REXX_TRANSFORM_HPP
#define REXX_TRANSFORM_HPP

#include <tuple>

namespace rexx::metafunctions {

    template<typename TTuple, template<class> class F>
    struct transform;

    template<typename... Ts, template<class> class F>
    struct transform<std::tuple<Ts...>, F> {
        using type = std::tuple<typename F<Ts>::type...>;
    };

}

#endif
