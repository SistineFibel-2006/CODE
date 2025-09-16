#include <string.h>
#include <stdio.h>

signed main () {
    char a[100], b[100];
    scanf("%s %s", a, b);
    char *c = strcat(a, b);
    puts(c);
}