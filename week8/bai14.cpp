#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
void sortListName(char input[])
{
    ifstream fin;
    fin.open(input);
    int n;
    fin >> n;
    char str[25][25], temp[25];
    for (int i = 0; i < n; ++i)
    {
        fin >> str[i];
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    cout << "Danh sach ten thi sinh sau khi sap xep la:\n";
    for (int i = 0; i < n; ++i)
        cout << str[i] << endl;
    fin.close();
}
int main()
{
    char input[] = "input.txt";
    sortListName(input);
    return 0;
}