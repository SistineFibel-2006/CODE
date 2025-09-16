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
    stack<int> a;
    int t = 100;
    int n;
    cin >> n;
    while(t --)
        a.push(0);

    int x, y;
    while(n -- ) {
        cin >> x;
        if(x == 1){
            cin >> y;
            a.push(y);
        }
        else {
            y = a.top();
            a.pop();
            cout << y << endl;
        }
    }




    return 0;
}

void solve() {

}

