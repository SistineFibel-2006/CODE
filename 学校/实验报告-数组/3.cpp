#include <stdio.h>

signed main () {
    int a[16], x, cnt_o = 0, p = 0;
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 4; j ++){
            scanf("%d", &x);
            if(x & 1 != 1)
                cnt_o ++;
            if(x < 5)
                a[p++] = x;
        }
    printf("odd_cnt : %d\n", cnt_o);
    for(int i = 0; i < p; i ++)
        printf("%d ", a[i]);
    return 0; 
}