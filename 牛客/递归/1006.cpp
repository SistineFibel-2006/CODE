#include <bits/stdc++.h>
using namespace std;

#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

#define endl '\n'

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

void solve(){}

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	std::cin >> n;
	int arr[n];
	for(int i = n - 1; i >= 0; i--)
		std::cin >> arr[i];
	u64 cnt = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(arr[j] > arr[i])
				cnt ++;
		} 
	}
	std::cout << cnt << endl;
	return 0;
}