#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int insert2thLine(char input[])
{
    ifstream fin;
    ofstream fout;
    fin.open(input);
    fout.open("tmp.txt");

    string s;
    while (getline(fin, s))
    {
        s.erase(0, 2);
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
    insert2thLine(input);
    return 0;
}