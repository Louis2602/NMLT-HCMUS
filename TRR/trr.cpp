#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Data{
    int x , xx, xxx, xxxx;
};
 
int main()
{
    int a,b, d;
    Data y;
    vector<Data> v;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    int r = 0,x;
    while (b != 0){
        cout << a << " = " << a/b << "*" << b << " + " << a%b << endl;
        y.x = a;
        y.xx = a/b;
        y.xxx = b;
        y.xxxx = a%b;
        v.push_back(y);
        x = a;
        a = b;
        b = x%b;
    }
    d = a;
    int n = 0,m = 0;
    int cnt = 0;
    a = v[v.size()-2].x;
    b = v[v.size()-2].xxx;
    n = 1;
    m = -1*v[v.size()-2].xx;
    cout << endl;
    while (v[0].x*n + v[0].xxx*m != d){
        cnt++;
        if (a < b) swap(a,b);
        if (cnt % 2 != 0){
            cout << d << " = " << n << "*" << a << " + " << m << "*" << b << endl;
        }
        else{
            for(int i=v.size()-1; i>=0; i--){
                if (v[i].xxxx == b){
                    cout << d << " = " << n << "*" << a << " + " << m << "*(" << v[i].x << " + " << -1*v[i].xx << "*" << v[i].xxx << ")" << endl;
                    int tmp;
                    tmp = n;
                    n = m;
                    m = tmp + n*(-1*v[i].xx);
                    a = v[i].x;
                    b = v[i].xxx;
                    break;
                }
            }
        }
        //cout << cnt <<  " "  << b << endl;
    }
    cout << d << " = " << n << "*" << a << " + " << m << "*" << b << endl;
    //cout << a << n << b << m;
 
    return 0;
}