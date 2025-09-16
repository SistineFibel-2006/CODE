#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'
signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){ 
    string a, b;
    cin >> a >> b;
    const int N = a.length();
    sort(all(a)); sort(all(b));
    reverse(all(b)); // 翻转取最大
    
    deque<char> as, bs;
    for(int i = 0; i < (N + 1) / 2; i++)
        as.push_back(a[i]);
    for(int i = 0; i < N / 2; i++)
        bs.push_back(b[i]);
    
    string l = "", r = "";
    for(int i = 0; i < N; i++) {
        if(i % 2) {
            if(!bs.empty()) {
                if(as.empty() || bs.front() > as.front()) {
                    l += bs.front();
                    bs.pop_front();
                } 
                else {
                    r += bs.back();
                    bs.pop_back();
                }
            }
        } 
        else { 
            if(!as.empty()) {
                if(bs.empty() || as.front() < bs.front()) {
                    l += as.front();
                    as.pop_front();
                } 
                else {
                    r += as.back();
                    as.pop_back();
                }
            }
        }
    }
    reverse(all(r));
    cout << l + r << endl;
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