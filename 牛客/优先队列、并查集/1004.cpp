#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();

const int N = 1e5 + 10;

struct node {
	int v;
	int s;
} a[N];

bool cmp(node a,node b)
{
    if(a.s!=b.s)
        return a.s > b.s;
    else
        return a.v > b.v;
}
/*
		遍历一遍，遍历过程中要维护最小的s，用优先队列维护v
*/

	priority_queue<int, vector<int>, greater<int>> q;
	i64 ans = 0, rans = 0;
	int r = 1e5 + 10;

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i].v >> a[i].s;
	}

	sort(a, a + n, cmp);


	for(int i = 0; i < n; i ++){
		// cout << "ok";
		if(a[i].s >= q.size() + 1){
			q.push(a[i].v);
			ans += a[i].v;
		}
		else {
			while(a[i].s <= q.size()) {				
				ans -= q.top();
				q.pop();
			}			
			q.push(a[i].v);
			ans += a[i].v;
		}

		// if(q.empty())
		// 	cout << "1" << endl;

		rans = max(ans, rans);
	}



		// while(!q.empty()){
		// 	cout << "q : "<<q.top() << endl;
		// 	q.pop();
		// }


	cout << rans;
	return 0;
}

void solve(){

}