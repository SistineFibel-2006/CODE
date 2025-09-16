#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second

vector<pair<int, int> > ans(1e6 + 10, {0, 0});
void init() {
	ans[1].x = 0; ans[1].y = 0;
	int cnt = 0;int total=0;
	for(int i = 1; i <= 1e6; i += cnt) {
		cnt++;
		total+=cnt;
		for(int j=0;j<cnt;j++){
			if((i+j)>1e6){
				break;
			}
			ans[i+j].x=total+j;
			ans[i+j].y=cnt;
			
		}
		total+=cnt-1;

	}
}

void solve() {
	int n; cin >> n;
	int nowx = ans[n].x;
	int nowy = ans[n].y;
	int g = __gcd(nowx, nowy);
	nowx /= g, nowy /= g;
	cout << nowx << ' ' << nowy << endl;
}

signed main() {
	init();
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}