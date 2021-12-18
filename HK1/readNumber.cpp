#include <iostream>
#include <math.h>
using namespace std;

void hangdonvi(int n)
{
	if (n == 1)
		cout << " Ty ";
	if (n == 2)
		cout << " Tram  ";
	if (n == 3)
		cout << " Muoi ";
	if (n == 4)
		cout << " Trieu ";
	if (n == 5)
		cout << " Tram ";
	if (n == 6)
		cout << " Muoi ";
	if (n == 7)
		cout << " Nghin ";
	if (n == 8)
		cout << " Tram ";
	if (n == 9)
		cout << " Muoi ";
	if (n == 10)
		cout << " ";
}

int main()
{
	long long n;
	cout << "Nhap n = ";
	cin >> n;
	int trunggian, j = 1000000000, a = 0;
	for (int i = 1; i <= 10; i++)
	{
		trunggian = n / j;
		switch (trunggian)
		{
		case 0:
			if (i % 9 == 0 && (n % j) / (j / 10) != 0 && a == 1)
			{
				cout << " le ";
			}
			if ((i == 4 || i == 7 || i == 10) && a == 1)
			{
				hangdonvi(i);
				a = 0;
			}
			break;
		case 1:
			if (i % 3 != 0)
				cout << " Mot ";
			hangdonvi(i);
			a = 1;
			break;
		case 2:
			cout << " Hai ";
			hangdonvi(i);
			a = 1;
			break;
		case 3:
			cout << " Ba ";
			hangdonvi(i);
			a = 1;
			break;
		case 4:
			cout << " Bon ";
			hangdonvi(i);
			a = 1;
			break;
		case 5:
			cout << " Nam ";
			hangdonvi(i);
			a = 1;
			break;
		case 6:
			cout << " Sau ";
			hangdonvi(i);
			a = 1;
			break;
		case 7:
			cout << " Bay ";
			hangdonvi(i);
			a = 1;
			break;
		case 8:
			cout << " Tam ";
			hangdonvi(i);
			a = 1;
			break;
		case 9:
			cout << " Chin ";
			hangdonvi(i);
			a = 1;
			break;
		}
		n = n % j;
		j = j / 10;
	}
	return 0;
}
