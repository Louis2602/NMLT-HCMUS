#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, total = 0;
    cout << "Nhap so ung vien: ";
    cin >> n;

    string names[20];
    int votes[100];
    cout << "Nhap ten cac ung cu vien: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> names[i];
    }
    cout << "Nhap so phieu: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> votes[i];
        total += votes[i];
    }
    float percent[100];
    for (int i = 0; i < n; ++i)
    {
        percent[i] = (float(votes[i]) / total) * 100;
    }
    cout << "Candidate" << setw(10) << "Votes" << setw(30) << "Received \% of Total Votes" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << names[i] << setw(15) << votes[i] << setw(20) << setprecision(4) << percent[i] << endl;
    }
    cout << endl;
    cout << "Total" << setw(15) << total << endl;
    int max = percent[0];
    int winner;
    for (int i = 0; i < n; ++i)
    {
        if (max < percent[i])
        {
            max = percent[i];
            winner = i;
        }
    }
    cout << "The Winner of the Election is " << names[winner] << "." << endl;
    return 0;
}