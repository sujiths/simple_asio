#include <iostream>
#include <tcp_socket.h>

using namespace simple_asio;
using namespace std;

int main()
{

    tcp_socket<> b;
    try
    {
        b.create_socket();
	cout<<"socket fd is "<<b.get_native_handle()<<endl;
    }
    catch (int e)
    {
        cout << "Exception occured : " << e << endl;
    }
    return 0;
}
