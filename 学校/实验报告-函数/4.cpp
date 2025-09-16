#include <stdio.h>

int find_max(int a[]){
    int maxx = -0x3f3f3f3f;
    for(int i = 0; i < sizeof(a); i ++)
        maxx = maxx > a[i] ? maxx : a[i] ;
    return maxx;
}

signed main () {
    int a[10];
    for(int i = 0; i < 10; i ++)
        scanf("%d", a + i);
    printf("%d", find_max(a));
    return 0;
}