#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; i ++)
#define rrep(i,a,b) for(int i = (b); i --> a; )
#define fi first
#define se second
using ll = long long;
using I = int;
using Int = long long;


#define int long long

auto solve = []() -> void {
  int h, w, s; cin >> h >> w >> s;
  int ans = h + w; 
  for(int l = 1, r = 1; l <= s; l = r + 1) {
    r = s/(s/l);
    ans = min(ans, ((h + r - 1)/r) + ((w + s/l - 1)/(s/l)) - 2);
  }
  cout << ans << '\n';


  // double tot = h*w/s;

  // if(h*w<=s){
  //   cout << 0 << '\n';
  //   return;
  // }

  // // cout << tot << endl;
  // ll sq = sqrt(tot);
  // if ((sq*sq)==tot) {
  //   cout << (sq-1)*2 << '\n';
  // } else {
  //   cout << sq*2+1 << '\n';
  // }

  // cerr << sq << endl;
  // ll ans = sq;
  // for(int i =0 ; i<1000000000;i++){
  //   if(sq*(sq-i)<tot){
  //     ans += (sq+i);
  //     break;
  //   }
  // }
  // cout << ans << '\n';
  // double y=sqrt(s*w/h),x=sqrt(h*s/w);
  // cout<<x<<" "<<y<<" ";
  // int ans=min((int)(w/y)*2,(int)(h/x)*2);
  // cout<<ans<<"\n";

};

signed main() {
  int t = 1;
  cin >> t;
  while(t --) solve();
}