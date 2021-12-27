#include <iostream>
#include <fstream>

using namespace std;
void swap(string &a, string &b)
{
    string tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    char input[] = "input.txt";
    char output[] = "output.txt";

    ifstream fin;
    fin.open(input);
    ofstream fout;
    fout.open(output);

    string s[100];
    int n = 0;
    string tmp;
    while (!fin.eof())
    {
        getline(fin, tmp);
        n++;
    }
    fin.close();
    fin.open(input);
    for (int i = 0; i < n; ++i)
        fin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (s[j] > s[j + 1])
                swap(s[j], s[j + 1]);
    for (int i = 0; i < n; ++i)
        fout << s[i] << '\n';

    fin.close();
    fout.close();

    return 0;
}