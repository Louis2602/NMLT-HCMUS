#include <iostream>
#include <fstream>
using namespace std;

int insert7thLine(char input[])
{
    ifstream fin;
    ofstream fout;
    fin.open(input);
    fout.open("tmp.txt");

    int line = 0;
    string s;
    while (getline(fin, s, '\n'))
    {
        line++;
        fout << s << endl;
    }
    fin.close();
    fin.open(input);
    while (line < 7)
    {
        fout << endl;
        line++;
    }
    fin.close();
    fout.close();
    remove(input);
    rename("tmp.txt", input);
}

int main()
{
    char input[] = "input.txt";
    insert7thLine(input);
    return 0;
}