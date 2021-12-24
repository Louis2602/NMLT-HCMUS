#include <iostream>
using namespace std;
#define COLS 30
#define ROWS 30
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
int main()
{
    int matrix[ROWS][COLS] = {
        {2, 3, 4, 1, 4, 6},
        {1, 1, 1, 3, 3, 2},
        {5, 4, 2, 8, 6, 5},
        {9, 9, 8, 8, 6, 6},
        {3, 4, 5, 8, 7, 6},
        {6, 6, 5, 3, 1, 0}};
    int n = 3, res[ROWS][COLS];
    create_matrix(matrix, n, res);
    return 0;
}