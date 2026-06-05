#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define rep(i, a, b) for(Int i = (a); i < (b); i ++)
using vi = vector<Int>;
#define sz(s) ((Int)size(s))
const Int mod = 998244353;

vi Z(string s) {
	Int n = sz(s);
	vi z(n, n);
	Int l = -1, r = -1;
	rep(i, 1, n) {
		Int &x = z[i] = i < r ? min(r - i, z[i - l]) : 0;
		while(i + x < n && s[i + x] == s[x]) x ++;
		if(i + x > r) l = i, r = i + x;
	}
	return z;
}

map<char, int> mp;

int main() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	mp['A'] = 0, mp['T'] = 1, mp['G'] = 2, mp['C'] = 3;

	auto z = Z(s);

	vector<vi> ch(m + 1, vi(4, 0));

	rep(j, 0, m) rep(k, 0, 4) for(int l = j + 1; l > 0; l --) {
		if(mp[s[l - 1]] != k) continue; //分开匹配新加入的碱基对与原本碱基对的前缀.
		if(l == 1) { //没有前缀
			ch[j][k] = 1;
			break;
		}
		Int idx = j - l + 1;
		if(idx == 0) {
			ch[j][k] = l;
			break;
		} else if(idx > 0 && idx < m) {
			if(z[idx] >= l - 1) {
				ch[j][k] = l;
				break;
			}
		}
	}
	rep(k, 0, 4) ch[m][k] = m;

	vector<vi> f(n + 1, vi(m + 1, 0));
	f[0][0] = 1;
	vi p(4);
	rep(i, 1, n + 1) {
		rep(j, 0, 4) cin >> p[j];

		rep(j, 0, m + 1) {
			if(!f[i - 1][j]) continue;
			rep(k, 0, 4) {
				f[i][ch[j][k]] = (f[i][ch[j][k]] + f[i - 1][j] * p[k]) % mod;
			}
		}
	}
	cout << f[n][m] << '\n';

}