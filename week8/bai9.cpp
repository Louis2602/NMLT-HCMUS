#include <iostream>
#include <fstream>
using namespace std;
int insert2thLine(char input[])
{
    ifstream fin;
    ofstream fout;
    fin.open(input);
    fout.open("tmp.txt");

    int line = 0;
    string s;
    string line_2nd;
    while (getline(fin, s, '\n'))
    {
        line++;
        if (line == 2)
        {
            line_2nd = s;
        }
    }
    fin.close();
    fin.open(input);
    int n = 1;
    while (getline(fin, s))
    {
        if (n % 2 == 0)
        {
            fout << line_2nd << endl;
        }
        else
            fout << s << endl;
        n++;
    }

    fin.close();
    fout.close();
    remove(input);
    rename("tmp.txt", input);
}

int main()
{
    char input[] = "input.txt";
    insert2thLine(input);
    return 0;
}