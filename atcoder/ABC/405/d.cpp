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
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char arr[] = {'^', 'v', '<', '>'};

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
	queue<pair<int, int>> q;
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	for(auto &c : g)
		cin >> c;
	
	vector<vector<int>> vis(h, vector<int> (w, -1));
	for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if (g[i][j] == 'E') {
                vis[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

	while(!q.empty()){
		auto [i, j] = q.front();q.pop();
		for(int k = 0; k <= 3; k ++){
			int ii = i + dx[k];
			int jj = j + dy[k];
			if(ii >= 0 && ii < h && jj >= 0 && jj < w)
				if(g[ii][jj] == '.' && vis[ii][jj] == -1){
					vis[ii][jj] = vis[i][j] + 1;
					q.emplace(ii,jj);
				}
		}
	}

	vector<string> ans = g;
	for(int i = 0; i < h; i ++)
		for(int j = 0; j < w; j ++)
			if(g[i][j] == '.'){
				for(int k = 0; k <= 3; k ++){
					int ii = i + dx[k];
					int jj = j + dy[k];
					if(ii >= 0 && ii < h && jj >= 0 && jj < w)	
						if(vis[ii][jj] == vis[i][j] - 1){
							ans[i][j] = arr[k];
							break;
						}				
				}
			}

	for(auto c : ans)
		cout << c << endl;
}
//test
/*
?
// ? (?????) ?
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