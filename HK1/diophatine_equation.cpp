#include <iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
void diophantine_equation(int a, int b, int c, int &x, int &y)
{
    // giai phuong trinh nghiem nguyen voi x,y thuoc [-50, 50] thoa ax + by = c
    // a = -5, b = 50, c = 15 => x = -3, y = 0

    int g = gcd(abs(a), abs(b), x, y);
    if (a == 0 && b == 0)
    {
        if (c == 0)
            cout << "Infinite solutions\n";
        else
            cout << "No solution!\n";
    }
    if (c % g)
        cout << "No solution!\n";
    x *= (c / g);
    y *= (c / g);
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
}
int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c;
    diophantine_equation(a, b, c, x, y);
    return 0;
}