#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
struct po{
	int x0,x1,x2;
}ans[N];

bool cmp(po a, po b){
	if(a.x1 != b.x1)
		return a.x1 < b.x1;
	else if(a.x0 != b.x0)
		return a.x0 < b.x0;
	else
		return a.x2 < b.x2;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	vector<int> y0, y1, y2;
	int a = 0, b = 0, c = 0;
	while(n --){
		int x, y;
		cin >> x >> y;
		if(y == 1)
			y1.push_back(x), c++;
		else if(y == 2)
			y2.push_back(x), b++;
		else
			y0.push_back(x), a++;
	}
	sort(y1.begin(), y1.end());
	sort(y2.begin(), y2.end());
	sort(y0.begin(), y0.end());
	int cnt = 0;
	for(int i = 0; i < sizeof a; i ++)
		for(int j = 0; j < sizeof b; j ++){
			if((abs(y0[i]) + abs(y2[j])) % 2 == 1)
				continue;
			int x = (y0[i] + y2[j]) / 2;
			if(find(y1.begin(), y1.end(), x) == y1.end())
				continue;
			int p = *find(y1.begin(), y1.end(), x);
			
			if(y0[i] == ans[cnt - 1].x0 && y2[j] == ans[cnt - 1].x2)
				continue;
			
			ans[cnt].x0 = y0[i];
			ans[cnt].x2 = y2[j];
			ans[cnt].x1 = p;
			cnt ++;
		}
	if(cnt == 0){
		cout << -1;
		return 0;
	}
	sort(ans, ans + cnt, cmp);

	for(int i = 0; i < cnt; i ++){
		if(i != 0 && ans[i].x0 == ans[i - 1].x0 && ans[i].x2 == ans[i - 1].x2)
			continue;
		printf("[%d, 0] [%d, 1] [%d, 2]\n",ans[i].x0,ans[i].x1,ans[i].x2);
	}

    return 0;
}
