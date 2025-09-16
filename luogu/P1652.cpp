// Problem: P1652 ��?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1652
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //MOD

using P = pair<double, double>;
using circle = pair<P, int>;

double dis(int x, int y, int a, int b){
	return sqrt(pow((x - a), 2) + pow((y - b), 2));
}

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  
	while(t --)
		solve();
}

void solve(){
	int n;
	cin >> n;
	circle y[n];
	for(int i = 0; i < n; i ++)
		cin >> y[i].first.first;
	for(int i = 0; i < n; i ++)
		cin >> y[i].first.second;
	for(int i = 0; i < n; i ++)
		cin >> y[i].second;
	P a, b;
	cin >> a.first >> a.second >> b.first >> b.second;
	int ain = -1, bin = -1;
	// int cnta = 0, cntb = 0;
	int ans = 0;
	for(int i = 0; i < n; i ++){
		// if(dis(a.first, a.second, y[i].first.first, y[i].first.second) < pow(y[i].second, 2))
		// 	ain = i, cnta ++;
		// if(dis(b.first, b.second, y[i].first.first, y[i].first.second) < pow(y[i].second, 2))
		// 	bin = i, cntb ++;
		if(
			(dis(a.first, a.second, y[i].first.first, y[i].first.second) < y[i].second) ^ 
			(dis(b.first, b.second, y[i].first.first, y[i].first.second) < y[i].second)
		)
		ans ++;
	}		
	// for(auto [x, y] : y){
	// 	debug(x.first);
	// 	debug(x.second);
	// 	debug(y);
	// 	cerr << endl;
	// }	
	cout << ans ;
	// if(ain == -1 && bin == -1)
	// 	cout << 0;
	// else if(ain != -1 && bin != -1){
	// 	if(ain == bin)
	// 		cout << 0;
	// 	else
	// 		cout << 2;
	// }
	// else
	// 	cout << 1;
}
