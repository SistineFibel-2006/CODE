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
    // cin.ignore();

    string S;
    char a;
    while(getline(cin, S)) {
        bool f = 0;
        for(auto c : S) {
            if(c == ' '){
                cout << ' ';
                f = 0;
            }
            else{
                if(f == 0){
                    a = c;
                    a -= 32;
                    cout << a;
                    f = 1;
                }
                else {
                    cout << c;
                }
            }
        }
        cout << endl;
    }
    return 0;
}

void solve(){

}