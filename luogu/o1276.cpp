#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'
void solve();

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, t;
	cin >> n >> t;
	int arr[n + 1] = {0};
	int a, l, r;
	int cnt1 = 0, cnt2 = 0;
	while(t--){
		cin >> a >> l >> r;
		if(a == 0)
			for(int i = l; i <= r; i ++){
				if(arr[i] == 1)
					cnt1++;
				arr[i] = 2;
			}
		else{
			for(int i = l; i <= r; i ++){
				if(arr[i] == 2)
					cnt2++,arr[i] = 1;
			}
		}
	}
	cout << cnt2 - cnt1 << '\n' << cnt1 << endl;
	return 0;
}

void solve(){

}