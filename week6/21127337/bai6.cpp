#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100

struct CauThu
{
    string name;
    int numAssists;
    int numGoals;
};

void nhapThongTinCauThu(CauThu &ct)
{
    fflush(stdin);
    cout << "\nNhap ten: ";
    cin >> ct.name;
    cout << "Nhap so ban thang: ";
    cin >> ct.numGoals;
    cout << "Nhap so ban ho tro: ";
    cin >> ct.numAssists;
}
void nhapSV(CauThu a[], int n)
{
    cout << "\nNhap cau thu thu " << n + 1;
    nhapThongTinCauThu(a[n]);
}
void xuatDanhSachCauThu(CauThu a[], int n)
{
    cout << "\nSTT\t" << setw(8) << "Ten" << setw(19) << "numGoals" << setw(15) << "numAssists";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << i + 1;
        cout << setw(16) << a[i].name;
        cout << setw(15) << a[i].numGoals;
        cout << setw(15) << a[i].numAssists;
    }
}
int xoaCauThu(CauThu a[], string tenCauThu, int n)
{
    int found = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].name == tenCauThu)
        {
            found = 1;
            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            cout << "\nDa xoa cau thu " << tenCauThu;
            break;
        }
    }
    if (found == 0)
    {
        cout << tenCauThu << " khong co trong danh sach cau thu!\n";
        return 0;
    }
    else
    {
        return 1;
    }
}
void capNhatThongTinCauThu(CauThu &ct)
{
    fflush(stdin);
    cout << "\nNhap so ban thang: ";
    cin >> ct.numGoals;
    cout << "Nhap so ban ho tro: ";
    cin >> ct.numAssists;
}
void capNhatCauThu(CauThu a[], string tenCauThu, int n)
{
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].name == tenCauThu)
        {
            found = 1;
            cout << "\nCap nhat thong tin cau thu co ten la " << tenCauThu << endl;
            capNhatThongTinCauThu(a[i]);
            break;
        }
    }
    if (found == 0)
    {
        cout << "Cau thu co ten " << tenCauThu << " khong ton tai!" << endl;
    }
}
void findBestPlayer(CauThu a[], int n)
{
    float bestPlayer = 0.4 * a[0].numAssists + 0.6 * a[0].numGoals;
    int index = 0;
    for (int i = 1; i < n; ++i)
    {
        int tmp = 0.4 * a[i].numAssists + 0.6 * a[i].numGoals;
        if (bestPlayer < tmp)
        {
            bestPlayer = tmp;
            index = i;
        }
    }
    cout << "\nTen" << setw(20) << "numGoals" << setw(18)
         << "numAssists\t" << setw(10) << "Diem BestPlayer" << endl;
    cout << a[index].name;
    cout << setw(15) << a[index].numGoals;
    cout << setw(15) << a[index].numAssists;
    cout << setw(20) << bestPlayer;
}
int main()
{
    int key;
    CauThu arrayCauThu[MAX];
    CauThu cauthu;
    int soLuongCauThu = 0;
    while (true)
    {
        cout << "\n\t\tCHUONG TRINH QUAN LY CAU THU\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Xuat ra thong tin cau thu.                    **\n";
        cout << "**  2. Nhap thong tin cau thu.                       **\n";
        cout << "**  3. Xoa cau thu.                                  **\n";
        cout << "**  4. Cap nhat thong tin cau thu.                   **\n";
        cout << "**  5. Tim cau thu xuat sac nhat mua gia.            **\n";
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
            xuatDanhSachCauThu(arrayCauThu, soLuongCauThu);
            break;
        case 2:
            cout << "\n2. Nhap thong tin sinh vien.";
            nhapSV(arrayCauThu, soLuongCauThu);
            cout << "\nNhap them sinh vien thanh cong!";
            soLuongCauThu++;
            break;
        case 3:
            if (soLuongCauThu > 0)
            {
                string tenCauThu;
                cout << "\nNhap ten cau thu: ";
                cin >> tenCauThu;
                cout << "\n3. Xoa cau thu.";
                if (xoaCauThu(arrayCauThu, tenCauThu, soLuongCauThu) == 1)
                    soLuongCauThu--;
            }
            else
                cout << "\nDanh sach cau thu trong!";
            break;
        case 4:
            if (soLuongCauThu > 0)
            {
                string tenCauThu;
                cout << "\nNhap ten cau thu: ";
                cin >> tenCauThu;
                cout << "\n4. Cap nhat thong tin cau thu.";
                capNhatCauThu(arrayCauThu, tenCauThu, soLuongCauThu);
            }
            else
                cout << "\nDanh sach cau thu trong!";
            break;
        case 5:
            if (soLuongCauThu > 0)
            {
                cout << "\n5. Tim cau thu xuat sac nhat mua giai.";
                findBestPlayer(arrayCauThu, soLuongCauThu);
            }
            else
                cout << "\nDanh sach cau thu trong!";
            break;
        }
    }
    return 0;
}