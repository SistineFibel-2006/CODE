#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

i64 fq(i64 x){
	if(x == 0 || x == 1)
		return x;
	i64 l = 1;
	i64 h = x;
	i64 ans = 0;
	while(l <= h){
		i64 m = l + (h - l) / 2;
		if(m * m == x)
			return m;
		else if(m * m < x){
			ans = m;
			l = m + 1;
		}
		else 
			h = m - 1;
	}
	return ans;
}

struct node {
	i64 e;
	i64 o;
};

node dec(i64 x) {
	node f;
	f.e = 0;
	while(x % 2 == 0 && x != 0) {
		x /= 2;
		f.e ++;
	}
	f.o = x;
	return f;
}

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >>t;
	while(t--)
		solve();
}

void solve(){
	i64 n, m;
	cin >> n >> m;

    if (n == 0 && m != 0){
        cout << "No" << endl;
    }
    else if (n != 0 && m == 0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}