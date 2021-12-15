#include <iostream>
#include <fstream>

using namespace std;

int deleteLastLine(char input[])
{
    ifstream fin;
    fin.open(input);
    ofstream fout;
    fout.open("tmp.txt");

    int line = 0;
    int n = 1;
    string s;
    while (getline(fin, s, '\n'))
    {
        line++;
    }
    fin.close();
    fin.open(input);
    while (getline(fin, s, '\n') && n < line)
    {
        n++;
        fout << s << endl;
    }
    fin.close();
    fout.close();
    remove(input);
    rename("tmp.txt", input);
}

int main()
{
    char input[] = "input.txt";
    deleteLastLine(input);
    return 0;
}