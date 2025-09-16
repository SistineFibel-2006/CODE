#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string a[21];
bool cmp(string &x, string &y){
    return (x+y > y+x);
}
signed main(void){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a,a+n,cmp);
    for (int i = 0; i < n; i++)
        cout << a[i];
}