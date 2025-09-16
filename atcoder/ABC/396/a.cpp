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

signed main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i ++)
        cin >> a[i];


    int flag = 0;
    for(int i = 1; i <= n - 2; i ++)
        if(a[i] == a[i + 1] && a[i + 1] == a[i + 2])
            flag = 1;


    if(flag == 1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

void solve() {

}

