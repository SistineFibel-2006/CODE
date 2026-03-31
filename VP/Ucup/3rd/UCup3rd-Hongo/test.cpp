#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define rep(i,a,b) for(int i = (a); i < (b); i ++)
#define rrep(i,a,b) for(int i = (b); i-- > (a); )
#define all(a) a.begin(),a.end()
#define int long long
#define INT(...) int __VA_ARGS__; cin>>__VA_ARGS__

void solve() {
  int n;
  cin >> n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  sort(all(arr));
  int ans=0;

  for(int i=1;i<n;i++){
    ans+=(arr[i]/arr[i-1]);
  }
  ans+=(arr[0]/arr[n-1]);
  sort(arr.rbegin(),arr.rend());
  int ans2=0;
  for(int i=1;i<n;i++){
    ans2+=(arr[i]/arr[i-1]);
  }
  ans2+=(arr[0]/arr[n-1]);
  ans=min(ans,ans2);
  cout << ans << endl;
}

#undef int

int main() {
  int t = 1;
  //cin >> t;
  while(t --)
    solve();
}