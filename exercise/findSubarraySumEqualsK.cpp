#include <iostream>
using namespace std;

bool sum(int a[], int m, int n) {
  if (m == 0)
    return true;
  if (n == 0)
    return false;
  return (sum(a, m - a[n - 1], n - 1) || sum(a, m, n - 1));
}

int main() {
  int a[1000];
  int n, m;
  bool ans;
  cout << "Nhap so nguyen n: ";
  cin >> n;
  cout << "Nhap mang: ";
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << "Nhap M: ";
  cin >> m;
  ans = sum(a, m, n);
  if (ans)
    cout << "yes";
  else
    cout << "no";
  return 0;
}
