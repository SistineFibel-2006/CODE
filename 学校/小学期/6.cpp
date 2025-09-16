#include <bits/stdc++.h>

void strmcpy(char *a, char *b, int m) {
    int p = 0;
    while((b[p] = a[m]) != '\0') m ++, p ++;
}

signed main() {
    char a[5050], b[5050];
    scanf("%s", a);
    int m; scanf("%d", &m);
    strmcpy(a, b, m);
    puts(b);
}