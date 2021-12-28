#include <iostream>
using namespace std;

int main()
{
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    int n = 4;
    int ans[4][4];
    cout << "Cach 1\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans[i][j] = matrix[n - j - 1][i];
    // output
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
    cout << "Cach 2\n";
    // transpose matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    // flip horizontally
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = tmp;
        }
    }
    // output
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << '\n';
    }
    return 0;
}