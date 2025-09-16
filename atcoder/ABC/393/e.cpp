#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'
// #define max(x, y) x>y?x:y

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int > a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	int N = *max_element(begin(a), end(a));

	vector<int> cnt(N + 1), bei(N + 1), maxx(N + 1);

	for(auto c : a)
		cnt[c] ++;

	for(int i = 1; i <= N; i ++)
		for(int j = i; j <= N; j += i)
			bei[i] += cnt[j]; //计算每一位上的倍数数量

	for(auto i = 1; i <= N; i ++) {
		if(bei[i] < k)
			continue;
		for(int j = i; j <=	N; j += i)
			maxx[j] = std::max(maxx[j], i);
	}

	for(int i = 0; i < n; i ++)
		cout << maxx[a[i]] << '\n';

}

void solve(){
	

}