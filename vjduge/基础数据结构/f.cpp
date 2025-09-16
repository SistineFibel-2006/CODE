#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

struct j {
    int d;
    int g;
};

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

    int n;
    cin >> n;
    vector<j> a(n);

    for(int i = 0; i < n; i ++)
        cin >> a[i].d >> a[i].g;

    sort(a.begin(), a.end(),
        [&](j a1, j b1){
            return a1.d<b1.d;
        }); 

    priority_queue<int, vector<int>, greater<int> > q;
    i64 ans = 0;
    for(int i = 0; i < n; i ++){
        if(a[i].d <= q.size() ) { //瞎逼做的结果就是后悔
            if(a[i].g > q.top() ) { //更优替换
                ans -= q.top();
                ans += a[i].g;
                q.pop();
                q.push(a[i].g);
            }
        }
        else {  //有时间就瞎比做
            q.push(a[i].g);
            ans += a[i].g;
        }
    }

    cout << ans << endl;
}

void solve(){

}