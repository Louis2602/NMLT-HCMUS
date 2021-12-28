#include <iostream>
using namespace std;

int main()
{
    int n, s = 3;
    int a[] = {1, 2, 3, 4, 5}, dp[40005];
    n = sizeof(a) / sizeof(int);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = s; j >= a[i]; --j)
            if (dp[j - a[i]] == 1)
                dp[j] = 1;
    (dp[s] == 1) ? cout << "YES" : cout << "NO";
    return 0;
}