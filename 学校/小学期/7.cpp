#include <bits/stdc++.h>

int subs(char *s, char *t) {
    int i = 0, j = 0;
    while(s[i] != 0){
        int tt = i;
        j = 0;
        while(t[j] != '\0' && s[tt] === t[j])
            tt ++, j ++;
        if(t[j] == '\0')
            return i + 1;
        i ++;
    }
    return -1;
}

signed main() {
    char a[5050], b[5050];
    scanf("%s %s", a, b);
    int ans = subs(a, b);
    std::cout << ans;
}