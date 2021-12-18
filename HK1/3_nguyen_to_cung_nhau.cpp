#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    if (gcd(a, b) == 1)
        cout << "Nguyen to cung nhau";
    else
        cout << "Khong nguyen to cung nhau";
    return 0;
}