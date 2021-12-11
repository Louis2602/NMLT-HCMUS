#include <iostream>
#include <map>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int num[1000];
    string word[1000];
    long long horizontal = 0, depth = 0, aim = 0;
    for (int i = 0; i < 1000; ++i)
    {
        cin >> word[i] >> num[i];
    }
    for (int i = 0; i < 1000; ++i)
    {
        if (word[i] == "forward")
        {
            horizontal += num[i];
            depth += num[i] * aim;
        }
        else if (word[i] == "down")
            aim += num[i];
        else
            aim -= num[i];
    }
    cout << depth * horizontal;
    return 0;
}
