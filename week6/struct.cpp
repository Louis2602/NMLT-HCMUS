#include <iostream>
using namespace std;

struct POINT
{
    int x;
    int y;
    char a[30];
    char id[10];
};

POINT newPoint(POINT p)
{
    p.x = 0;
    POINT np = p;
    return np;
}
void input(POINT &p)
{
    cout << "x = ";
    cin >> p.x;
    cout << "y = ";
    cin >> p.y;
}
void show(POINT p)
{
    cout << p.x << ", " << p.y << endl;
}
int main()
{
    POINT p;
    cin.get(p.a, 30);
    cout << p.a << endl;
    fflush(stdin);
    cin.get(p.id, 10);
    cout << p.id << endl;
    return 0;
}