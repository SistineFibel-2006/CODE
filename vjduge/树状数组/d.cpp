#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const int N = 1000100;
i64 sum1[N], sum2[N];
i64 n;

void add(i64 p, i64 x){
    for(int i = p; i <= n; i += i & -i)
        sum1[i] += x, sum2[i] += x * p;
}
void range_add(i64 l, i64 r, i64 x){
    add(l, x), add(r + 1, -x);
}
i64 ask(i64 p){
    i64 res = 0;
    for(int i = p; i; i -= i & -i)
        res += (p + 1) * sum1[i] - sum2[i];
    return res;
}
i64 range_ask(i64 l, i64 r){
    return ask(r) - ask(l - 1);
}

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	i64 f;
	cin >> n >> f;

	vector<i64 > arr(n + 1);
	for(int i =1; i <= n; i ++) {
		cin >> arr[i];
		add(i, arr[i] - arr[i - 1]);
	}

	while(f --)
		solve();
}

void solve(){
	int a;
	cin >> a;

	i64 l, r, k;
	if(a == 1) {
		cin >> l >> r >> k;
		range_add(l, r, k);
	}
	else if(a == 2) {
		cin >> k;
		range_add(1, 1, k);
	}
	else if(a == 3) {
		cin >> k;
		range_add(1, 1, -k);		
	}
	else if(a == 4) {
		cin >> l >> r;
		cout << range_ask(l, r) << endl;
	}
	else {
		cout << range_ask(1, 1) << endl;
	} 
}