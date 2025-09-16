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
int n;
bool check(vector<int> a, vector<int> b){
    for(int i = 1; i <= n; i ++)
        if(a[i] != b[i])
            return false;
    return true;
}

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
    int k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), d(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++)
	    c[i]=i;
	for(int i = 1; i <= n; i ++)
	    cin >> a[i];
	for(int i = 1; i <= n; i ++)
	    cin >> b[i];
    int s = 0, t = 0; //没初始化 WA 一发呜呜
	for(int i = 1; i <= k; i ++){
		for(int j = 1; j <= n; j ++)
		    d[j]=c[a[j]];
		for(int j = 1; j <= n; j ++)
		    c[j]=d[j];
		if(check(c, b)) {
			s=i;
			break;
		}
	}
	for(int i = 1; i <= n; i ++)
	    c[i]=i;
	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= n; j ++)
		    d[a[j]]=c[j];
		for(int j = 1; j <= n; j ++)
		    c[j]=d[j];
		if(check(c, b)) {
			t=i;
			break;
		}
	}
	for(int i = 1; i <= n; i ++)
	    c[i]=i;
	if(check(c, b))
	    printf("NO");
	else if(s == 1 && t == 1 && k > 1)
	    printf("NO");
	else if((k - s) % 2 == 0 && s)
	    printf("YES");
	else if((k - t) % 2 == 0 && t)
	    printf("YES");
	else
	    printf("NO");
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
