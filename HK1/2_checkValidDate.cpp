#include <iostream>
using namespace std;

int main()
{
    int ngay, thang, nam;
    int ngaymax;
    cout << "Nhap ngay: ";
    cin >> ngay;
    cout << "Nhap thang: ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
    if (nam < 0 || thang < 0 || thang > 12 || ngay < 0 || ngay > 31)
        cout << "Ko hop le";
    else
    {
        switch (thang)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ngaymax = 31;
            break;
        case 2:
            ngaymax = 28 + ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ngaymax = 30;
            break;
        }
        if (ngay <= ngaymax)
            cout << "Hop le";
        else
        {
            cout << "Ko hop le";
            return 0;
        }
    }
    return 0;
}