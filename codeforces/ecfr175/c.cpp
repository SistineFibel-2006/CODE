#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'
// #define max(x, y) x>y?x:y

bool check(int d, const string& s, const vector<int>& a, int k) {
    char last = 'R';
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (a[i] > d) {
            if (s[i] == 'B' && last != 'B') {
                cnt++;
            }
            last = s[i];
        }
    }
    return cnt <= k;
}

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int > a(n);
	for(auto &c : a)
		cin >> c;
	int l = 0, r = (int)(1e9);
	int ans = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid, s, a, k)){ans = mid; r = mid - 1;}
		else l = mid - 1;
	}
	cout << ans << endl;
}