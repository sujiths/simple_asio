#include <iostream>
#include <tcp_socket.hpp>
#include <udp_socket.hpp>

using namespace simple_asio;
using namespace std;

int main()
{
    tcp_socket<> sock_tcp;
    udp_socket<> sock_udp;
    tcp_socket<> move_tcp;
    try
    {
        sock_tcp.create_socket();
        sock_udp.create_socket();
	cout<<"tcp socket fd is "<<sock_tcp.get_native_handle()<<endl;
	cout<<"udp socket fd is "<<sock_udp.get_native_handle()<<endl;

	move_tcp = std::move(sock_tcp);
	cout<<"move tcp socket fd is "<<move_tcp.get_native_handle()<<endl;
	cout<<"tcp socket fd is "<<sock_tcp.get_native_handle()<<endl;
    }
    catch (int e)
    {
        cout << "Exception occured : " << e << endl;
    }
    return 0;
}
