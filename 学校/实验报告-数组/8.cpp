#include <stdio.h>

signed main () {
    int triangle[10][10];
    int i, j;
    for (i = 0; i < 10; i++) {
        triangle[i][0] = 1;  
        triangle[i][i] = 1; 
        for (j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j <= i; j++) {
            printf("%6d", triangle[i][j]);
        }
        puts("");
    }
    return 0;
}