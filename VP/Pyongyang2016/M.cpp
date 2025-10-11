#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define int long long

void sol() {
  int n;
  cin>>n;
  cout << n*n + n*4 + 8 << ' ' << n*n - n*4 + 8 << '\n';
  // int s=n*n*n*n+64;
  // if(n%2){
  //   cout<<5<<" "<<s/5<<"\n";
  // }
  // else{
  //   cout<<2<<" "<<s/2<<"\n";
  // }
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    	sol();
}