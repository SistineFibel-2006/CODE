#include <bits/stdc++.h>
#define int long long 
#define what(x) x>0?1:-1
using namespace std;

int n,m,p,s,k,add,ans;
int a[100000];

int main(){
    cin >> n;
    for(int i=1; i <= n ; i++) cin >> a[i];
    cin >> m >> p >> s >> k;
    for(int i=1; i <= n ; i++) add += (a[i] * (m-i));
    add+= (s * (m-p));
    int x = (add*1.0 / k + 0.5 * (what(add)));
    ans = m + x ;
    if (ans > n ) ans = n;
    if (ans < 1 ) ans = 1;
    cout << ans;
    return 0; 
}