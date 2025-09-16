#include <stdio.h>
#include <string.h>
signed main () {
    char a[100], b[100];
    char x;
    int p1 = 0, p2 = 0;
    while(scanf("%c", &x) && x != '\n')
        a[p1 ++] = x;
    while(scanf("%c", &x) && x != '\n')
        b[p2 ++] = x;    
    puts(a);
    puts(b);
    if(strcmp(a, b) != -1)
        puts("1");
    else
        puts("0");

    int L1 = (int)strlen(a);
    int L2 = (int)strlen(b);
    printf("%d %d", p1, p2);
    return 0;
}