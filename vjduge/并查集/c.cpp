#include<bits/stdc++.h>
using namespace std;
long long  n,m,x,y,t,c,d,q,f1[1000100],f2[1000100];
int find(int x, long long f[]){
       if(f[x] == x)
              return x;
       else
              return f[x] = find(f[x], f);
} 

void nan(int x,int y) {
       int a, b;
       a = find(x, f1);
       b = find(y, f1);
       if(a != b)
              f1[a] = b;
}
void nv(int x, int y) {
       int a, b;
       a = find(x, f2);
       b = find(y, f2);
       if(a != b)
              f2[a] = b;       
}

int main(){
       cin >> n >> m >> t >> q;

       for(int i = 1; i <= n; i ++)
              f1[i]=i;
       for(int i = 1; i <= m; i ++)
              f2[i]=i;

       for(int i = 1; i <= t; i ++){
              cin >> x >> y;
              nan(x, y);
       }
       for(int i = 1; i <= q; i ++){
              cin >> x >> y;
              x = (-x);
              y = (-y);
              nv(x, y);
       }

       int fstn = find(1, f1);
       int fstv = find(1, f2);
       int cntn = 0, cntv = 0;
       for(int i = 1; i <= n; i ++)
              if(find(i, f1) == fstn)
                     cntn ++;

       for(int i = 1; i <= m; i ++)
              if(find(i, f2) == fstv)
                     cntv ++;

       cout << min(cntn, cntv);
       
    return 0;
}

