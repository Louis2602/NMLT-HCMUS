#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int tmp = 10;
    int cnt = 1;
    while (n / tmp != 0)
    {
        tmp *= 10;
        cnt++;
    }
    cout << "So luong chu so cua n la: " << cnt;
    return 0;
}