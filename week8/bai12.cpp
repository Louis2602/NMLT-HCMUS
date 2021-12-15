#include <iostream>
#include <fstream>

using namespace std;
bool checkPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < n; ++i)
    {
        if (n % 2 == 0)
            return false;
    }
    return true;
}
int countPrimes(char input[])
{
    ifstream fin;
    fin.open(input);
    int n;
    int cnt = 0;
    while (fin >> n)
    {
        if (checkPrime(n))
            cnt++;
    }
    fin.close();
    return cnt;
}

int main()
{
    char input[] = "output.txt";
    cout << countPrimes(input);
    return 0;
}