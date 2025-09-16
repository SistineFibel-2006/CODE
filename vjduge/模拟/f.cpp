#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

string zhuan(int n, int m) {
    string s = "";  
    bool nigger = n < 0; 
    if (nigger) {
        n = -n; 
    }
    while (n > 0) {
        int a = n % m;  
        if (a < 10) {
            s = char('0' + a) + s; 
        } else {
            s = char('A' + a - 10) + s; 
        }
        n /= m;  
    }
    if (nigger) {
        s = "-" + s;  
    }
    return s;
}

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

    int n, m;
    while(cin >> n >> m){
        cout << zhuan(n, m) << endl;
    }



}

void solve(){

}