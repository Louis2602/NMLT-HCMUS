#include <bits/stdc++.h>

#define N 1000
#define inf 10e9

using namespace std;

char s[N];
int mauTin[N], n__mauTin = 0;

struct Hocsinh
{
    char MaHS[N];
    char HoDem[N];
    char Ten[N];
    char NgaySinh[N];
    char GioiTinh[N];
    char Diachi[N];
};

struct diem
{
    int MaHS;
    double Toan;
    double Li;
    double Hoa;
    double Van;
    double Tin;
    double dtb;
};

Hocsinh a[N];
diem b[N];

void ganChuoi(char x[N], char y[N])
{
    int m = strlen(y);
    for (int i = 0; i < m; i++)
        x[i] = y[i];
}

bool check(int x, int a[N], int n)
{
    for (int i = 1; i <= n; i++)
        if (x == a[i])
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin;
    fin.open("Diem-kiem-tra-1-tiet.txt");
    fin.getline(s, N);
    int cntN = 0;
    while (fin.getline(s, N))
    {
        cntN++;
        int n = strlen(s), cnt = 0, m = -1;
        char stmp[N];
        for (int i = 0; i < n; i++)
        {
            if (int(s[i]) != 9)
                stmp[++m] = s[i];
            else
            {
                cnt++;
                stmp[++m] = '\0';
                if (cnt == 1)
                {
                    int num = atoi(stmp);
                    b[cntN].MaHS = num;
                }
                char *endPtr;
                double num = strtod(stmp, &endPtr);
                if (cnt == 2)
                    b[cntN].Toan = num;
                if (cnt == 3)
                    b[cntN].Li = num;
                if (cnt == 4)
                    b[cntN].Hoa = num;
                if (cnt == 5)
                    b[cntN].Van = num;
                if (cnt == 6)
                    b[cntN].Tin = num;
                m = -1;
            }
        }
        cnt++;
        char *endPtr;
        double num = strtod(stmp, &endPtr);
        if (cnt == 6)
            b[cntN].Tin = num;
        b[cntN].dtb = (b[cntN].Toan + b[cntN].Li + b[cntN].Hoa + b[cntN].Van + b[cntN].Tin) / 5;
        cout << b[cntN].MaHS << ' ' << b[cntN].Toan << ' ' << b[cntN].Li << ' ' << b[cntN].Hoa << ' ' << b[cntN].Van << ' ' << b[cntN].Tin << endl;
    }
    fin.close();

    double maxDTB = 0, minDTB = inf;
    for (int i = 1; i <= cntN; i++)
    {
        maxDTB = max(maxDTB, b[i].dtb);
        minDTB = min(minDTB, b[i].dtb);
    }
    cout << "Diem trung binh cao nhat: " << maxDTB << endl;
    cout << "Diem trung binh thap nhat: " << minDTB << endl;

    fin.open("Danh-sach-hoc-sinh.txt");
    fin.getline(s, N);
    cntN = 0;
    while (fin.getline(s, N))
    {
        cntN++;
        int n = strlen(s), m = -1, cnt = 0;
        char stmp[N];
        for (int i = 0; i < n; i++)
        {
            if (int(s[i]) != 9)
                stmp[++m] = s[i];
            else
            {
                cnt++;
                stmp[++m] = '\0';
                if (cnt == 1)
                {
                    ganChuoi(a[cntN].MaHS, stmp);
                    int num = atoi(a[cntN].MaHS);
                    n__mauTin = 0;
                    while (num)
                    {
                        if (!check((num % 10 + 1), mauTin, n__mauTin))
                            mauTin[++n__mauTin] = (num % 10 + 1);
                        num /= 10;
                    }
                }
                if (cnt == 2)
                    ganChuoi(a[cntN].HoDem, stmp);
                if (cnt == 3)
                    ganChuoi(a[cntN].Ten, stmp);
                if (cnt == 4)
                    ganChuoi(a[cntN].NgaySinh, stmp);
                if (cnt == 5)
                    ganChuoi(a[cntN].GioiTinh, stmp);
                if (cnt == 6)
                    ganChuoi(a[cntN].Diachi, stmp);
                m = -1;
            }
        }
        cnt++;
        stmp[++m] = '\0';
        if (cnt == 6)
            ganChuoi(a[cntN].Diachi, stmp);
        cout << a[cntN].MaHS << ' ' << a[cntN].HoDem << ' ' << a[cntN].Ten << ' ' << a[cntN].NgaySinh << ' ' << a[cntN].GioiTinh << ' ' << a[cntN].Diachi << endl;
        cout << "Mau tin cua " << a[cntN].Ten << ": ";
        for (int i = 1; i <= n__mauTin; i++)
            cout << mauTin[i] << ' ';
        cout << endl;
    }
    fin.close();

    return 0;
}
