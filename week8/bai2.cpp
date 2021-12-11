#include <iostream>
#include <fstream>

using namespace std;

int convertFile60CharsperLine(char input[], char output[])
{
    ifstream in;
    ofstream out;

    in.open(input);
    out.open(output);
    char s[60];
    // '|' consider as one single line
    in.close();
    out.close();
}
int main()
{
    char input[] = "input.txt";
    char output[] = "output.txt";
    convertFile60CharsperLine(input, output);
    return 0;
}