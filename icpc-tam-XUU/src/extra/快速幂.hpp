#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll qpow(ll a,ll b,ll c)
{
    ll ans=1,base=a;
    while(b>0)
    {
        if(b&1==1)
        {
            ans*=base;
            ans%=c;
        }
        base*=base;
        base%=c;
        b>>=1;
    }
    return ans%c;
}
int main()
{
    ll a,b,p;
    cin>>a>>b>>p;
    ll ans=qpow(a,b,p);
    printf("%d^%d mod %d=%d",a,b,p,ans);
    system("pause");
    return 0;
}