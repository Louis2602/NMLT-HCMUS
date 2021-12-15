#include <iostream>
#include <fstream>
using namespace std;

int countAverageChar(char input[])
{
    ifstream fin;
    fin.open(input);
    char ch;
    int cnt = 0;
    int line = 0;
    while (fin.get(ch))
    {
        if (ch != '\n')
        {
            cnt++;
        }
        else
        {
            line++;
        }
    }
    cout << cnt << " " << line << endl;
    return cnt / line;
    fin.close();
}
int main()
{
    char input[] = "input.txt";
    cout << "Gia tri trung binh so luong ki tu tren 1 dong la: " << countAverageChar(input);
    return 0;
}