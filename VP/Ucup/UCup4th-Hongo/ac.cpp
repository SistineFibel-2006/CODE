#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second 
#define ll long long



#define int long long

void solve() {
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int>prel(n+1),prer(n+1),ans(n+1),pre(n+1);
    // for(int i=1;i<=n;i++){
    //     prel[i]=prel[i-1]+(s[i]=='(');
    //     prer[i]=prer[i-1]+(s[i]==')');
    //     if(s[i]=='('&&prer[i]>=prel[i]) ans[i]=1; 
    // }
    // for(int i=1;i<=n;i++) ans[i]+=ans[i-1];
    // while(m--){
    //     int l,r;
    //     cin>>l>>r;
    //     if(ans[r]-ans[l-1]) cout<<"Infinite\n";
    //     else cout<<"Finite\n";
    // }
    for(int i=1; i <= n; i ++) 
        if(s[i - 1] == '(')pre[i]=pre[i - 1] + 1;
        else pre[i] = pre[i - 1] - 1;
    while(m --) {
        int l, r; cin >> l >> r;
        if(pre[r] == pre[l - 1]) cout<<"Infinite\n";
        else cout<<"Finite\n";
    }
}

signed main() {
  int t = 1;
//   cin >> t;
  while(t --) solve();
}