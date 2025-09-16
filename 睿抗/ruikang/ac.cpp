#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve();

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while(t --)
    solve();
}

void solve() {
  int m, d, c;
  cin >> m >> d >> c;
  int a = m*100 + d;
  if(a > 711) {
    cout << "Too late!\n";
    return;
  }
  else if(a > 620) {
    if(c < 2000){
      cout << "Need more!\n";
      return;
    }
    else if(c == 2000) {
      cout << "Ok!\n";
      return;
    }
    else {
      cout << "^_^\n";
      return;
    }
  }
  else {
    if(c < 1800){
      cout << "Need more!\n";
      return;
    }
    else if(c == 1800) {
      cout << "Ok!\n";
      return;
    }
    else {
      cout << "^_^\n";
      return;
    }
    
  }
}
