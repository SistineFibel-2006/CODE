#include <bits/stdc++.h>
#define MAXLEN 1000000
using namespace std;

int n, k;
char s[MAXLEN + 10];
int cnt, sz[MAXLEN + 10], t[MAXLEN + 10], ch[MAXLEN + 10][26];

int newNode() {
    cnt++;
    sz[cnt] = t[cnt] = 0;
    memset(ch[cnt], 0, sizeof(ch[cnt]));
    return cnt;
}

void add() {
    int now = 1;
    t[now]++;
    for (int i = 1; s[i]; i++) {
        int &c = ch[now][s[i] - 'a'];
        if (!c) c = newNode();
        t[now = c]++;
    }
    sz[now]++;
}

void solve() {
    cnt = 0; newNode();
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        add();
    }
    int now = 1;
    while (true) {
        int tmp = sz[now];
        for (int i = 0; i < 26; i++) if (t[ch[now][i]]) tmp++;
        if (tmp >= k) {
            if (now == 1) printf("EMPTY");
            printf("\n");
            return;
        }
        for (int i = 0; i < 26; i++) if (t[ch[now][i]]) {
            tmp = tmp - 1 + t[ch[now][i]];
            if (tmp >= k) {
                k -= tmp - t[ch[now][i]];
                now = ch[now][i];
                printf("%c", i + 'a');
                break;
            }
        }
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}