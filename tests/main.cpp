#include <iostream>
#include <socket_base.h>

using namespace simple_asio;
using namespace std;

using namespace std;

int main()
{

    socket_base<> b;
    try
    {
        b.create_socket(AF_INET, SOCK_STREAM, 0);
    }
    catch (int e)
    {
        cout << "Exception occured : " << e << endl;
    }
    return 0;
}
