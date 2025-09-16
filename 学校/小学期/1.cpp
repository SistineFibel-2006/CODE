#include <bits/stdc++.h>
#define P printf

void swap(int* x, int* y){
    int t = *x;
    *x =*y;
    *y = t;
}

void sss(int* x, int* y, int* z){
    if(*x < *y)
        swap(x, y);
    if(*x < *z)
        swap(x, z);
    if(*y < *z)
        swap(y, z);
}
signed main () {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    sss(&a, &b, &c);
    printf("%d %d %d", a, b, c);
    return 0;
}