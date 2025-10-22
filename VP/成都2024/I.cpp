#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
const ll LINF = LLONG_MAX / 4;
#define rep(i,a,b) for(ll i = a; i < b; i ++)
#define all(a) a.begin(),a.end()
#define sz(a) size(a)
bool chmax(auto&a, auto b) {return a < b ? a = b, 1 : 0;}
bool chmin(auto&a, auto b) {return a > b ? a = b, 1 : 0;}
#define fi first 
#define se second 
#define eb emplace_back
#define pb push_back

ll ggcd(ll x, ll y) {
  if(x == 0) return y;
  if(y == 0) return x;
  return std::gcd(x, y);
}

struct Segtree {
  ll size = 1;
  vector<ll> data;
  Segtree(ll n) {
    while(size < n) size *= 2;
    data.assign(size*2, 0);
  }
  void update(ll at) {
    while(at /= 2) data[at] = ggcd(data[at * 2], data[at * 2 + 1]);
  }
  void set(ll at, ll val) {
    at += size;
    data[at] = val;
    update(at);
  }
  ll get(ll l, ll r) {
    ll Rans = 0, Lans = 0;
    l += size;
    r += size;
    for(;l<=r;l/=2,r/=2) {
      if(l & 1) Lans = ggcd(Lans, data[l ++]);
      if(!(r & 1)) Rans = ggcd(Rans, data[ r --]);
    }
    return ggcd(Rans,Lans);
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n + 1); rep(i,1,n + 1) cin >> a[i];
  Segtree st(n);
  rep(i, 1, n) {
    if(a[i] > a[i + 1]) st.set(i - 1, i);
    else st.set(i - 1, 0);
  }
  st.set(n-1, 0);

  auto prt = [&](){
    ll ans = st.get(0, n - 1);
    if(ans == 0) {
      cout << n << endl;
      return;
    }
    // cerr << "ans : " << ans << '\n';
    // cerr << "data : " ; 
    // for(auto c : st.data) {
    //   cerr << c << ' ';
    // }
    // cerr << endl;
    ll cnt=0;
    for(int i=1;i*i<=ans;i++) cnt+=(ans%i==0);
    cout<<cnt*2-((int)sqrt(ans)*(int)sqrt(ans)==ans)<<"\n";
  };

  prt();

  rep(_,0,q) {
    int at,v; cin >> at >> v;
    a[at] = v;
    if(at == n) {
      if(a[at - 1] > a[at])
        st.set(at - 1 - 1, at - 1);
      else
        st.set(at - 1 - 1, 0);
    } else if(at == 1) {
      if(a[at] > a[at + 1])
        st.set(at - 1, at);
      else
        st.set(at - 1, 0);
    } else {
      if(a[at - 1] > a[at])
        st.set(at - 1 - 1, at - 1);
      else
        st.set(at - 1 - 1, 0);
      if(a[at] > a[at + 1])
        st.set(at - 1, at);
      else
        st.set(at - 1, 0);      
    }
    prt();
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1; 
  cin >> t;
  while(t --)  {
    solve();
  }
}