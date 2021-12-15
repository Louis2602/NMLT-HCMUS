#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    char input[] = "input.txt";
    char output[] = "output.txt";
    ifstream fin;
    ofstream fout;
    fin.open(input);
    fout.open(output);
    string s;
    string a[30];
    int n = 0;
    while (getline(fin, s))
    {
        n++;
    }
    fin.close();
    fin.open(input);
    for (int i = 0; i < n; ++i)
    {
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n - 1; ++j)
        {
            cout << a[j];
        }
        return 0;
    }
}