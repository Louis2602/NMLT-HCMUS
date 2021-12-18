#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float n, k;
    cout << "Nhap mot so nguyen n > 0: ";
    cin >> n;
    while (n < 0 || n != int(n))
    {
        cout << "Nhap sai, vui long nhap lai!" << endl;
        cout << "Nhap mot so nguyen n > 0: ";
        cin >> n;
    }
    k = sqrt((n - 1) / 2);
    if (k == int(k))
        cout << n << " la so gia nguyen to voi k = " << k << endl;
    else
        cout << n << " khong la so gia nguyen to" << endl;

    return 0;
}
