// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'


// signed main (){ 
// 	std::ios::sync_with_stdio(false);std::cin.tie(0);
// 	int t;
// 	cin >> t;
// 	while(t --)
// 		solve();
// }

// void solve(){
// 	int n;
// 	cin >> n;
// 	vector<int > a(n);
// 	for(auto &c : a)
// 		cin >> c;

// 	i64 f[n][n] = {0};
// 	for(int i = 0; i < n; i ++)
// 		f[i][i] == abs(a[i]);

// 	for(int j = 2; j <= n; j ++) 
// 		for(int i = 0; i <= n - j; i ++){
// 			int x = i + j - 1;
// 			i64 l = f[i + 1][x] + abs(a[i]);
// 			i64 r = f[i][x + 1] + abs(a[x]);
// 			f[i][j] = max(l, r);
// 		}

// 	cout << f[0][n - 1] << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'


// signed main (){ 
// 	std::ios::sync_with_stdio(false);std::cin.tie(0);
// 	int t;
// 	cin >> t;
// 	while(t --)
// 		solve();
// }

// void solve(){
// 	int n;
// 	cin >> n;
// 	vector <int > a(n);
// 	for(auto &c : a)
// 		cin >> c;

// 	priority_queue <pair<int, int>> p;
// 	for(int i = 0; i < n; i ++)
// 		p.push({abs(a[i]), i});

// 	vector<bool> vis(n, 0);
// 	i64	coin = 0;

// 	int l = 0, r = n - 1; //双指针标记可用区域

// 	while(!p.empty()) {
// 		auto now = p.top();
// 		p.pop();

// 		int val = now.first;
// 		int pos = now.second;
// 		if(vis[pos])
// 			continue;

// 		coin += val;
// 		vis[pos] = true;

// 		if(a[pos] < 0) {
// 			// for(int i = pos; i <= r; i ++)
// 			// 	vis[i] = true;
// 			// r = pos - 1;
// 			for(int i = pos; i < n; i ++)
// 				vis[i] = true;
// 		}
// 		else {
// 			// for(int i = l; i <= pos; i ++)
// 			// 	vis[i] = true;
// 			// l = pos + 1;
// 			for(int i = 0; i <= pos ; i ++)
// 				vis[i] = true;
// 		}
// 	}

// 	cout << coin << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'


// signed main (){ 
	// std::ios::sync_with_stdio(false);std::cin.tie(0);
	// int t;
	// cin >> t;
	// while(t --)
	// 	solve();
// }

// void solve(){
// 	int n;
// 	cin >> n;
// 	vector<i64> a(n);
// 	for(auto &c : a) 
// 		cin >> c;

// 	vector<i64> fl(n), fr(n);

// 	fl[0] = max(0LL, a[0]);
// 	for(int i = 1; i < n; i ++)
// 		fl[i] = max(fl[i - 1] + a[i], 0LL);

// 	fr[n - 1] = max(0LL, a[n - 1]);
// 	for(int i = n - 2; i >= n; i --)
// 		fr[i] = max(fr[i + 1] + a[i], 0LL);

// 	i64 coin = 0;

// 	for(int i = 0; i < n; i ++)
// 		coin = max(coin, fl[i] + fr[i] - abs(a[i]));

// 	cout << coin << endl;
// }


#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

i64 mcoin(vector<i64> & a, int l, int r);

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t --)
		solve();
}

void solve(){
    int n;
    cin >> n;
    vector<i64 > a(n);
    for (auto &c : a) 
    	cin >> c;
        
    cout << mcoin(a, 0, n - 1) << endl;
}

i64 mcoin(vector<i64> & a, int l, int r) {
    if(l == r)
    	return max(0LL, a[l]);
    int m = (l + r) / 2;
    i64 lm = mcoin(a, l, m);
    i64 rm = mcoin(a, m + 1, r);

    i64 ls = 0, rs = 0, ml = 0, mr = 0;

    for(int i = m; i >= l; i --) {
    	ls += a[i];
    	ml = max(ml, ls);
    }

    for(int i = m + 1; i <= r; i ++) {
    	rs += a[i];
    	mr = max(mr, rs);
    }

    return max({lm, rm, ml + mr});		
}