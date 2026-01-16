#include <stdio.h>

int main() {
    int n = 20, a[n];
    for(int i = 0; i < 3; i ++) scanf("%d", a + i);
    for(int i = 0; i < 3; i ++) printf("%d ", a[i]);
    puts("0");
    return 0;
}
