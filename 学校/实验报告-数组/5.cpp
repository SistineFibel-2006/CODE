#include <stdio.h>
signed main () {
    char s1[1000], s2[1000], s3[10000];
    char t, p1 = 0, p2 = 0;
    while(scanf("%c", &t) && t != '\n')
        s1[p1 ++] = t;
    s1[p1] = '\0';
    while(scanf("%c", &t) && t != '\n')
        s2[p2 ++] = t;
    s2[p2] = '\0';
    for(int i = 0; i <= p1 + p2 - 1; i ++)
        if(i < p1)
            s3[i] = s1[i];
        else
            s3[i] = s2[i - p1];
    printf("%s", s3);
    return 0;
}