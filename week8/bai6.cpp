#include <iostream>
#include <fstream>

using namespace std;

int deleteLastLine(char input[])
{
    ifstream fin;
    fin.open(input);
    ofstream fout;
    fout.open("tmp.txt");

    string s;
    while (getline(fin, s))
    {
        if (!s.empty())
        {
            fout << s << endl;
        }
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