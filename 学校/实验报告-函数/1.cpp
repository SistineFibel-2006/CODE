#include <stdio.h>

int findM(int x, int y);

signed main () {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", findM(a, b));
}

int findM(int x, int y){
    return x > y ? x : y; 
}