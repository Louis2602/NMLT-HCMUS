#include <iostream>
using namespace std;

union
{
    float f;
    struct
    {
        unsigned int mantisa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } parts;
} data;

int main()
{
    data.f = -2.2;
    cout << hex << data.parts.sign << '\n';
    cout << hex << data.parts.exponent << '\n';
    cout << hex << data.parts.mantisa << '\n';

    return 0;
}