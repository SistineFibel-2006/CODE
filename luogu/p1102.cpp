#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'


signed solve1 (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);

	int n, c, x, ans = 0;
	cin >> n >> c;

	vector<int > a(n, 0); // a.pushback(x);

	for(int i = 0; i < n; i++)
		cin >> a[i];	//读入数组数据

	//lambda函数
	int l = 0, r = n - 1;
	int mid;
	auto find = [&](int x) -> bool{ // find (x,l,r,a)
		while(l <= r){
			mid = (l + r) / 2;
			if(a[mid] > x)
				r = mid;
			else if(a[mid] < x)
				l = mid;
			else
				return true;
		}
		return false;
	};

	sort(a.begin(),a.end());
	// a - b = c  => c + b = a
	for(int i = 0; i < n - 1; i ++) {
		x = a[i] + c;
		if(find(x))
			ans ++;
	}

	cout << ans << endl;

	return 0;
}


//#define int long long

map<int, int > a; // a = b + c => a - c = b

signed main() {

	int n, c;
	cin >> n >> c;

	vector<int > arr(n, 0), b(n, 0);

	for(int i = 0; i < n; i ++) {
		cin >> arr[i];
		a[arr[i]] ++;
		b[i] = arr[i] - c;
	}

	i64 ans = 0;

	for(int i = 0; i < n; i ++)
		ans += a[b[i]];

	cout << ans ;

}

vector<int> a(n);

lower_bound(a,a + n,c) - a;
upper_bound(a,a + n,c) - a; // logn


//二分查找

//二分答案












































