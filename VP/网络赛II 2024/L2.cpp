#include <bits/stdc++.h>
using namespace std;
#define int long long

using a2 = array<int, 2>;

void solve() {
	int n; cin >> n;
	auto work = [](int c, int t) -> array<int, 2> {
		int a = c * c + 2 * t - c, b = 2 * c;
		int g = __gcd(a, b);
		return {a/g,b/g};
	};
	auto cmp = [](a2 a, a2 b) ->bool {
		return a[0] * b[1] <= a[1] * b[0];
	};
	int c1 = ceil(sqrt(n * 2)), c2 = floor(sqrt(2 * n));
	auto a1 = work(c1, n), a2 = work(c2, n);
	auto ans = cmp(a1, a2) ? a1 : a2;
	cout << ans[0] << ' ' << ans[1] << endl;
}

signed main() {
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}