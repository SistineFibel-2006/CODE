/*

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
        solve();
}

void solve() {
    i64 k, a, b, c;
    cin >> k >> a >> b >> c;
    vector<i64> sums = {
        0,
        a,
        b,
        c,
        a + b,
        a + c,
        b + c,
        a + b + c
    };
    i64 max_s = 0;
    for (i64 s : sums) {
        if (s <= k && s > max_s) {
            max_s = s;
        }
    }
    cout << (k - max_s) << endl;
}
//test
/*
ඞ
// ٩ (◕‿◕｡) ۶
*/

/*

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	vector<int> b(n);
	for (int i = 0; i < n; ++i) 
		cin >> b[i];
	
	i64 ans = 0;
	int now = a[0] + b[0];
	i64 sum = a[0];
	int il = 1;
	
	for (int i = 1; i < n; ++i) {
	    int s = a[i] + b[i];
	    if (s == now)
	        sum += a[i], il += 1;
	    else {
	        i64 tt = sum * il;
	        if (tt > ans) 
	        	ans = tt;
	        now = s;
	        sum = a[i];
	        il = 1;
	    }
	}
	i64 temp = sum * il;
	if (temp > ans) ans = temp;
	
	printf("%lld\n", ans);
}
//test
/*
ඞ
// ٩ (◕‿◕｡) ۶
*/


/*

#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

bool cmp(int x,int y){
	return x > y;
}

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(auto &c : a)
		cin >> c;
	string s; cin >> s;
	int cntr = 0, cnts = 0;
	vector<int> r(n, 0), b(n, 0);
	for(int i = 0; i < s.length(); i ++) {
		if(s[i] == 'R')
			r[i] = a[i], cntr++;
		else
			b[i] = a[i], cnts++;
	}
	int L = min(cntr, cnts);
	sort(r.begin(),r.end(),cmp);
	sort(b.begin(),b.end(),cmp);

	// for(auto c : r)
	// 	cerr << c << ' ';
	// cerr << endl;
	// for(auto c : b)
	// 	cerr << c << ' ';
	// cerr << endl;

	int sum = 0;
	for(int i = 0; i < L; i ++)
		sum += r[i] + b[i];
	int maxx = r[L];
	cout << sum + maxx << endl;
}
//test
/*
ඞ
// ٩ (◕‿◕｡) ۶
*/