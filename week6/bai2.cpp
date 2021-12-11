#include <iostream>
using namespace std;

struct PhanSo
{
    int TuSo;
    int MauSo;
};

int main()
{
    PhanSo a;
    PhanSo b;
    cout << "Nhap phan so thu 1" << endl;
    cout << "Nhap tu so: ";
    cin >> a.TuSo;
    cout << "Nhap mau so: ";
    cin >> a.MauSo;

    cout << "Nhap phan so thu 2" << endl;
    cout << "Nhap tu so: ";
    cin >> b.TuSo;
    cout << "Nhap mau so: ";
    cin >> b.MauSo;

    cout << "Phan so thu 1 la: " << a.TuSo << "/" << a.MauSo << endl;
    cout << "Phan so thu 2 la: " << b.TuSo << "/" << b.MauSo << endl;

    float sum;
    sum = float(a.TuSo * b.MauSo + b.TuSo * a.MauSo) / (a.MauSo * b.MauSo);
    cout << "Tong cua 2 phan so la: " << sum << endl;

    return 0;
}