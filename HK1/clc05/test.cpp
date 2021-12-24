#include <iostream>
#include <fstream>

using namespace std;
string mssv = "21127337";
bool check(int x)
{
    for (int i = 0; i < (int)mssv.size(); ++i)
        if ((mssv[i] - '0' + 1 == x))
            return 1;
    return 0;
}
struct HocSinh
{
    int MaSV;
    string info[9];
};
HocSinh a[10];
int n;
struct Diem
{
    int MaSV;
    double Toan;
    double Li;
    double Hoa;
    double Van;
    double Tin;
    double dtb;
};

void takeInput(string s, int MaSV)
{
    int i = 0, id = 0;
    while (i < s.size())
    {
        if (s[i] != '\t')
            (a[MaSV].info)[id] += s[i];
        else
            (a[MaSV].info)[++id] = "";
        ++i;
    }
    for (int i = 0; i < 9; ++i)
    {
        cout << (a[MaSV].info)[i] << '\n';
    }
}
void bai2(char danhsach[])
{
    ifstream fin;
    fin.open(danhsach);

    int MaSV;
    string s;
    getline(fin, s, '\n');
    for (int i = 1; i <= 10; ++i)
    {
        fin >> MaSV;
        if (!check(MaSV))
        {
            getline(fin, s, '\n');
            continue;
        }
        getline(fin, s, '\n');
        takeInput(s, i);
    }
}

int main()
{
    char diem[] = "Diem-kiem-tra-1-tiet.txt";
    char danhsach[] = "Danh-sach-hoc-sinh.txt";
    bai2(danhsach);
    return 0;
}