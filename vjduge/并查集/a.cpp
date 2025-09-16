#include<bits/stdc++.h>
using namespace std;
long long  n,m,x,y,t,c,d,f[1000100];
int find(int x){
       if(f[x] == x)
              return x;
       else
              return f[x] = find(f[x]);
} 
void lianjie(int x, int y){
       f[find(y)] = find(x);
       return;
}

int main(){
       cin >> n >> m >> t;
       for(int i = 1; i <= n; i ++)
              f[i]=i;
       for(int i = 1; i <= m; i ++){
              cin >>x >> y;
              lianjie(x, y);
       }
       for(int i = 1; i <= t; i ++){
              cin >> c >> d;
              if(find(c) == find(d))
                     cout << "Yes\n" ;
              else
                     cout << "No\n" ;
       }
    return 0;
}

