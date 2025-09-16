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
	int n, m;
    cin >> n >> m;
    vector<pair<int, int > > part, notp;
    vector<pair<int, int > > ans(m);
    int p = 0;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        if(b == 1)
            part.push_back({a, i});
        else
            notp.push_back({a, i}), p ++;
    }
    if(part.size() >= n) {puts("-1"); return;}
    sort(all(part)); sort(all(notp));
    for(int i = 1; i <= part.size(); i ++)
        ans[part[i - 1].second] = {i, i + 1};
    int s = 0, cnt = 1;
    for(int i = 0; i < notp.size(); i ++){
        if(notp[i].first >= part[s + 1].first) {
            ans[notp[i].second] = {cnt, s + 3};
            cnt --;
            if(cnt == 0){
                cnt = s + 2;
                s ++;
            }
        }
        else {puts("-1"); return;}
    }

    for(auto c : ans)
        cout << c.first << ' ' << c.second << endl;
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