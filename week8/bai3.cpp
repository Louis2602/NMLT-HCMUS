#include <iostream>
#include <fstream>
using namespace std;

int countAverageChar(char input[])
{
    ifstream fin;
    fin.open(input);
    char ch;
    int cnt = 0;
    int avg = 0;
    int line = 0;
    fin.get(ch);
    while (fin)
    {
        while (fin && ch != '\n')
        {
            cnt++;
            avg += int(ch);
            fin.get(ch);
        }
        line++;
        cout << "gia tri trung binh dong " << line << ": " << avg / cnt << endl;
        avg = 0;
        cnt = 0;
        fin.get(ch);
    }
    fin.close();
}
int main()
{
    char input[] = "input.txt";
    countAverageChar(input);
    return 0;
}