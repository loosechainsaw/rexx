#ifndef REXX_ZIP_HPP
#define REXX_ZIP_HPP

#include <tuple>

namespace rexx::metafunctions {

    template<typename TTuple1, typename TTuple2,
    template<class, class> class F>
    struct zip;

    template<typename... Ts, typename... Us,
            template<class, class> class F>
    struct zip<std::tuple<Ts...>, std::tuple<Us...>, F> {
        using type = std::tuple<typename F<Ts, Us>::type...>;
    };

}

#endif
