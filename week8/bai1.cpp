#include <iostream>
#include <fstream>

using namespace std;

void copyFile(char input[], char output[])
{
    ifstream in;
    ofstream out;

    in.open(input);
    out.open(output);
    string s;
    // '|' consider as one single line
    while (getline(in, s, '|'))
    {
        in >> s;
        out << s << " ";
    }
    in.close();
    out.close();
}
int main()
{
    char input[] = "input.txt";
    char output[] = "output.txt";
    copyFile(input, output);
    return 0;
}