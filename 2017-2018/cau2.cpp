#include <iostream>
using namespace std;
int check(int thang, int nam)
{
    int ngaymax;
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
    return ngaymax;
}
int main()
{
    int ngay, thang, nam;
    cin >> ngay >> thang >> nam;
    int khoangcach = 0;
    if (thang == 1)
        khoangcach = ngay - 1;
    else
    {

        for (int i = 2; i < thang; ++i)
        {
            khoangcach += check(i, nam);
        }
        khoangcach += ngay + 30;
    }
    cout << khoangcach;
    return 0;
}