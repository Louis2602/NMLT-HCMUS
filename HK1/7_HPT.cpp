#include <iostream>
using namespace std;

struct PT
{
    float a;
    float b;
    float c;
};

void nhapPT(PT &pt1, PT &pt2)
{
    cout << "Nhap phuong trinh 1:\n";
    cout << "Nhap a: ";
    cin >> pt1.a;
    cout << "Nhap b: ";
    cin >> pt1.b;
    cout << "Nhap b: ";
    cin >> pt1.c;
    cout << "Nhap phuong trinh 2:\n";
    cout << "Nhap a: ";
    cin >> pt2.a;
    cout << "Nhap b: ";
    cin >> pt2.b;
    cout << "Nhap b: ";
    cin >> pt2.c;
    cout << "He phuong trinh cua ban la:\n";
    cout << pt1.a << "x + " << pt1.b << "y = " << pt1.c << endl;
    cout << pt2.a << "x + " << pt2.b << "y = " << pt2.c << endl;
}
int main()
{
    PT pt1;
    PT pt2;
    nhapPT(pt1, pt2);
    int common1 = pt1.a, common2 = pt2.a;
    pt1.a *= common2;
    pt1.b *= common2;
    pt1.c *= common2;
    pt2.a *= common1;
    pt2.b *= common1;
    pt2.c *= common1;

    cout << "He phuong trinh sau khi bien doi la:\n";
    cout << pt1.a << "x + " << pt1.b << "y = " << pt1.c << endl;
    cout << pt2.a << "x + " << pt2.b << "y = " << pt2.c << endl;

    float a, b, c;
    a = pt1.a - pt2.a;
    b = pt1.b - pt2.b;
    c = pt1.c - pt2.c;
    cout << "Vay:\n";
    float y = c / b;
    cout << "=> x = " << float(pt1.c - pt1.b * y) / pt1.a << endl;
    cout << "=> y = " << y << endl;
    return 0;
}