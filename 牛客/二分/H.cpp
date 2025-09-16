#include <bits/stdc++.h>
using namespace std;


using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

#define endl '\n'

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

void solve(){}

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, m;
	cin >> n >> m;
	int arr[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	int b, l, r;
	int cnt = 0;
	while(m--){
		cnt ++;
		cin >> b >> l >> r;
		for(int i = l; i <= r; i++){
			arr[i] -= b;
			if(arr[i] < 0){
				cout << cnt << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}

//TLE