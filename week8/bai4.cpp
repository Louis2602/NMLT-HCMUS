#include <iostream>
#include <fstream>

using namespace std;

int printSource(char input[])
{
    ifstream in;
    string s;
    in.open(input);

    while (!in.eof())
    {
        getline(in, s);
        cout << s << '\n';
    }
    in.close();
}

int main()
{
    char input[] = "bai4.cpp";
    printSource(input);
    return 0;
}