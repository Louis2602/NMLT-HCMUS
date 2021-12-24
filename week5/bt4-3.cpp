#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int tickets[78], chairs[78], passengers, i = 1;
    char books[13][6];
    cout << "Nhap so luong hanh khach: ";
    cin >> passengers;
    // hang nhat: 1-2, hang thuong gia: 3->7, hang pho thong: 8->13
    int high = 1, mid = 3, low = 8;
    while (passengers > 0)
    {
        cout << "Nhap thong tin hanh khach thu " << i << endl;
        cout << "Hang nhat: 1\nHang thuong gia: 2\nHang pho thong: 3\n";
        cout << "Vui long chon loai ve: ";
        cin >> tickets[i];
        cout << "Vui long chon loai ghe (A->F : 1->6): ";
        cin >> chairs[i];
        switch (tickets[i])
        {
        case 1:
            if (books[high][chairs[i]] == 'X')
                books[++high][chairs[i]] = 'X';
            else
                books[high][chairs[i]] = 'X';
            break;
        case 2:
            if (books[mid][chairs[i]] == 'X')
                books[++mid][chairs[i]] = 'X';
            else
                books[mid][chairs[i]] = 'X';
            break;
        case 3:
            if (books[low][chairs[i]] == 'X')
                books[++low][chairs[i]] = 'X';
            else
                books[low][chairs[i]] = 'X';
            break;
        }
        i++;
        passengers--;
    }
    cout << "\nSO DO CHO NGOI TREN CHUYEN BAY NGAY HOM NAY\n";
    cout << setw(10) << "A" << setw(4) << "B" << setw(4) << "C" << setw(4) << "D" << setw(4) << "E" << setw(4) << "F" << endl;
    // all the chairs are empty
    for (int i = 1; i <= 13; ++i)
    {
        if (i < 10)
            cout << "Row " << i << setw(5);
        else
            cout << "Row " << i << setw(4);
        for (int j = 1; j <= 6; ++j)
        {
            if (books[i][j] == 'X')
                cout << books[i][j] << setw(4);
            else
                cout << "*" << setw(4);
        }
        cout << endl;
    }
}
