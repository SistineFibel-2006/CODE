#include <bits/stdc++.h>
using namespace std;
int n,m;
long long int a[100000000];
long long s;
int ans;
int main(){
    cin >> n >> m;
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        cin>>s;
        ans = lower_bound(a+1,a+n+1,s)-a;
        if(s != a[ans]) cout<<"-1 ";
        else cout<<ans<<" ";
    }
    return 0;
}