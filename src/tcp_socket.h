#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include <socket_base.h>
#include <log.h>
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
            ~tcp_socket()
            {
                debug_msg("tcp_socket object destroyed");
                // will call the base socket destructor
            }
            
	    void create_socket(void)
            {
		    socket_base<T>::create_socket(AF_INET, SOCK_STREAM, 0);
            }
    };
}
#endif
