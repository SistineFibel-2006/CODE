
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
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}
int a[15][15], ans = 0;
int n, m;
int cnt[15][15];

void count_ans(int x,int y,int s){
	if(x==n) {
		ans=max(ans,s);
		return;
	}
	if(!a[x-1][y-1]&&!a[x-1][y]&&!a[x-1][y+1]&&!a[x+1][y]&&!a[x][y]){
		a[x-1][y-1]=a[x-1][y]=a[x-1][y+1]=a[x+1][y]=a[x][y]=1;
		if(s+1>=cnt[x][y]){
			cnt[x][y]=max(cnt[x][y],s);
			if(y==m-1) count_ans(x+1,2,s+1);
			else count_ans(x,y+1,s+1);
		}
		a[x-1][y-1]=a[x-1][y]=a[x-1][y+1]=a[x+1][y]=a[x][y]=0;
	}
	if(!a[x+1][y-1]&&!a[x+1][y]&&!a[x+1][y+1]&&!a[x-1][y]&&!a[x][y]){
		a[x+1][y-1]=a[x+1][y]=a[x+1][y+1]=a[x-1][y]=a[x][y]=1;
		if(s+1>=cnt[x][y]){
			cnt[x][y]=max(cnt[x][y],s);
			if(y==m-1) count_ans(x+1,2,s+1);
			else count_ans(x,y+1,s+1);
		}
		a[x+1][y-1]=a[x+1][y]=a[x+1][y+1]=a[x-1][y]=a[x][y]=0;
	}
	if(!a[x-1][y-1]&&!a[x][y-1]&&!a[x][y+1]&&!a[x+1][y-1]&&!a[x][y]){
		a[x-1][y-1]=a[x][y-1]=a[x][y+1]=a[x+1][y-1]=a[x][y]=1;
		if(s+1>=cnt[x][y]){
			cnt[x][y]=max(cnt[x][y],s);
			if(y==m-1) count_ans(x+1,2,s+1);
			else count_ans(x,y+1,s+1);
		}
		a[x-1][y-1]=a[x][y-1]=a[x][y+1]=a[x+1][y-1]=a[x][y]=0;
	}
	if(!a[x-1][y+1]&&!a[x][y-1]&&!a[x][y+1]&&!a[x+1][y+1]&&!a[x][y]) {
		a[x-1][y+1]=a[x][y-1]=a[x][y+1]=a[x+1][y+1]=a[x][y]=1;
		if(s+1>=cnt[x][y]) {
			if(y==m-1) count_ans(x+1,2,s+1);
			else count_ans(x,y+1,s+1);
			cnt[x][y]=max(cnt[x][y],s);
		}
		a[x-1][y+1]=a[x][y-1]=a[x][y+1]=a[x+1][y+1]=a[x][y]=0;
	}
	if(y==m-1) 
		count_ans(x+1,2,s);
	else 
		count_ans(x,y+1,s);
}


void solve(){
  cin >> n >> m;
	// if(m > n)
	// 	swap(m, n);
  if(n < 3 || m < 3) {
  	cout << 0;
  	return;
  }
  count_ans(2, 2, 0);
	cout << ans;
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
