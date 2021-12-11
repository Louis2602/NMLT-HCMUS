#include<iostream>
using namespace std;

#define ll long long

int main()
{
	freopen("input.txt", "r", stdin);
	int a[2000], sum[2000];
	ll s = 0;
	for(int i=0; i<2000; ++i) {
		cin >> a[i];
	}
	for(int i=0; i<2000-3+1; ++i) {
		for(int j=0; j<3; ++j) {
			s += a[j+i];
			sum[i] = s;
		}
		s = 0;
	}
	ll cnt=0;
	for(int i=0; i<2000-3+1-1; ++i) {
		if(sum[i] < sum[i+1])
			cnt++;
	}
	cout << cnt;
	return 0;
}
