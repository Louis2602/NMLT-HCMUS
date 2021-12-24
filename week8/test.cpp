#include <iostream>
#include <fstream>

using namespace std;

void readFile(char *input)
{
    ifstream fin;
    fin.open(input);
    string s;
    // read 1 line
    getline(fin, s);
    cout << s;
}

int main()
{
    char input[] = "input.txt";
    char output[] = "output.txt";
    readFile(input);
    return 0;
}