#include <stdio.h>

signed main () {
    int a[3][6];
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 6; j ++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 6; j ++)
            printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}