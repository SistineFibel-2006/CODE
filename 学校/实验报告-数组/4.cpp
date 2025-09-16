#include <stdio.h>
signed main () {
    int a[][4] = {{14,26,18,17},{24,37,21,8},{19,31,22,16},{7,19,14,26}};
    int min_i, min_j, minx = 0x3f3f3f3f;
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 4; j ++)
            if(a[i][j] < minx)
                minx = a[i][j], min_i = i, min_j = j;
    printf("%d %d", min_i, min_j);        
    return 0;
}