#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    // a là đơn vị
    int a = n % 10;
    // b là chục
    int b = (n / 10) % 10;
    // c là hàng trăm
    int c = n / 100;
    //điều kiện số có hai chữ số
    if (n < 1 || n > 999)
    {
        cout << "Nhap sai!";
    }
    else
    {
        // in ra hàng trăm
        switch (c)
        {
        case 1:
            printf("Mot tram ");
            break;
        case 2:
            printf("Hai tram ");
            break;
        case 3:
            printf("Ba tram ");
            break;
        case 4:
            printf("Bon tram ");
            break;
        case 5:
            printf("Nam tram ");
            break;
        case 6:
            printf("Sau tram ");
            break;
        case 7:
            printf("Bay tram ");
            break;
        case 8:
            printf("Tam tram ");
            break;
        case 9:
            printf("Chin tram ");
            break;
        }
        // in ra chử "lẻ" nếu hàng chục bằng không
        if (n > 100)
            if (b % 10 == 0 && a != 0)
                printf("le ");
        // in ra hàng chục
        switch (b)
        {
        case 1:
            printf("muoi ");
            break;
        case 2:
            printf("hai muoi ");
            break;
        case 3:
            printf("ba muoi ");
            break;
        case 4:
            printf("bon muoi ");
            break;
        case 5:
            printf("nam muoi ");
            break;
        case 6:
            printf("sau muoi ");
            break;
        case 7:
            printf("bay muoi ");
            break;
        case 8:
            printf("tam muoi ");
            break;
        case 9:
            printf("chin muoi ");
            break;
        }
        // in ra hàn đơn vị
        switch (a)
        {
        case 1:
            printf("mot ");
            break;
        case 2:
            printf("hai ");
            break;
        case 3:
            printf("ba ");
            break;
        case 4:
            printf("bon ");
            break;
        case 5:
            printf("nam ");
            break;
        case 6:
            printf("sau ");
            break;
        case 7:
            printf("bay ");
            break;
        case 8:
            printf("tam ");
            break;
        case 9:
            printf("chin ");
            break;
        }
    }
    return 0;
}