#ifndef REXX_CONCAT_HPP
#define REXX_CONCAT_HPP

#include <tuple>

namespace rexx::metafunctions {
    
    template<typename TTuple1, typename TTuple2>
    struct concat;
    
    template<typename... Ts, typename... Us>
    struct concat<std::tuple<Ts...>, std::tuple<Us...>> {
        using type = std::tuple<Ts..., Us...>; 
    };
    
}

#endif
