#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
		int n;
		while(cin >> n && n != 0){
            int a[n];
			for(int i = 0; i < n; i ++)
				cin >> a[i];
			int mp = min_element(a,a + n) - a;
			swap(a[mp], a[0]);
            for(int i = 0; i < n; i ++)
                cout << a[i] << " ";
            cout << endl;
		}
}

void solve(){

}