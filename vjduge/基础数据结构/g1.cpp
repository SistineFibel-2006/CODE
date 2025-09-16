#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
struct node
{
    ll s,t,num;
}a[200005];
struct print
{
    ll t,num;
    bool operator < (const print &x) const{
        return t>x.t||(t==x.t&&num>x.num);
    }
}p[200005];
vector<int> ans[200005];
bool cmp(node x,node y){return x.t<y.t;}
priority_queue<print> q1,q2;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) p[i].t=0,p[i].num=i,q1.push(p[i]);
    for(int i=1;i<=n;i++) a[i].num=i,cin>>a[i].s>>a[i].t;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        while(!q2.empty()){
            struct print x=q2.top();
            if(x.t <= a[i].t){
                x.t=0;
                q2.pop();
                q1.push(x);
            }
            else break;
        }

        if(!q1.empty())
        {
            struct print x=q1.top();q1.pop();
            x.t=a[i].s + a[i].t;
            q2.push(x);
            ans[x.num].push_back(a[i].num);
        }
        else{
            struct print x=q2.top();q2.pop();
            x.t+=a[i].s;
            q2.push(x);
            ans[x.num].push_back(a[i].num);
        }

    }


    for(int i=1;i<=m;i++){
        cout<<ans[i].size()<<" ";
        sort(ans[i].begin (),ans[i].end());
        for(auto j=ans[i].begin();j!=ans[i].end();j++){
            cout<<*j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}


