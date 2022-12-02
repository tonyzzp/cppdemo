#include "hb.h"
#include "xf.h"
#include "xf2.h"
#include "wh.h"
#include <iostream>

using namespace std;
int main()
{
    cout << hb::name << endl;
    cout << hb::xf::name << endl;
    cout << hb::wh::name << endl;
    cout << hb::xf::desc << endl;
    return 0;
}