#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();


double q1 = 100.0;
double q2 = 0.0;

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n; cin >> n;

	for(double hl,o;n--;){
		cin >> hl;
		o = q1;
		q1 = max(q1, q2 / hl * 100);
		q2 = max(q2, o / 100 * hl);
	}

	cout << q1 << endl;

	return 0;
}

void solve(){

}