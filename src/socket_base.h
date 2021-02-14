#ifndef SOCKET_BASE_H_
#define SOCKET_BASE_H_

#include <file_base.h>
#include <sys/socket.h>
#include <unistd.h>
#include <log.h>

using namespace std;

namespace simple_asio 
{
    template <typename T = int>
    class socket_base : public file_base<T>
    {
        private:
            T socket_handle;
        public:
            socket_base() { debug_msg("socket_base object created"); };
            ~socket_base() 
            {

                if(is_valid_handle(socket_handle))
                    close(socket_handle);
                debug_msg("socket_base object destroyed");
            }

            void create_socket(int domain, int type, int protocol)
            {
                socket_handle = socket(domain, type, protocol);
                if(!is_valid_handle(socket_handle))
                    throw 0;
            }

            virtual T get_native_handle() const
            {
                return socket_handle;
            }
            virtual bool is_valid_handle(T handle) const
            {
                return ((handle < 0)?false: true);
            }
    };
}
#endif
