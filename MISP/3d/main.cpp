#include "3d.h"
#include <iostream>
using namespace std;

int main()
{
    point3d p1;
    point3d p2(2, 2, 2);
    p1 = p2;
    cout << p1.getx() << p1.gety() << p1.getz() << p2.getx() << p2.gety() << p2.getz() << '\n';
    getRoPhi(p1);
    cout << p1.getx() << '\n' << p1.gety() << '\n' << p1.getz();
    return 0;
}