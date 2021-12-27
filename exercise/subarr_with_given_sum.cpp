#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1, 4, 20, 3, 10, 5};
    int n = 6;
    int i = 0, j = 0;
    int sum = 27;
    int tmp = 0;
    while (i < n)
    {
        cout << tmp << '\n';
        if (tmp == sum)
            break;
        else if (tmp < sum)
            tmp += arr[i++];
        else
            tmp -= arr[j++];
    }
    cout << "Subarray with given sum starts from " << j << " to " << i - 1 << '\n';
    return 0;
}