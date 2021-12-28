#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3};
    int s = 0;
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; ++i)
    {
        s += a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        s -= a[i];
        for (int j = 0; j < n; ++j)
        {
            if (a[j] == s)
            {
                cout << a[j];
                return 0;
            }
        }
    }
    return 0;
}