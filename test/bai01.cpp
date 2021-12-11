#include <iostream>
#include <cstring>

using namespace std;

#define MAX 256

void formatNumberWithCommas(char a[]);

int main()
{
    char a[MAX];
    char x;
    int check, mostAppearChar, pos;
    formatNumberWithCommas(a);
    return 0;
}
void formatNumberWithCommas(char a[])
{
    cout << "Nhap chuoi so: ";
    cin >> a;
    int n = strlen(a);
    for (int i = n - 3; i > 0; i -= 3)
    {
        for (int j = n; j > i; j--)
        {
            a[j] = a[j - 1];
        }
        a[i] = ',';
        a[++n] = '\0';
    }
    cout << "Chuoi sau khi xu ly: " << a << endl;
}
