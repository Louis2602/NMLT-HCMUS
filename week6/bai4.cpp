#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 100

struct SinhVien
{
    int ID;
    string name;
    float Toan, Ly, Hoa;
    float diemTB;
};
void nhapThongTinSV(SinhVien &sv, int id)
{
    fflush(stdin);
    cout << "\nNhap ID: ";
    cin >> sv.ID;
    cout << "Nhap ten: ";
    cin >> sv.name;
    cout << "Nhap diem Toan: ";
    cin >> sv.Toan;
    cout << "Nhap diem Ly: ";
    cin >> sv.Ly;
    cout << "Nhap diem Hoa: ";
    cin >> sv.Hoa;
    sv.diemTB = (sv.Toan + sv.Ly + sv.Hoa) / 3;
}
void nhapSV(SinhVien a[], int id, int n)
{
    cout << "\nNhap sinh vien thu " << n + 1;
    nhapThongTinSV(a[n], id);
}
void xuatDanhSachSV(SinhVien a[], int n)
{
    SinhVien tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].diemTB > a[j].diemTB)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    cout << "\nID" << setw(14) << "Ten" << setw(19) << "Diem Toan"
         << setw(15) << "Diem Ly" << setw(15) << "Diem Hoa" << setw(15) << "Diem TB\n";
    cout << a[n - 1].ID;
    cout << setw(13) << a[n - 1].name;
    cout << setw(15) << a[n - 1].Toan;
    cout << setw(15) << a[n - 1].Ly;
    cout << setw(17) << a[n - 1].Hoa;
    cout << setw(17) << a[n - 1].diemTB;
    cout << endl;
    cout << a[0].ID;
    cout << setw(13) << a[0].name;
    cout << setw(15) << a[0].Toan;
    cout << setw(15) << a[0].Ly;
    cout << setw(17) << a[0].Hoa;
    cout << setw(17) << a[0].diemTB;
}
int main()
{
    SinhVien a[MAX];
    int key;
    int soLuongSV = 0;
    int idCount = 0;

    while (true)
    {
        cout << "\n\t\tCHUONG TRINH QUAN LY SINH VIEN\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Xuat ra thong tin sinh vien theo diem TB.     **\n";
        cout << "**  2. Nhap thong tin sinh vien.                     **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key)
        {
        case 0:
            cout << "Ban da chon thoat chuong trinh!";
            return 0;
            break;
        case 1:
            cout << "\nHien thi danh sach sinh vien co diem TB cao va thap nhat lop.";
            xuatDanhSachSV(a, soLuongSV);
            break;
        case 2:
            cout << "\n2. Nhap thong tin sinh vien.";
            nhapSV(a, idCount, soLuongSV);
            cout << "\nNhap them sinh vien thanh cong!";
            soLuongSV++;
            break;
        }
    }
    return 0;
}
