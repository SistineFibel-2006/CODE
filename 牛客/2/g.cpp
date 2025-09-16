#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}

void solve(){

    int n,m;
    cin >> n >> m;
    int lst=m,now=m*m;
    int cnt=2;
    while(now-n<0&&now<=1000000000){
        if(m==1){
            break;
        }
        lst=now;
        now*=m;
        cnt++;
    }
    cout << (abs(lst-n) <= abs(now-n)?cnt-1:cnt) << endl;

}