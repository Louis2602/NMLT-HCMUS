#include <iostream>
#include <fstream>

using namespace std;

int deleteLastLine(char input[], int n)
{
    ifstream fin(input);
    ofstream fout;
    fout.open("tmp.txt", ios::out);

    char ch;
    int line = 1;
    while (fin.get(ch))
    {
        if (ch == '\n')
            line++;

        if (line != n) // content not to be deleted
            fout << ch;
    }
    fout.close();
    fin.close();
    remove(input);
    rename("tmp.txt", input);
}

int main()
{
    int n;
    cout << "Enter the line number you want to delete: ";
    cin >> n;
    char input[] = "input.txt";
    deleteLastLine(input, n);
    return 0;
}