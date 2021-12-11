#include <iostream>
using namespace std;

#define MAX 256

int main()
{
    char a[MAX][MAX];
    int m, n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 0; i < m; ++i)
    {
        cout << "Nhap chuoi " << i + 1 << ": ";
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    // yeu cau 1
    cout << "Yeu cau 1 - Bang ky tu duoc tao: " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    // yeu cau 2
    cout << "Yeu cau 2 - Chuoi duoc tao theo hinh zigzag: " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i % 2 == 0)
                cout << a[j][i];
            else
                cout << a[m - j - 1][i];
        }
    }

    return 0;
}