#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, x, y;

	string a, b, c;
	cin >> n >> x >> y;
	cin >> a >> b >> c;

	// vector<int> a, b, c;
	int s = 0, d = 0, s1 = 0, s0 = 0;
	for(int i = 0; i < n; i ++){
			if(a[i] == '1' && b[i] == '0' && c[i] == '0')
				s ++;
			if(a[i] == '0' && b[i] == '1' && c[i] == '0')
				d ++;
			if(a[i] == '1' && b[i] == '1' && c[i] == '1')
				s1 ++;
			if(a[i] == '0' && b[i] == '0' && c[i] == '1')
				s0 ++;
		}
	int cnt = 0;
	if(y >= x * 2){
		cnt = (s + d + s1 + s0) * x;
		cout << cnt << endl;
		return 0;
	}


	if(s - (d + s1 + s0) > 0)
		cnt = (s - (d + s1 + s0)) * x + (d + s1 + s0) * y ;
	else if(d - (s + s1 + s0) > 0)
		cnt = (d - (s + s1 + s0)) * x + (s + s1 + s0) * y;
	else if(s1 - (d + s + s0) > 0)
		cnt = (s1 - (s + d + s0)) * x + (s + d + s0) * y;
	else if(s0 - (d + s + s1) > 0)
		cnt =  (s0 - (s + s1 + d)) * x + (s + s1 + d) * y;
	else
		cnt = x * ((s + d + s1 + s0) % 2) + y * ((s + d + s1 + s0) / 2);

	cout << cnt << endl;
}


void solve(){

}
