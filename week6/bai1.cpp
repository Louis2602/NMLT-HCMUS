#include <iostream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
};
void time1(Time &moc1)
{
    cout << "Nhap moc thoi gian thu 1" << endl;
    cout << "Nhap gio: ";
    cin >> moc1.hour;
    cout << "Nhap phut: ";
    cin >> moc1.minute;
    cout << "Nhap giay: ";
    cin >> moc1.second;
}

void time2(Time &moc2)
{
    cout << "Nhap moc thoi gian thu 2" << endl;
    cout << "Nhap gio: ";
    cin >> moc2.hour;
    cout << "Nhap phut: ";
    cin >> moc2.minute;
    cout << "Nhap giay: ";
    cin >> moc2.second;
}
void calculate(Time &moc1, Time &moc2)
{
    int sumTime1 = moc1.hour * 3600 + moc1.minute * 60 + moc1.second;
    int sumTime2 = moc2.hour * 3600 + moc2.minute * 60 + moc2.second;

    int chenhlech = sumTime2 - sumTime1;
    int newHour, newMinute, newSecond;
    newHour = chenhlech / 3600;
    chenhlech %= 3600;
    newMinute = chenhlech / 60;
    newSecond = chenhlech % 60;
    cout << "Chenh lenh giua 2 moc thoi gian la: " << newHour << ":" << newMinute << ":" << newSecond << endl;
}
int main()
{
    Time moc1;
    Time moc2;

    time1(moc1);
    time2(moc2);

    calculate(moc1, moc2);

    return 0;
}