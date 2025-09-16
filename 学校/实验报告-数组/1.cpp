#include <stdio.h>
#include <algorithm>
int i, j, k;
signed main () {
    int a[10];
    const int n = 10;
    for (i = 0; i < 10; i ++)
        scanf("%d", a + i);
    for (i = 0; i < n-1; i++) 
        for (j = 0; j < n-i-1; j++) 
            if (a[j] > a[j+1]) 
                std::swap(a[j], a[j + 1]);

    for (i = 0; i < n; i ++)
        printf("%d ", a[i]);
    return 0;
}