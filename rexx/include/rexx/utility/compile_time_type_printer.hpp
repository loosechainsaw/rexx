#ifndef REXX_COMPILE_TIME_TYPE_PRINTER_HPP
#define REXX_COMPILE_TIME_TYPE_PRINTER_HPP

namespace rexx::utility {
    template<typename T>
    struct compile_time_type_printer;
}

#define PRINT_TYPE(t) \
{ \
    rexx::utility::compile_time_type_printer<t> _; \
}
#endif
