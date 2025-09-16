#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子

#define endl '\n'
void solve();



signed main(){	std::ios::sync_with_stdio(false);std::cin.tie(0);
	
	int t;
	cin >> t;
	while(t --)
		solve();

}


void solve(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	auto diss = [&](int x, int y) -> double{
		double d = 0;
		double sq = sqrt(2.00);
		for(int i = 1; i <= x + y; i ++) //算正常对角线
			d += (i * sq);
		d -= (y * sq);
		for(int i = 0; i < x + y; i ++)  //算非正常对角线
			d += sqrt( ((double)i * i) + ((double)(i + 1) * (i + 1)) );
		return d;
	};


	printf("%.3f\n",fabs(diss(x1,y1) - diss(x2, y2)));
}

