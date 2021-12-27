#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    cout << "The given string in lowercase: " << s << '\n';
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = toupper(s[i]);
    }
    cout << "The given string in uppercase: " << s << '\n';
    return 0;
}