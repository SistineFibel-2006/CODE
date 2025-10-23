#include<bits/stdc++.h>
#define N 100005
#define inf 2147483647
#define ll long long
using namespace std;
int n,a[N],b[N],sit[N],dp[N],len;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sit[a[i]]=i;
    for(int i=1;i<=n;i++) cin>>b[i],dp[i]=inf;
    for(int i=1;i<=n;i++){
        if(sit[b[i]]>dp[len]) dp[++len]=sit[b[i]];
        else{
            int l=0,r=len,mid;
            while(l<r){
                mid=(l+r)>>1;
                if(dp[mid]>sit[b[i]]) r=mid;
                else l=mid+1;
            }
            dp[l]=min(dp[l],sit[b[i]]);
        }
    }
    cout<<len;
    return 0;
}