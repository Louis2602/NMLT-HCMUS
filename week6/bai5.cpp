#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#define MAX 100
struct Car
{
    string carMake;  // hang xe
    string carModel; // model
    int yearModel;   // nam san xuat
    double cost;     // gia thanh
    int quantity;    // so luong
};
struct soldCar
{
    string carMake;
    int quantity;
    double cost;
};
void PrintLine(int n);
void nhapXe(Car a[], int n); // Nhap thong tin xe
void nhapThongTinXe(Car &car);
void xuatDanhSachXe(Car a[], int n);
void banXe(Car a[], soldCar b[], int &n);
int xoaXe(Car a[], string tenXe, int n);
void doanhThu(soldCar b[], int n);

int main()
{
    int key;
    Car arrayCar[MAX];
    Car car;
    soldCar arraySoldCar[MAX];
    int amountOfCar = 0;
    while (true)
    {
        cout << "\n\t\tCHUONG TRINH QUAN LY XE\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. In ra cac xe co trong hang.                   **\n";
        cout << "**  2. Nhap them xe moi.                             **\n";
        cout << "**  3. Ban xe.                                       **\n";
        cout << "**  4. Thu hoi xe cu (xoa)                           **\n";
        cout << "**  5. Tong ket ban hang trong thang.                **\n";
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
            cout << "\nHien thi danh sach cac hang xe.";
            xuatDanhSachXe(arrayCar, amountOfCar);
            break;
        case 2:
            cout << "\n2. Nhap them xe moi.";
            nhapXe(arrayCar, amountOfCar);
            cout << "\nNhap them xe moi thanh cong!";
            amountOfCar++;
            break;
        case 3:
            cout << "\n3. Ban xe.";
            banXe(arrayCar, arraySoldCar, amountOfCar);
            break;
        case 4:
            cout << "Nhap ten hang xe muon thu hoi: ";
            cin >> car.carMake;
            if (xoaXe(arrayCar, car.carMake, amountOfCar) == 1)
                cout << "\nHang xe da duoc thu hoi het.";
            amountOfCar--;
            break;
        case 5:
            cout << "\n5. Tong ket ban hang trong thang.";
            doanhThu(arraySoldCar, amountOfCar);
            break;
        }
    }
    return 0;
}

void printLine(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "_";
    }
    cout << endl;
}
void nhapXe(Car a[], int n)
{
    printLine(40);
    cout << "Nhap hang xe thu " << n + 1 << ":";
    nhapThongTinXe(a[n]);
    printLine(40);
}
void nhapThongTinXe(Car &car)
{
    printLine(40);
    fflush(stdin);
    cout << "Nhap hang xe: ";
    getline(cin, car.carMake);
    cout << "Nhap model xe: ";
    getline(cin, car.carModel);
    cout << "Nhap nam san xuat: ";
    cin >> car.yearModel;
    cout << "Nhap gia thanh: ";
    cin >> car.cost;
    cout << "Nhap so luong: ";
    cin >> car.quantity;
    printLine(40);
}
void xuatDanhSachXe(Car a[], int n)
{
    printLine(90);
    cout << "STT\t" << setw(8) << "Hang xe\t" << setw(15) << "Mau ma\t" << setw(18) << "Nam san xuat\t" << setw(10) << "Gia thanh\t" << setw(10) << "So luong";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << i + 1;
        cout << setw(13) << a[i].carMake;
        cout << setw(15) << a[i].carModel;
        cout << setw(15) << a[i].yearModel;
        cout << setw(19) << a[i].cost << " $";
        cout << setw(17) << a[i].quantity;
    }
    printLine(90);
}

void banXe(Car a[], soldCar b[], int &n)
{
    printLine(40);
    string tenHangXe;
    int soLuongXe;
    fflush(stdin);
    cout << "Nhap ten hang xe muon ban: ";
    getline(cin, tenHangXe);
    cout << "Nhap so luong xe muon ban: ";
    cin >> soLuongXe;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].carMake == tenHangXe)
        {
            if (a[i].quantity >= soLuongXe)
            {
                cout << "Xe da duoc ban thang cong\n";
                b[i].quantity = soLuongXe;
                b[i].carMake = tenHangXe;
                b[i].cost = a[i].cost;
                a[i].quantity -= soLuongXe;
                if (a[i].quantity == 0)
                {
                    if (xoaXe(a, a[i].carMake, n) == 1)
                    {
                        cout << "Xe da duoc ban het!\n";
                    }
                    n--;
                }
                break;
            }
            else
            {
                cout << "Khong du so luong xe trong cua hang de ban!\n";
                break;
            }
        }
        else
        {
            cout << "Khong co hang xe do trong cua hang!\n";
        }
    }
    printLine(40);
}

int xoaXe(Car a[], string tenXe, int n)
{
    int found = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].carMake == tenXe)
        {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            cout << "\nDa xoa hang xe " << tenXe;
            printLine(40);
            break;
        }
    }
    if (found == 0)
    {
        cout << "Hang xe " << tenXe << " khong co trong cua hang!\n";
        return 0;
    }
    else
    {
        return 1;
    }
}

void doanhThu(soldCar b[], int n)
{
    int money = 0;
    for (int i = 0; i < n; ++i)
    {
        money += b[i].quantity * b[i].cost;
    }
    cout << "\nTong doanh thu la: " << money << " $" << endl;
}