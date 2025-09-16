#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const int N = 2E5 + 10;

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, q;
	cin >> n >> q;
	i64 cnt = 0;
	map<pair<int, int>, int> p;
	
	int x, y;
	while(q --){
		cin >> x >> y;
		if(x == y){
			cnt ++;
			continue;
		}
		if(x < y)
			swap(x, y);
		p[{x, y}] += 1;
	}
	for(auto i : p)
		cnt += i.second - 1;
	cout << cnt;

}

void solve(){

}

/*
6 2
4 1 
5 1 
6 6 1
5 3
5 1 1
1 4 1
6 4
4 2
5 6



*/