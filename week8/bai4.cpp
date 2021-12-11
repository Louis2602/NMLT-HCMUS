#include <iostream>
#include <fstream>

using namespace std;

int printSource(char input[])
{
    ifstream in;
    string s;
    in.open(input);

    while (getline(in, s, '|'))
    {
        in >> s;
        cout << s;
    }
    in.close();
}

int main()
{
    char input[] = "input.txt";
    printSource(input);
    return 0;
}