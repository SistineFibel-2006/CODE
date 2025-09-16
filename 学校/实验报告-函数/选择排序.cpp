#include <bits/stdc++.h>

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
        std::swap(a[mi], a[j]);
    }
    for(auto c : a)
        printf("%d ", c);

    return 0;
}