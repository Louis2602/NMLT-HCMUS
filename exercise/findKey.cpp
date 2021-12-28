#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i < n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
int findKey(string s)
{
    int n = s.size();
    string t;
    int cnt = 0;
    string tmp;
    int ans = 0;
    int check;
    for (int i = 0; i < n; ++i)
    {
        if (isdigit(s[i]))
            cnt++;
        else
        {
            t = s.substr(i - cnt, cnt);
            if (t.size() >= 2)
            {
                for (int j = 0; j < t.size() - 1; ++j)
                {
                    for (int k = j; k < j + 2; ++k)
                        tmp += t[k];
                    stringstream geek(tmp);
                    geek >> check;
                    if (isPrime(check))
                        ans += check;
                    tmp.clear();
                }
            }
            cnt = 0;
        }
        if (i == n - 1)
        {
            t = s.substr(i + 1 - cnt, cnt);
            if (t.size() >= 2)
            {
                for (int j = 0; j < t.size() - 1; ++j)
                {
                    for (int k = j; k < j + 2; ++k)
                        tmp += t[k];
                    stringstream geek(tmp);
                    geek >> check;
                    if (isPrime(check))
                        ans += check;
                    tmp.clear();
                }
            }
        }
    }
    return ans;
}
int main()
{
    string text = "abc112797def9hung17d1b3";
    // 112797 9 17 1 3
    // split into 2 digits number and check prime
    // 112797 = 11 79 97
    // 17
    // => ans = 11 + 79 + 97 + 17 = 204
    cout << findKey(text);
    return 0;
}