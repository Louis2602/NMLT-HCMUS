#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 100
struct VanDongVien
{
    int maSo;
    float canNang;  // don vi kg
    float chieuCao; // don vi m
};
void cau1(char input[])
{
    ifstream fin;
    fin.open(input);
    int a[MAX][MAX];
    int n;
    fin >> n;
    int x;
    fin >> x;
    int num;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fin >> num;
            a[i][j] = num;
        }
    }
    int cnt[MAX];
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == x || a[i++][j] == x)
                cnt[k]++;
            else
            {
                k++;
            }
        }
    }
    cout << "Chua hoan thanh";
}

void Remove(VanDongVien danhSachVDV[], int &n)
{
    float bmi = 0;
    int i = 0;
    while (i < n)
    {
        bmi = float(danhSachVDV[i].canNang) / pow(danhSachVDV[i].chieuCao, 2);
        if (bmi >= 18.5 && bmi <= 24.9)
        {
            for (int j = i; j < n; ++j)
            {
                danhSachVDV[j] = danhSachVDV[j + 1];
            }
            i = 0;
            n--;
        }
        i++;
    }
    // 102 1001 1004 1005
    // 102 1004 1005
    for (int i = 0; i < n; i++)
        cout << danhSachVDV[i].maSo << " ";
}
void cau3(char par[])
{
    ifstream fin;
    fin.open(par);
    char ch;
    int cntWords = 0;
    // so tu trong doan van
    while (fin.get(ch))
    {
        if (ch == ' ' || ch == '\n')
            cntWords++;
    }
    cout << "So tu co trong doan van: " << cntWords << '\n';
    fin.close();

    // so tu it hon 3 ky tu
    fin.open(par);
    int tmp = 0;
    int cntLessWords = 0;
    while (fin.get(ch))
    {
        if (ch == ' ' || ch == '\n')
        {
            if (tmp < 3)
                cntLessWords++;
            tmp = 0;
        }
        else
            tmp++;
    }
    cout << "So tu co it hon 3 ky tu: " << cntLessWords << '\n';
    fin.close();

    fin.open(par);

    string s1[1000];
    int cnt[1000];
    char s[1000];
    for (int i = 0; i < cntWords; ++i)
    {
        fin >> s;
        s1[i] = strtok(s, " ,.-");
    }
    for (int i = 0; i < cntWords; ++i)
    {
        for (int j = 0; j < cntWords; ++j)
        {
            if (s1[i] == s1[j])
                cnt[i]++;
        }
    }
    for (int i = 0; i < cntWords; ++i)
    {
        cout << s1[i] << '\n';
    }
    int cntDiff = 0;
    for (int i = 0; i < cntWords; ++i)
    {
        if (cnt[i] == 0)
            cntDiff++;
    }
    cout << "Chua hoan thanh\n";
    cout << "So tu khac nhau la: " << cntDiff << '\n';
    fin.close();
}
int FindKey(string text)
{
    cout << "Chua hoan thanh";
}
int main()
{
    VanDongVien danhSachVDV[MAX];
    int n = 5;
    string text;
    char par[] = "paragraph.txt";
    char input[] = "input.txt";
    // Khoi tao danh sach van dong vien
    danhSachVDV[0] = {105, 53, 1.65};  // dat
    danhSachVDV[1] = {102, 80, 1.7};   // ko dat
    danhSachVDV[2] = {1001, 60, 1.6};  // dat
    danhSachVDV[3] = {1004, 65, 1.59}; // ko dat
    danhSachVDV[4] = {1005, 70, 1.75}; // dat

    int key;
    while (true)
    {
        cout << "\n*************************MENU************************\n";
        cout << "**  1. Cau 1.                                        **\n";
        cout << "**  2. Cau 2.                                        **\n";
        cout << "**  3. Cau 3.                                        **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key)
        {
        case 0:
            cout << "Ban da chon thoat chuong trinh!";
            return 0;
            break;
        case 1:
            cau1(input);
            break;
        case 2:
            Remove(danhSachVDV, n);
            break;
        case 3:
            cau3(par);
            break;
        case 4:
            FindKey(text);
            break;
        }
    }
    return 0;
}