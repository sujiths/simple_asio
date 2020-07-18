#ifndef FILE_BASE_H_
#define FILE_BASE_H_

#include <iostream>

namespace simple_asio
{
    template <typename T = int>
    class file_base
    {
        public:
        file_base() {}
        ~file_base() {}

        virtual T get_native_handle() = 0;
        virtual bool is_valid_handle(T handle) = 0;
    };
}

#endif
