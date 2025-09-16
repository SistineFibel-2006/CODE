#include <bits/stdc++.h>

void paixu (int a[]){
    for(int j = 0; j < 10; j ++){
        int minx = 0x3f3f3f3f, mi = -1;
        for(int i = j; i < 10; i ++){
            if(minx > a[i])
                minx = a[i], mi = i;
        }
        std::swap(a[mi], a[j]);
    }
}

signed main() {
    int a[10];
    for(int i = 0; i < 10; i ++)
        scanf("%d", a + i);
    paixu(a);
    for(int i = 0; i < 10; i ++)
        printf("%d ", a[i]);
}