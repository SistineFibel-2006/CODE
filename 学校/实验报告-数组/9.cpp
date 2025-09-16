#include <stdio.h>

signed main () {
    int n1, n2;
    char a[100], b[100];
    scanf("%d", &n1);
    for(int i = 0; i < n1; i ++)
        scanf("%c", a + i);
    scanf("%d", &n2);
    for(int i = 0; i < n2; i ++)
        scanf("%c", b + i);
    bool flag = 1;
    for(int i = 0; i < n1 > n2 ? n2 : n1; i ++){
        if(n1 != n2){
            flag = 0;
            break;
        }
        if(a[i] != b[i]) { 
            flag = 0;
            break;
        }   
    }
    if(flag)
        puts("YES");
    else 
        puts("NO");
    return 0;
}