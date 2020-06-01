#ifndef REXX_CONSTEXPR_BACK_HPP
#define REXX_CONSTEXPR_BACK_HPP

#include <type_traits>
#include <tuple>

namespace rexx::cexpr {


    template<typename T>
    static constexpr int last_tuple_index = std::tuple_size_v<std::decay_t<T>> - 1;

    template<typename T>
    using back_result_type =
    typename std::conditional<std::is_lvalue_reference_v<T>,
            decltype(std::get<last_tuple_index<T>>(std::declval<T>())),
            std::remove_reference_t<decltype(std::get<last_tuple_index<T>>(std::declval<T>()))>>::type;

    template<typename T>
    static constexpr bool back_result_noexcept =
            std::is_lvalue_reference_v<T> ?
            true :
            std::is_nothrow_move_constructible_v<std::remove_reference_t<decltype(std::get<last_tuple_index<T>>(std::declval<T>()))>>;

    template<typename T>
    constexpr auto back(T &&tuple) noexcept(back_result_noexcept<T>) -> back_result_type<T> {
        return std::get<last_tuple_index<T>>(tuple);
    }


}

#endif
