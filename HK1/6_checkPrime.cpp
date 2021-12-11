#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            cout << "Ko phai SNT";
            return 0;
        }
    }
    cout << "La SNT";
    return 0;
}