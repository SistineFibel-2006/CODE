#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve();

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while(t --)
    solve();
}
bool e[110][110][2] = {false};
void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  int turn = 0;
  vector<int > err;
  bool f = 0, score = 0;
  int hz = 0;
  int A = 0, B = 0;
  for(int now, x, y, x1, y1, i = 1; i <= s; i ++) {
    f = 0, score = 0;
    cin >> now >> x >> y >> x1 >> y1;
    if(x1 < x || y1 < y){
      swap(x, x1); swap(y, y1);
    }
    if(x != x1)
      hz = 0;
    else
      hz = 1;
    if(i == 1 && now == 1){
      err.push_back(i);
      continue;
    }
    if(turn != now) {
      err.push_back(i);
      continue;
    }
      
    // if(i == 9) cerr << turn << "\n\n";
    
    // if(e[x][y][hz])
    //   f = 1;
    if(x != x1 && y != y1) {
      err.push_back(i);
      continue;
    }
    if(e[x][y][hz]) {
      err.push_back(i);
      continue;
    }
    e[x][y][hz] = 1;
    // if(i == 8) cerr << now << "\n\n";
    if(hz == 1) {
      if(x - 1 >= 1 && y + 1 <= m)
        if(e[x][y][1]&&e[x - 1][y][0]&&e[x - 1][y][1]&&e[x - 1][y + 1][0]) {
           if(now == 0)
             A ++;
           else
             B ++;
           score = 1;

           // cerr << i << endl;
        }
      if(x + 1 <= n && y + 1 <= m)
        if(e[x][y][1]&&e[x][y][0]&&e[x][y + 1][0]&&e[x + 1][y][0]) {
          if(now == 0)
            A ++;
          else
            B ++;
          score = 1;

          // cerr << i << endl;
        }
    }
    else {
      if(x + 1 <= n && y + 1 <= m)
        if(e[x][y][0]&&e[x][y][1]&&e[x + 1][y][1]&&e[x][y + 1][0]){
          if(now == 0)
            A ++;
          else
            B ++;
          score = 1;

          // cerr << i << endl;
        }
      if(x + 1 <= n && y - 1 >= 1)
        if(e[x][y][0]&&e[x][y - 1][1]&&e[x + 1][y - 1][1]&&e[x][y - 1][0]){
          if(now == 0)
            A ++;
          else
            B ++;
          score = 1;

          // cerr << i << endl;
        }
    }
    if(f == 1)
      err.push_back(i);
    if(score != 1)
      turn = (turn == 1) ? 0 : 1;
  }
  // for(auto c : err)
  //   cout << c << ' ';
  // cout << endl;
  // cout << A << ' ' << B;
  if(err.size() == 0)
    cout << "-1\n";
  else {
    for(int i = 0; i < err.size() - 1; i ++)
      cout << err[i] << ' ';
    cout << err[err.size() - 1];
    cout << endl;
  }
  int ans = (A > B) ? 0 : 1;
  cout << ans << ' ';
  if(ans == 0)
    cout << A;
  else
    cout << B;
}
