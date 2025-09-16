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

void solve(){
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> a[i][j];

    vector<int> p(h + w - 1);
    for (int i = 0; i < h + w - 1; ++i)
        cin >> p[i];

    if (h > w) {
        vector<vector<int>> b(w, vector<int>(h));
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                b[j][i] = a[i][j];
        swap(h, w);
        a = move(b);
    }

    auto ok = [&](int x) -> bool {
        vector<int> dp(w, -1);

        int coins = x + a[0][0];
        if (coins < p[0]) return false;
        dp[0] = coins - p[0];

        for (int j = 1; j < w; ++j) {
            if (dp[j - 1] == -1) continue;
            int cur = dp[j - 1] + a[0][j];
            if (cur >= p[j]) dp[j] = cur - p[j];
        }

        for (int i = 1; i < h; ++i) {
            if (dp[0] != -1) {
                int cur = dp[0] + a[i][0];
                dp[0] = (cur >= p[i]) ? cur - p[i] : -1;
            }
            for (int j = 1; j < w; ++j) {
                int pre = max(dp[j], dp[j - 1]);
                if (pre == -1) {
                    dp[j] = -1;
                    continue;
                }
                int cur = pre + a[i][j];
                dp[j] = (cur >= p[i + j]) ? cur - p[i + j] : -1;
            }
        }
        return dp[w - 1] != -1;
    };

    int l = 0, r = 4e14, ans = r;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ok(m)) {
            ans = m;
            r = m - 1;
        } 
        else 
            l = m + 1;
        
    }
    cout << ans << '\n';
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
