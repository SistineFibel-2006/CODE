#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(size_t i = a; i < b; i ++)
#define F_(i,a,b) for(size_t i = a; i > b; i --)
#define pb push_back
#define fi first
#define se second
#define in insert
#define eb emplace_back


void solve() {
    int n,k,cnt=1,mk=0,ans2=0,ans1=0,ans3=0;
    cin>>n>>k;
    string s,nj={"nanjing"};
    cin>>s;
    s=' '+s;
    if(n<7){cout<<0<<"\n";return;}
    for(int i=7;i<=n;i++){
        string cur;
        for(int j=i-6;j<=i;j++) cur=cur+s[j];
        ans1+=(cur==nj);
    }
    for(int i=1;i<=n;i++) s=s+s[i];
    for(int i=n+1;i<=n+6;i++){
        string cur;
        for(int j=i-6;j<=i;j++) cur=cur+s[j];
        // cout<<cur<<"\n";
        ans2+=(cur==nj);
    }
    for(int i=n+1;i<=n+k%n;i++){
        if(k%n==0) break;
        string cur;
        for(int j=i-6;j<=i;j++) cur=cur+s[j];
        ans3+=(cur==nj);
    }
    // cout<<s<<"\n";
    cout<<ans1*(k/n+1)+ans2*(k/n-(k/n>0))+ans3<<"\n";
}

signed main() {
    int t=1; 
    cin >> t;
    while(t --)  solve();
}