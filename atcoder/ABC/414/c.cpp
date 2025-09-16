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


vector<int> toBase(int n, int A) {
    vector<int> d;
    if (n == 0) {
        d.push_back(0);
        return d;
    }
    while (n > 0) {
        d.push_back(n % A);
        n /= A;
    }
    reverse(d.begin(), d.end());
    return d;
}

bool isPal(vector<int>& d) {
    int l = 0, r = d.size() - 1;
    while (l < r) {
        if (d[l] != d[r]) return false;
        l++;
        r--;
    }
    return true;
}

vector<int> genPals(int N) {
    vector<int> x;
    for (int len = 1; len <= 15; ++len) {
        int mid = (len + 1) / 2;
        int l = pow(10, mid - 1);
        int end = pow(10, mid);
        for (int p = l; p < end; ++p) {
            string s = to_string(p);
            string pal = s.substr(0, s.length() - 1) + string(s.rbegin(), s.rend());
            int num = stoll(pal);
            if (num <= N) x.push_back(num);
            else break;
        }
        mid = len / 2;
        l = pow(10, mid - 1);
        end = pow(10, mid);
        for (int p = l; p < end; ++p) {
            string s = to_string(p);
            string pal = s + string(s.rbegin(), s.rend());
            int num = stoll(pal);
            if (num <= N) x.push_back(num);
            else break;
        }
    }
    for (int i = 1; i <= 9; ++i) {
        if (i <= N) x.push_back(i);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    return x;
}

void solve() {
    int a, n;
    cin >> a >> n;
    vector<int> x = genPals(n);
    int sum = 0;
    for (auto c : x) {
        vector<int> d = toBase(c, a);
        if (isPal(d)) sum += c;
    }
    cout << sum << endl;
    return;
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

