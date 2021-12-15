#include <iostream>
#include <fstream>
using namespace std;
int insertDoubleSpaced(char input[])
{
    ifstream fin;
    ofstream fout;
    fin.open(input);
    fout.open("tmp.txt");

    char ch;
    while (fin.get(ch))
    {
        if (ch != '\n')
        {
            fout << ch;
        }
        else
            fout << "\n\n";
    }
    fin.close();
    fout.close();
    remove(input);
    rename("tmp.txt", input);
}

int main()
{
    char input[] = "input.txt";
    insertDoubleSpaced(input);
    return 0;
}