#include <iostream>
using namespace std;

#define MAX 250

struct PhanSo
{
    int TuSo;
    int MauSo;
};
void takeInput(PhanSo arr[], int n);
int gcd(int a, int b);
void findMin(PhanSo arr[], int n);
int main()
{
    PhanSo arr[250];
    int n;
    cout << "Nhap vao so luong phan so: ";
    cin >> n;
    takeInput(arr, n);
    findMin(arr, n);
    return 0;
}
void takeInput(PhanSo arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << "Nhap phan so thu " << i + 1 << endl;
        cout << "Nhap tu so: ";
        cin >> arr[i].TuSo;
        cout << "Nhap mau so: ";
        cin >> arr[i].MauSo;
        cout << "Phan so ban nhap la: " << arr[i].TuSo << " / " << arr[i].MauSo << endl;
        i++;
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void findMin(PhanSo arr[], int n)
{
    float min = float(arr[0].TuSo) / arr[0].MauSo;
    float tmp;
    int tuso, mauso;
    // tim min
    for (int i = 1; i < n; ++i)
    {
        tmp = float(arr[i].TuSo) / arr[i].MauSo;
        if (min > tmp)
        {
            min = tmp;
        }
    }
    // tim phan so
    for (int i = 0; i < n; ++i)
    {
        tuso = int(min * arr[i].MauSo);
        if (tuso == arr[i].TuSo)
        {
            mauso = arr[i].MauSo;
            tuso = arr[i].TuSo;
            break;
        }
    }
    int minimize = gcd(tuso, mauso);
    cout << "\nPhan so nho nhat la: " << tuso / minimize << " / " << mauso / minimize << endl;
}