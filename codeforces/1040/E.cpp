#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int> ask(int k, const vector<int>& id) {
    cout << "? " << k;
    for (int x : id) cout << ' ' << x;
    cout << "\n" << flush;
    int a; cin >> a;
    cout << "? " << k;
    for (int i = k - 1; i >= 0; i--) cout << ' ' << id[i];
    cout << "\n" << flush;
    int b; cin >> b;
    return {a, b};
}

pair<int,int> ask(int k) {
    vector<int> id(k);
    iota(id.begin(), id.end(), 1);
    return ask(k, id);
}

pair<int,int> ask_2(int k, int n) {
    vector<int> id(k);
    for (int i = 0; i < k; i++) id[i] = n - k + 1 + i;
    return ask(k, id);
}

int finds(int n) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r + 1) >> 1;
        auto [a, b] = ask(m);
        int D = m*m - 4*(a + b);
        int sq = (int)(sqrtl(D) + 0.5);
        int x = (m + sq) >> 1;
        if (x == m) l = m;
        else r = m - 1;
    }
    return l;
}

int find_2(int n) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r + 1) >> 1;
        auto [a, b] = ask_2(m, n);
        int D = m*m - 4*(a + b);
        int sq = (int)(sqrtl(D) + 0.5);
        int x = (m + sq) >> 1;
        if (x == m) l = m;
        else r = m - 1;
    }
    return l;
}

void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
    int n; cin >> n;
    int p = finds(n);
    bool lft = (p != 0);
    int reask;
    vector<char> s(n+1, '?');
    if (lft) {
        reask = p;
        for (int i = 1; i <= p; i++) s[i] = '(';
    } 
    else {
        int q = find_2(n);
        reask = n - q + 1;
        for (int i = reask; i <= n; i++) s[i] = ')';
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] != '?') continue;
        cout << "? 2 " << reask << " " << i << "\n" << flush;
        int f; cin >> f;
        if (lft) s[i] = (f == 1 ? ')' : '(');
        else     s[i] = (f == 1 ? '(' : ')');
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << s[i];
    cout << "\n" << flush;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _; cin >> _;
    while (_--) Tempest_Flare__The_Wind_Splitting_Magic_Bullet();
    return 0;
}
