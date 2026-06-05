#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long
using vi = vector<int>;
#define sz(x) (int)size(x)
#define rep(i, a, b) for(int i = (a); i < (b); i ++)

const int inf = LLONG_MAX / 4;
void solve() {
    int x;
    cin>>x;
    int n=sqrt(x);
    int s=inf;
    for(int ans=0;ans<=min(360ll,(int)sqrt(n));ans++){
        for(int a=max(0ll,n-ans);a<=n;a++){
            int b=a+ans;
            if(a*b>x) break;
            int c=x-a*b;
            if(max({ans,abs(b-c),abs(a-c)})<s) s=max({ans,abs(b-c),abs(a-c)});
        }
    }
    cout<<s<<"\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t --) solve();
}