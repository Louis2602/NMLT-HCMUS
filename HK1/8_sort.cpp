#include <iostream>
using namespace std;

#define MAX 100

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void tangdan(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void giamdan(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]);
}

void sortChanLe(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j] && a[i] % 2 == 0 && a[j] % 2 == 0)
                swap(a[i], a[j]);
            else if (a[i] < a[j] && a[i] % 2 != 0 && a[j] % 2 != 0)
                swap(a[i], a[j]);
}
void output(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[MAX];
    int n;
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    // cout << "Mang tang dan: ";
    // tangdan(a, n);
    // output(a, n);
    // cout << endl;
    // cout << "Mang giam dan: ";
    // giamdan(a, n);
    // output(a, n);
    // cout << endl;
    cout << "Mang chan tang le giam: ";
    sortChanLe(a, n);
    output(a, n);
    return 0;
}