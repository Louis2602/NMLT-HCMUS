#include <iostream>
using namespace std;

struct SinhVien
{
    string hoten;
    int mssv;
    float diemTB;
};
// nhap thong tin 1 sv
void nhapThongTinSinhVien(SinhVien &sv)
{
    cout << "\nNhap MSSV: ";
    cin >> sv.mssv;
    rewind(stdin);
    cout << "\nNhap ho ten sinh vien: ";
    getline(cin, sv.hoten);
    cout << "\nNhap diem TB: ";
    cin >> sv.diemTB;
}

// xuat thong tin 1 sv
void xuatThongTinSinhVien(SinhVien sv)
{
    cout << "\nMSSV: " << sv.mssv;
    cout << "\nHo ten sinh vien: " << sv.hoten;
    cout << "\nDiem TB: " << sv.diemTB;
}

// nhap danh sach sv
void nhapDanhSachSinhVien(SinhVien arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "\n\n\t\tNHAP THONG TIN SINH VIEN THU " << i + 1;
        nhapThongTinSinhVien(arr[i]);
    }
}

// xuat danh sach sv
void xuatDanhSachSinhVien(SinhVien arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << i + 1;
        xuatThongTinSinhVien(arr[i]);
    }
}
void timKiemSVTheoDiem(SinhVien arr[], int n, float diemTB)
{
    int dem = 1;
    int found = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].diemTB == diemTB)
        {
            found = 1;
            cout << "\n\n\t\t THONG TIN SINH VIEN " << dem++;
            xuatThongTinSinhVien(arr[i]);
        }
    }
    if (found == 0)
        cout << "\nKhong tim thay sinh vien co diem tuong ung!!";
}
// them sinh vien vao vi tri bat ky
void themSinhVien(SinhVien arr[], int &n, int pos, SinhVien sv)
{
    for (int i = n - 1; i > pos; --i)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = sv;
    n++;
}
void xoaSinhVien(SinhVien arr[], int &n, int pos)
{
    for (int i = pos; i < n - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}
int main()
{
    SinhVien arr[100];
    int pos;
    SinhVien sv;
    int key;
    int n;
    cout << "\nNhap so luong sinh vien: ";
    cin >> n;
    while (true)
    {
        cout << "\n\n\t\tCHUONG TRINH QUAN LY SINH VIEN\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Tim kiem sinh vien theo diem Trunh binh.      **\n";
        cout << "**  2. Nhap thong tin sinh vien.                     **\n";
        cout << "**  3. Xuat danh sach sinh vien.                     **\n";
        cout << "**  4. Them sinh vien.                               **\n";
        cout << "**  5. Xoa sinh vien.                                **\n";
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
            float diemTimKiem;
            cout << "\nNhap diem can tim kiem: ";
            cin >> diemTimKiem;
            timKiemSVTheoDiem(arr, n, diemTimKiem);
            break;
        case 2:
            cout << "\n\n\t\tNHAP DANH SACH SINH VIEN\n";
            nhapDanhSachSinhVien(arr, n);
            break;
        case 3:
            cout << "\n\n\t\tXUAT DANH SACH SINH VIEN\n";
            xuatDanhSachSinhVien(arr, n);
            break;
        case 4:
            cout << "\nNhap vi tri can them: ";
            cin >> pos;
            cout << "\n\n\t\tNHAP THONG TIN SINH VIEN CAN THEM\n";
            nhapThongTinSinhVien(sv);
            themSinhVien(arr, n, pos, sv);

            cout << "\n\n\t\tXUAT DANH SACH SINH VIEN\n";
            xuatDanhSachSinhVien(arr, n);
            break;
        case 5:
            cout << "\nNhap vi tri muon xoa: ";
            cin >> pos;
            xoaSinhVien(arr, n, pos);
            cout << "\n\n\t\tXUAT DANH SACH SINH VIEN\n";
            xuatDanhSachSinhVien(arr, n);
            break;
        }
    }

    return 0;
}