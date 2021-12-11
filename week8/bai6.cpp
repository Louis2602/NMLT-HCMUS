#include <iostream>
#include <fstream>

using namespace std;

int deleteLastLine(char input[])
{
    ifstream fin(input);
    ofstream fout;
    fout.open("tmp.txt", ios::out);

    string s;
    while (getline(fin, s, '\n'))
    {
        fout << s;
    }
    fout.close();
    fin.close();
    remove(input);
    rename("tmp.txt", input);
}

int main()
{
    char input[] = "input.txt";
    deleteLastLine(input);
    return 0;
}