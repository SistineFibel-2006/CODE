#include<bits/stdc++.h>
#define N 2000006
#define ll long long
typedef unsigned long long ull;
#define inf 2147483647
using namespace std;
ull base=131;
ull a[10010];
char s[10010];
int n,ans=1,prime=19260817;
ull mod=212370440130137957;
ull hash1(char s[])
{   
    int len=strlen(s);
    ull ans=0;
    for(int i=0;i<len;i++) ans=(ans*base+ull(s[i]))%mod+prime;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        a[i]=hash1(s);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1])
            ans++;
    }
    cout<<ans;
    return 0;
}