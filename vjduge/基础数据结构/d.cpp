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
	int n, m;
	cin >> n >> m;
	// vector<int > a(n);
	// for(int i = 0; i < n; i ++)	
	// 	cin >> a[i];

	priority_queue <pair<int, int >, vector<pair<int, int >>, greater<pair<int, int>> > q;

	// q.push({0, 0}); //会造成一个虚空的最小值，因此不选用

	for(int i = 1, t; i <= n; i ++) {
		//大于m个的时候让他滚
		while(!q.empty() && q.top().second <= (i - m - 1))
			q.pop();	

		int temp = 0;
		if(i != 1)
			temp = q.top().first; //记录当前最大值，以防现在的新数字更新了最值
		// cout << "temp :" << temp << endl;
		cin >> t;
		q.push({t, i});
		// cout << "ok" << endl;
		//此外就是输出队首
		// cout << "top :" << q.top().first << q.top().second<<endl;
		if(q.top().second == i)
			cout << temp << '\n';
		else
			cout << q.top().first << endl;

	}





}

void solve(){

}
