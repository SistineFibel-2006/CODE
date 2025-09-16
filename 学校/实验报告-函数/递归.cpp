#include <stdio.h>


int work(int x){
    if(x == 1 || x == 0)
        return 1;
    else
        return work(x - 1) * x;
}

signed main() {
    int n;
    scanf("%d", &n);
    printf("%d", work(n));
}