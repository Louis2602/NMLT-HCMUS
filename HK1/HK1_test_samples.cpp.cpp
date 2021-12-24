#include <iostream>
#include <fstream>

using namespace std;

#define COLS 30 // so cot toi da cua ma tran
#define ROWS 30 // so dong toi da cua ma tran
#define NB 120  // so luong sach co san trong books.txt

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
void diophantine_equation(int a, int b, int c, int &x, int &y)
{
    // giai phuong trinh nghiem nguyen voi x,y thuoc [-50, 50] thoa ax + by = c
    // a = -5, b = 50, c = 15 => x = -3, y = 0

    int g = gcd(abs(a), abs(b), x, y);
    if (a == 0 && b == 0)
    {
        if (c == 0)
            cout << "Infinite solutions\n";
        else
            cout << "No solution!\n";
    }
    if (c % g)
        cout << "No solution!\n";
    x *= (c / g);
    y *= (c / g);
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
}
void create_matrix(int mtx[][COLS], int n, int res[][COLS])
{
    // cho ma tran vuong 2nx2n, tao ma tran nxn, gap tu duoi len tren, roi gap tu trai sang phai
    /* Ex: n = 2
    1 2 3 5
    5 6 7 8
    5 5 5 5
    6 6 6 6
=>  17 18
    23 23
    */
    int tmp[ROWS][COLS];
    // gap tu duoi len
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2 * n; ++j)
            tmp[i][j] = mtx[i][j] + mtx[2 * n - i - 1][j];
    // gap tu trai qua phai
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res[i][j] = tmp[i][j] + tmp[i][2 * n - j - 1];
    // doi vi tri phan tu
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n / 2; ++j)
            swap(res[i][j], res[i][n - j - 1]);
    // xuat mang
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << res[i][j] << " ";
        cout << '\n';
    }
}
struct Book
{
    char name[30];
    char author[20];
    int year;
};
void find_books(Book B[NB], char word[10], int findin, Book result[], int &len)
{
    // tim sach ma trong ten sach hoac ten tac gia co xuat hien chuoi con word
    // findin = 1 => tim trong ten sach; finin = -1 => tim trong ten tac gia
    // Ex: word = "harry", findin = 1 => len = 2; result = {{"HarryPotterBoxedSetBooks","JKRowling",2004} , {"HarryPotterCollection","JKRowling",2005} }
}

int main_student()
{
    // ham main sinh vien, dung de debug

    return 0;
}

int main(int argc, char **argv)
{
    // KHONG DUOC THAY DOI HAM MAIN
    if (argc < 2)
        main_student();
    else
    {
        int a, b, c, x = -10000, y = -10000;
        cin >> a >> b >> c;
        diophantine_equation(a, b, c, x, y);
        cout << x << " " << y << "\n";

        int matrix[ROWS][COLS], result[ROWS][COLS] = {-10000};
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; i++)
            for (int j = 0; j < 2 * n; j++)
                cin >> matrix[i][j];
        create_matrix(matrix, n, result);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cout << result[i][j] << " ";
        cout << "\n";

        Book B[NB];
        ifstream f("books.txt");
        for (int i = 0; i < NB; i++)
        {
            f >> B[i].name >> B[i].author >> B[i].year;
        }
        int findin, len = -1;
        char word[10];
        Book result2[NB] = {"", "", -1};
        cin >> findin >> word;
        find_books(B, word, findin, result2, len);
        cout << len << " ";
        for (int i = 0; i < len; i++)
            cout << result2[i].name << " ";
        cout << "\n";
    }
    return 0;
}