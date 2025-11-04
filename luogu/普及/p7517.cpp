#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int MAXN = 200000;
int n,a[MAXN];

signed main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i< n; i++)
    sort(a,a + n);
    int m[MAXN];
    m = unique(a,a + n) - a; 
}   