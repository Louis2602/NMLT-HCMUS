#include <iostream>
using namespace std;

int fib(int n)
{
    if (n < 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    int fibNum;
    cout << "Nhap n: ";
    cin >> n;
    fibNum = fib(n);
    cout << "So fibonacci thu " << n << " la: " << fibNum;
    return 0;
}