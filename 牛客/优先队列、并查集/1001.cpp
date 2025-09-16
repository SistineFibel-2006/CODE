#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();


priority_queue <int,vector<int>,greater<int>> t;

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;
	int a, b;

	for(int i = 0; i < n; i ++){
		cin >> a;
		t.push(a);
	}
	int sum = 0;
	for(int i = 0; i < n - 1; i ++) {
		a = t.top();
		t.pop();
		b = t.top();
		t.pop();
		t.push(a + b);


		sum += (a + b);

	}


	cout << sum;
	return 0;
}

void solve(){

}