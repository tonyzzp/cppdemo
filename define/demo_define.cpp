#include <iostream>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MAKE_STR(str) #str

#define CONCAT(a, b) a##b

int main()
{
    {
        auto a = MAX(1 + 5, 3);
        cout << a << endl;
    }

    {
        auto s = MAKE_STR(hello world);
        cout << s << endl;
    }

    {
        int xy = 123;
        int v = CONCAT(x, y);
        cout << v << endl;
    }

    cout << "__FILE__ " << __FILE__ << endl;
    cout << "__LINE__ " << __LINE__ << endl;
    cout << "__DATE__ " << __DATE__ << endl;
    cout << "__TIME__" << __TIME__ << endl;
    cout << "__TIMESTAMP__ " << __TIMESTAMP__ << endl;
    cout << "__WIN32__ " << __WIN32__ << endl;
    cout << "__WIN32 " << __WIN32 << endl;
    cout << "__WIN64 " << __WIN64 << endl;
    cout << "__WIN64__ " << __WIN64__ << endl;

    return 0;
}