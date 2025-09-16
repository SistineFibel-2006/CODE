#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数


signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}


vector<vector<int >> e(58, vector<int> (58));
vector<int > P(200, 0);

void solve(){
  int p; cin >> p;
  for(int i = 0; i <= 57; i ++)
    for(int j = 0; j <= 57; j ++)
      e[i][j] = INF;
  for(int i = 0; i < p; i ++) {
    char a, b; int v, x, y;
    cin >> a >> b >> v;
    x = a - 'A'; y = b - 'A';
    if(a >= 'A' && a <= 'Y') P[x] = 1;
    if(b >= 'A' && b <= 'Y') P[y] = 1;
    e[x][y] = min(e[x][y], v);
    e[y][x] = min(e[y][x], e[x][y]);    
  }
  //floyd
  for(int k = 0; k < 58; k ++)
    for(int i = 0; i < 58; i ++)
      for(int j = 0; j < 58; j ++){
        if(e[i][j] > e[i][k] + e[k][j])
          e[i][j] = e[i][k] + e[k][j];
      }
  int ans = INF, id;
  for(int i = 0; i < 25; i ++)
    if(P[i] == 1 && e[i][25] < ans)
      id = i, ans = e[i][25];

  char rid = id + 'A';
  cout << rid << ' ' << ans;
}
//test
/*
ඞ
// ٩ (◕‿◕�?) ۶
*/

/*
What's wrong with my code?
1. 小数据？特殊数据？如 n = 1?
2. 最小值，最大值取多少？是否会溢出？
3. 初始值有没有赋值？有没有建树？
4. 数组大小？是否越界？
5. 思考暴力的时候，考虑是否可能是多个连续段？或者是个数不确定无法暴力？是否可以分治暴力？
6. 进行详细的分类讨论?
7. 选择的区间是否可以为空？

Trick:
1.
2.
3.

About implementation skills:
1. 全局常量均大写字母，而局部变量，临时变量，和函数传递的参数使用小写字母。
2. 大模拟尽量遵循：怎么方便怎么写。
3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
4. 写成多个函数。
*/

