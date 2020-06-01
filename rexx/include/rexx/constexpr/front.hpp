#ifndef REXX_CONSTEXPR_FRONT_HPP
#define REXX_CONSTEXPR_FRONT_HPP

#include <type_traits>

namespace rexx::cexpr {

    template<typename T>
    using front_result_type =
            typename std::conditional<std::is_lvalue_reference_v<T>,
                                      decltype(std::get<0>(std::declval<T>())),
                                      std::remove_reference_t<decltype(std::get<0>(std::declval<T>()))>>::type;

    template<typename T>
    static constexpr bool front_result_noexcept =
            std::is_lvalue_reference_v<T> ?
                 true :
                 std::is_nothrow_move_constructible_v<std::remove_reference_t<decltype(std::get<0>(std::declval<T>()))>>;

    template<typename T>
    constexpr auto front(T&& tuple) noexcept(front_result_noexcept<T>) -> front_result_type<T> {
        return std::get<0>(tuple);
    }

}

#endif
