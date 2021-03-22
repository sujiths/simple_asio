#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include <socket_base.hpp>
#include <log.hpp>
using namespace std;

namespace simple_asio
{
    template<typename T = int>
    class udp_socket : public socket_base<T>
    {
        public:
            udp_socket() 
            {
                debug_msg("udp_socket object created");
            }
            virtual ~udp_socket()
            {
                // will call the base socket destructor
                debug_msg("udp_socket object destroyed");
            }
            
	    void create_socket(void)
            {
                debug_msg("creating tcp socket");
                socket_base<T>::create_socket(AF_INET, SOCK_DGRAM, 0);
            }
    };
}
#endif
