#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
	cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for(int i = 0; i < h; i ++)
		cin >> s[i];
	vector<vector<int>> pre(h + 1, vector<int>(w + 1, 0)); 

	// 前缀和
	for(int i = 0; i < h; i ++) { 
		for(int j = 0; j < w; j ++) { 
			pre[i + 1][j + 1] = pre[i + 1][j] + (s[i][j] == '#' ? 1 : -1);
        }
    }

	long long cnt = 0;

	int nowmax = h * w;
	int offset = nowmax; 
	int sizea = 2 * nowmax + 1;

	for(int l = 1; l <= w; l ++){
		for(int r = l; r <= w; r ++){
			vector<int> lsum(h + 1); 
			for(int i = 1; i <= h; i ++) {
				lsum[i] = pre[i][r] - pre[i][l - 1]; 
            }
			vector<int> c(sizea, 0); 
			
			c[0 + offset] = 1; 
			int nowsum = 0; 

			for(int i = 1; i <= h; i ++){
				nowsum += lsum[i]; 

				cnt += c[nowsum + offset]; 
				c[nowsum + offset] ++; 
			}
		}
	}
	cout << cnt << endl;
}


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
1.   //// ///// 想到 可以 符号转化为 代数和！！！！！
2.
3.

About implementation skills:
1. 全局常量均大写字母，而局部变量，临时变量，和函数传递的参数使用小写字母。
2. 大模拟尽量遵循：怎么方便怎么写。
3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
4. 写成多个函数。

本题目思路 ：
因为 # 和 . 是 同样数量的 ，那么可以预处理成 +1 和 -1， 故只需要找到在一个矩形方阵内， 代数和是0 的
子矩阵的数量即可
就变成了一个二维前缀和的题目
先预处理 0,0到 i, j的所有矩阵的 代数和
枚举范围
然后求出美剧范围内每行每列的代数和
统计次数即可
*/
