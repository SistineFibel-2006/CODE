#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
#define endl '\n'

const i64 INF = 0x3f3f3f3f;
const i64 MOD = 1e9; //模数


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cntall = 0;
    int cntb = 0;
    for(int i = 0; i < s.length(); i ++){
        if(s[i] == 'a' && cntall < a + b){
            cout << "Yes\n";
            cntall ++;
        }
        else if(s[i] == 'b' && cntall < a + b && cntb < b){
            cout << "Yes\n";
            cntall ++;
            cntb ++;
        }
        else{  
            cout << "No\n";
        }
    }{}
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
1. 全局变量多用长变量名，而局部变量，临时变量，和函数传递的参数使用短变量名。
2. 大模拟尽量遵循：怎么方便怎么写。
3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
4. 写成多个函数。
*/