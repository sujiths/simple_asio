#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include <socket_base.hpp>
#include <log.hpp>
using namespace std;

namespace simple_asio
{
    template<typename T = int>
    class tcp_socket : public socket_base<T>
    {
        public:
            tcp_socket() 
            {
                debug_msg("tcp_socket object created");
            }

	    tcp_socket(tcp_socket&& rhs):socket_base<T>(std::move<T>(rhs))
	    {

	    }
	    tcp_socket& operator=(tcp_socket&& rhs)
	    {
		return static_cast<tcp_socket<T>&>(socket_base<T>::operator=(std::move(rhs)));
	    }
            ~tcp_socket()
            {
                // will call the base socket destructor
                debug_msg("tcp_socket object destroyed");
            }
            
	    void create_socket(void)
            {
                debug_msg("creating tcp socket");
                socket_base<T>::create_socket(AF_INET, SOCK_STREAM, 0);
            }
    };
}
#endif
