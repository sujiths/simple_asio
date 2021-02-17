#ifndef IO_BASE_H_
#define IO_BASE_H_

#include <iostream>

namespace simple_asio
{
    template <typename T = int>
    class io_base
    {
        public:
        io_base() {}
        ~io_base() {}

        virtual T get_native_handle() const = 0;
        virtual bool is_valid_handle(T handle) const = 0;
    };
}

#endif
