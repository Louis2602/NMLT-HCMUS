#include <iostream>
using namespace std;

#define MAX 100

void set2dArray(int a[][MAX], int m, int n);
void print2dArray(int a[][MAX], int m, int n);
int sumDiagonal(int a[][MAX], int m, int n);
int sumDiagonalPhu(int a[][MAX], int m, int n);
void deleteItems(int a[][MAX], int &m, int &n);

int main()
{
    int a[MAX][MAX];
    int m, n, sum, sumPhu;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    set2dArray(a, m, n);
    print2dArray(a, m, n);
    sum = sumDiagonal(a, m, n);
    cout << "Tong cheo = " << sum << endl;
    sumPhu = sumDiagonalPhu(a, m, n);
    cout << "Tong cheo phu = " << sumPhu << endl;
    // deleteItems(a, m, n);
    return 0;
}

void set2dArray(int a[][MAX], int m, int n)
{
    cout << "Input 2D Array" << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
}
void print2dArray(int a[][MAX], int m, int n)
{
    cout << "Output 2D Array" << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int sumDiagonal(int a[][MAX], int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                sum += a[i][j];
        }
    }
    return sum;
}

int sumDiagonalPhu(int a[][MAX], int m, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i][n - 1 - i];
    return sum;
}
void deleteItems(int a[][MAX], int &m, int &n)
{
    int x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    int dong, cot;
    bool found = false;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == x)
            {
                dong = i;
                cot = j;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    // xoa dong
    for (int i = dong; i < m - 1; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = a[i + 1][j];
    m--;
    // xoa cot
    for (int i = 0; i < m; i++)
        for (int j = cot; j < n - 1; j++)
            a[i][j] = a[i][j + 1];
    n--;
    print2dArray(a, m, n);
}