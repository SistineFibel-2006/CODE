#include <bits/stdc++.h>
#define P printf

void swap(int* x, int* y){
    int t = *x;
    *x =*y;
    *y = t;
}
signed main () {
    int a[100];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
        scanf("%d", a + i);
    for(int i = 0; i < n / 2; i ++)
        swap(a + i, a + n - i - 1);
    for(int i = 0; i < n; i ++)
        printf("%d ", a[i]);
    return 0;
}