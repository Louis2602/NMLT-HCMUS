#include <iostream>
#include <fstream>

using namespace std;
int sumMatrix(char input[])
{
    ifstream fin;
    fin.open(input);
    int m, n;
    fin >> m >> n;
    int arr[100][100];
    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    fin.close();
    return sum;
}

int main()
{
    char input[] = "input.txt";
    cout << sumMatrix(input);
    return 0;
}