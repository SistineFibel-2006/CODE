#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n+1],ans[n+1],tot=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--){
        int j;
        while(s.size()>=1){
            j=s.top();
            if(a[i]<a[j]){
                ans[++tot]=s.top();
                s.push(i);
                break;
            }
            else{
                s.pop();
            }
        }
        if(s.empty()==1){s.push(i);ans[++tot]=0;}
    }
    for(int i=tot;i>=1;i--) cout<<ans[i]<<" ";
    return 0;
}