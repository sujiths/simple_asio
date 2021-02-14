#include <iostream>
#include <tcp_socket.h>
#include <udp_socket.h>

using namespace simple_asio;
using namespace std;

int main()
{
    tcp_socket<> sock_tcp;
    udp_socket<> sock_udp;
    try
    {
        sock_tcp.create_socket();
        sock_udp.create_socket();
	cout<<"tcp socket fd is "<<sock_tcp.get_native_handle()<<endl;
	cout<<"udp socket fd is "<<sock_udp.get_native_handle()<<endl;
    }
    catch (int e)
    {
        cout << "Exception occured : " << e << endl;
    }
    return 0;
}
