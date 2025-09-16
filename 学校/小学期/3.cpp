#include <bits/stdc++.h>
#define P printf

void swap(int* x, int* y){
    int t = *x;
    *x =*y;
    *y = t;
}
signed main () {
    int a[10];
    for(int i = 0; i < 10; i ++)
        scanf("%d", a + i);
    for(int j = 0; j < 10; j ++){
        int minx = 0x3f3f3f3f, mi = -1;
        for(int i = j; i < 10; i ++){
            if(minx > a[i])
                minx = a[i], mi = i;
        }
        swap(a+mi, a+j);
    }
    for(int i = 0; i < 10; i ++)
        printf("%d ", a[i]);
    return 0;
}