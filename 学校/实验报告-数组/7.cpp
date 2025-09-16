#include <stdio.h>
signed main () {
    int arr[100] = {1, 3, 5, 7, 9}; 
    int n = 5;                      
    int num, i, pos;
    scanf("%d", &num);
    for (pos = 0; pos < n; pos++) {
        if (num < arr[pos]) {
            break;
        }
    }
    for (i = n; i > pos; i--)
        arr[i] = arr[i-1];
    arr[pos] = num;
    n++; 
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}