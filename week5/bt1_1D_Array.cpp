#include <iostream>
using namespace std;

void setArray(int a[], int &n);
void printArray(int a[], int &n);
void deleteItems(int a[], int &n, int x);
void deleteItemsFromIndex(int a[], int &n, int index, int no_items);
void concatTwoArrays(int a[], int n, int b[], int m, int c[]);
void concatInterspersedlyTwoArrays(int a[], int n, int b[], int m, int c[]);

int main()
{
    int a[100], b[100], c[200];
    int n, x, index, amount;
    int n1, m1;
    cout << "Nhap n: ";
    cin >> n;
    setArray(a, n);
    printArray(a, n);
    cout << "Nhap x: ";
    cin >> x;

    deleteItems(a, n, x);
    printArray(a, n);

    deleteItemsFromIndex(a,n,index,amount);
    printArray(a, n);

    cout << "Nhap n1: ";
    cin >> n1;
    setArray(a, n1);
    cout << "Nhap m1: ";
    cin >> m1;
    setArray(b, m1);
    concatTwoArrays(a, n1, b, m1, c);
    concatInterspersedlyTwoArrays(a, n1, b, m1, c);

    return 0;
}

void setArray(int a[], int &n) {
    cout << "Input Array: ";
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
}
void printArray(int a[], int &n) {
    cout << "Output Array: ";
    for(int i=0; i<n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void deleteItems(int a[], int &n, int x) {
    int i = 0;
    cout << "Mang sau khi xoa: ";
    while(i < n) {
        if(a[i] == x) {
            for(int j=i; j<n; ++j) {
               a[j] = a[j+1];                 
            }
            i=0;
            n--;
        }
        i++;
    }
}

void deleteItemsFromIndex(int a[], int &n, int index, int no_items) {
    cout << "Nhap vi tri can xoa: ";
    cin >> index;
    cout << "Nhap so luong phan tu muon xoa: ";
    cin >> no_items;

    for(int i=index; i<n; ++i) {
        a[i] = a[i+no_items];
    }
    n-=no_items;
}
void concatTwoArrays(int a[], int n, int b[], int m, int c[]) {
    int n1 = n;
    int m1 = m;
    for(int i=0; i<n1+m1; ++i) {
        if(n > 0) {
            c[i]=a[i];
            n--;
        } else if (m > 0) {
            c[i]=b[i-n1];
            m--;
        }
    }
    cout << "Mang sau khi hop lai: ";
    for(int i=0; i<m1+n1; ++i) {
        cout << c[i] << " ";
    }
}

void concatInterspersedlyTwoArrays(int a[], int n, int b[], int m, int c[]) {
    int iA = 0, iB = 0, iC = 0;
    while(iA < n && iB < m) {
        c[iC++] = a[iA++];
        c[iC++] = b[iB++];
    }
    while(iA < n) {
        c[iC++] = a[iA++];
    }
    while(iB < m) {
        c[iC++] = b[iB++];
    }
    cout << "\nMang sau khi hop xen ke: ";
    for(int i=0; i<m+n; ++i) {
        cout << c[i] << " ";
    }
}