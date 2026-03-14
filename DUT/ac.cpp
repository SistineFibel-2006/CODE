#include <bits/stdc++.h>
using namespace std;

const long long fk[] = {26,676,17576,456976,11881376,308915776,8031810176,208827064576,5429503678976,141167095653376,3670344486987776,95428956661682176};

void solve();

int main() {
    int t; cin >> t;
    while(t --) solve();
}

void solve() {
    long long n; cin >> n;
    stack<int > st;
    int p = 11;
    while(n != 0) {
        if(n >= fk[p]){
            st.push(n % fk[p]);
            n /= fk[p--];
        }
        if(n < fk[p]) p --;
        if(p == -1) break;
    }
    while(!st.empty()) {
	int ans = st.top(); st.pop();
	cout << ans << ' ';
//	cout << (char)('A' + ans - 1 == '@' ? 'Z' : 'A' + ans - 1);
    }

    cout << "\n";
}

