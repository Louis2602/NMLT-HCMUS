#include <iostream>
#include <cstring>

using namespace std;

#define MAX 256

void reverseCharArray(char a[MAX]);
int checkSymmetricArray(char a[MAX]);
int findMostFrequentChar(char a[MAX], char &chr);
void insertCharAtPosition(char a[], char chr, int pos);
void formatNumberWithCommas(char a[]);

int main()
{
    char a[MAX];
    char x;
    int check, mostAppearChar, pos;
    reverseCharArray(a);
    check = checkSymmetricArray(a);
    if (check)
        cout << "Chuoi ban nhap doi xung" << endl;
    else
        cout << "Chuoi ban nhap khong doi xung" << endl;
    mostAppearChar = findMostFrequentChar(a, x);
    cout << "Ki tu " << char(x) << " co so lan xuat hien nhieu nhat la: " << mostAppearChar << " lan" << endl;
    insertCharAtPosition(a, x, pos);
    formatNumberWithCommas(a);
    return 0;
}

void reverseCharArray(char a[MAX])
{
    cout << "Nhap chuoi: ";
    cin >> a;
    int n = strlen(a);
    for (int i = 0; i < n / 2; ++i)
    {
        int tmp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = tmp;
    }
    cout << "Chuoi sau khi dao nguoc la: " << a << endl;
}
// kiem tra tinh doi xung
int checkSymmetricArray(char a[MAX])
{
    cout << "Nhap chuoi: ";
    cin >> a;
    int n = strlen(a);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else
            return 0;
    }
    return 1;
}

int findMostFrequentChar(char a[MAX], char &chr)
{
    int cnt[MAX];
    int n = strlen(a);
    for (int i = 0; i < MAX; ++i)
        cnt[i] = 0;
    for (int i = 0; i < n; ++i)
        cnt[a[i]]++;
    int max = cnt[0];
    for (int i = 1; i < MAX; ++i)
    {
        if (max < cnt[i])
        {
            max = cnt[i];
            chr = i;
        }
    }
    return max;
}
void insertCharAtPosition(char a[], char chr, int pos)
{
    cout << "Nhap ki tu muon chen: ";
    cin >> chr;
    cout << "Nhap vi tri can chen: ";
    cin >> pos;
    int n = strlen(a);
    while (pos > n)
    {
        cout << "ERROR! OUT OF RANGE" << endl;
        cout << "Nhap ki tu muon chen: ";
        cin >> chr;
        cout << "Nhap vi tri can chen: ";
        cin >> pos;
    }
    for (int i = n; i > 0; --i)
    {
        a[i] = a[i - 1];
        if (i == pos)
        {
            a[i] = chr;
            break;
        }
    }
    a[++n] = '\0';
    cout << "Chuoi sau khi chen: " << a << endl;
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
