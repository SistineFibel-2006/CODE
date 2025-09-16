#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'



signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	int n, r;
	cin >> n >> r;
	// auto zuhe = [&](int n,int r, int s) -> int{

	// };
	queue<pair<vector<int>, int>> qu; // vector是现在的排列，pair的second是现在vector指向的下一个数
	qu.push({{ }, 1});


	while(!qu.empty()){
		auto temp = qu.front();
		qu.pop();
		vector<int> now = temp.first;
		int nextt = temp.second;

		if(now.size() == r){ //检测到满足r个数就输出
			for(auto c : now)
				cout << setw(3) << c;
			cout << '\n';
			continue;
		}

		for(int i = nextt; i <= n; i ++){
			auto next = now;
			next.push_back(i);
			qu.push({next, i + 1});
		}

	}


}

void solve(){

}