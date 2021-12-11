#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // x^2021 + 2021x - 1 = 0
    float x = 1.3;
    // 2021x^2020 + 2021
    float sum;
    int i = 0;
    while (i < 10000)
    {
        sum = x - ((pow(x, 2021) + 2021 * x - 1) / (2021 * pow(x, 2020) + 2021));
        x = sum;
        i++;
    }
    cout << sum;
    return 0;
}