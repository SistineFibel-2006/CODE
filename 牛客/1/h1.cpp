#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

const int N = 1e5 + 1;
vector<pair<int, int>> ran(N + 1);
vector<bool> vis(N + 1, 0);
vector<int> ans(N + 1);

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    int len_a = a.second - a.first + 1;
    int len_b = b.second - b.first + 1;
    if (len_a == len_b) return a.first > b.first;
    return len_a < len_b;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    n = read();

    for (int i = 1; i <= n; i++) {
        ran[i].first = read();
        ran[i].second = read();
    }

    // 剪枝：计算所有范围的并集大小
    int unionSize = 0;
    vector<bool> inRange(N + 1, false);
    for (int i = 1; i <= n; i++) {
        for (int j = ran[i].first; j <= ran[i].second; j++) {
            if (!inRange[j]) {
                inRange[j] = true;
                unionSize++;
            }
        }
    }
    if (unionSize < n) {
        cout << "-1" << endl;
        return 0;
    }

    sort(ran.begin() + 1, ran.begin() + n + 1, cmp);

    int minChosen = n + 1, maxChosen = 0;
    int i = 1;
    while (i <= n) {
        bool found = false;
        for (int j = ran[i].first; j <= ran[i].second; j++) {
            if (!vis[j] && j >= minChosen && j <= maxChosen) {
                ans[i] = j;
                vis[j] = true;
                minChosen = min(minChosen, j);
                maxChosen = max(maxChosen, j);
                found = true;
            }
        }
        if (found) {
            i++;
        } else {
            if (i > 1) {
                int j = ans[i - 1];
                vis[j] = 0;
                i--;
            } else {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}