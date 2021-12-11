#include <iostream>
using namespace std;

void getData(float tmp[12][2]);
float averageHigh(float tmp[12][2]);
float averageLow(float tmp[12][2]);
int indexHighTemp(float tmp[12][2]);
int indexLowTemp(float tmp[12][2]);
int main()
{
    float tempPerMonth[12][2];
    float avgH, avgL;
    int maxIndex, minIndex;
    getData(tempPerMonth);
    avgH = averageHigh(tempPerMonth);
    cout << "Nhiet do trung binh cao cua 12 thang trong nam la: " << avgH << endl;
    avgL = averageLow(tempPerMonth);
    cout << "Nhiet do trung binh thap cua 12 thang trong nam la: " << avgL << endl;
    maxIndex = indexHighTemp(tempPerMonth);
    cout << "Nhiet do cao nhat trong nam la: " << maxIndex << endl;
    minIndex = indexLowTemp(tempPerMonth);
    cout << "Nhiet do thap nhat trong nam la: " << minIndex << endl;
    return 0;
}

void getData(float tmp[12][2])
{
    for (int i = 1; i <= 12; ++i)
    {
        cout << "Nhap nhiet do cao nhat va thap nhat cua thang " << i << ": ";
        for (int j = 0; j < 2; ++j)
        {
            cin >> tmp[i][j];
        }
    }
}

float averageHigh(float tmp[12][2])
{
    float avg = 0;
    for (int i = 1; i <= 12; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (j == 0)
                avg += tmp[i][j];
        }
    }
    return avg / 12;
}

float averageLow(float tmp[12][2])
{
    float avg = 0;
    for (int i = 1; i <= 12; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (j == 1)
                avg += tmp[i][j];
        }
    }
    return avg / 12;
}
int indexHighTemp(float tmp[12][2])
{
    int max = tmp[1][0];
    for (int i = 1; i <= 12; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
            if (max < tmp[i][j])
                max = tmp[i][j];
        }
    }
    return max;
}
int indexLowTemp(float tmp[12][2])
{
    int min = tmp[1][1];
    for (int i = 1; i <= 12; ++i)
    {
        for (int j = 1; j < 2; ++j)
        {
            if (min > tmp[i][j])
                min = tmp[i][j];
        }
    }
    return min;
}