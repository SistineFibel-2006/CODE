#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'
const int N = 1e5 + 1;
	vector<pair<int, int>> ran(N + 1);
	vector<bool> vis(N + 1, 0);
	vector<int> ans(N + 1);


bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    int len_a = a.second - a.first + 1;
    int len_b = b.second - b.first + 1;
    if (len_a == len_b) return a.first > b.first;
    return len_a < len_b;
}
// bool try1(int a, int b){
// 	if(b >= ran[a].first && b <= ran[a].second && !vis[b]) {
// 			ans[a] = b;
// 			vis[b] = 1;
// 			return 1;
// 	}
// 	return 0;
// }

// void huis(int a){
// 		if(a > 1) {
// 			int j = ans[a - 1];
// 			vis[j] = 0;
// 			ans[a - 1] = -1;
// 		}
// }

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;

	for(int i = 0; i < n; i ++)
		cin >> ran[i].first >> ran[i].second;

	sort(ran.begin(), ran.begin() + n ,cmp);

	auto try1 = [&](int a, int b) -> bool {
		if(b >= ran[a].first && b <= ran[a].second && !vis[b]) {
			ans[a] = b;
			vis[b] = 1;
			return 1;
		}
		return 0;
	};
	auto huis = [&](int a) -> void {
		if(a > 1) {
			int j = ans[a - 1];
			vis[j] = 0;
			ans[a - 1] = -1;
		}
	};
	int i = 0;
	while(i <= n){
		bool can = 0;
		for(int j = 1; j <= n; j ++){
			if(try1(i , j)) {
				can = 1;
				if(++i == n){
					for(int q = 0; q < n; q ++)
						cout << ans[q] << " ";
					cout << endl;
					return 0;
				}
			}
		}
		if(!can){
			huis(i);
			--i;
		}
	}
}

void solve(){

}