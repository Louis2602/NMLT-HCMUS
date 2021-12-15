#include <iostream>
#include <fstream>

using namespace std;
int writeListOddNumbers(int n, char output[])
{
    ofstream fout;
    fout.open(output);
    int sum = 0;
    for (int i = 11; i < n; i += 2)
    {
        int tmp = i;
        while (tmp != 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum % 2 == 0)
            fout << i << endl;
        sum = 0;
    }
    fout.close();
    fout.open(output);
}

int main()
{
    char output[] = "output.txt";
    int n;
    cout << "Nhap n: ";
    cin >> n;
    while (n < 10)
    {
        cout << "Khong co so nao het!\n";
        cout << "Moi nhap lai: ";
        cin >> n;
    }
    writeListOddNumbers(n, output);
    return 0;
}