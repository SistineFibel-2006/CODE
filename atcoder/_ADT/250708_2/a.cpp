#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, m; cin >> n >> m;
  string s;
  cin >> s;
  int cnt = 0;
  for(auto c : s)
    if(c == '@')
      cnt ++;
  cout << (cnt + m <= n ? cnt + 1 : cnt);
}
