#ifndef SOCKET_BASE_H_
#define SOCKET_BASE_H_

#include <io_base.hpp>
#include <sys/socket.h>
#include <unistd.h>
#include <log.hpp>

using namespace std;

namespace simple_asio 
{
    template <typename T = int>
    class socket_base : public io_base<T>
    {
        private:
            T socket_handle;
        public:
	    socket_base(socket_base&& rhs)
	    {
	        debug_msg("socket_base object is being moved via move constructor");
		*this = std::move(rhs);
	    }
            socket_base() { debug_msg("socket_base object created"); };
            ~socket_base() 
            {

                if(is_valid_handle(socket_handle))
                    close(socket_handle);
                debug_msg("socket_base object destroyed");
            }

	    socket_base& operator=(socket_base&& rhs)
	    {
	        debug_msg("socket_base object is being moved via move operator");
		socket_handle = dup(rhs.socket_handle);
		close(rhs.socket_handle);
                rhs.socket_handle = -1;
		return *this;
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
