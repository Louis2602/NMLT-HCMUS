#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 2; j <= 5; ++j)
        {
            cout << j << " x " << i << " = " << i * j;
            if (i * j >= 10)
                cout << setw(8);
            else
                cout << setw(9);
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 6; j <= 9; ++j)
        {
            cout << j << " x " << i << " = " << i * j;
            if (i * j >= 10)
                cout << setw(8);
            else
                cout << setw(9);
        }
        cout << '\n';
    }
    return 0;
}