#include <stdio.h>

int fGCD(int x, int y){
    while(y != 0){
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int fLCM(int x, int y){
    return x * y / fGCD(x, y);
}

signed main () {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("GCD:%d LCM:%d", fGCD(a, b), fLCM(a, b));
    return 0;
}