#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    string s;
    cin >> s;
    int sl[s.size()+1],sr[s.size()+1],tl=0,tr=0;
    for(int i=0;i<s.size();i++) if(s[i]=='L') sl[++tl]=i;
    for(int i=s.size()-1;i>=0;i--) if(s[i]=='R') sr[++tr]=i;
    int n;
    cin>>n;
    while(n--){
        string q;
        cin>>q;
        int ans[q.size()+1],totl=0,totr=0,pd=0;
        for(int i=0;i<q.size();i++){
            if(q[i]=='L'&&totl==tl){
                pd=1;
                break;
            }
            if(q[i]=='L'&&totl<tl) ans[i]=sl[++totl];
        }
        for(int i=q.size()-1;i>=0;i--){
            if(q[i]=='R'&&totr==tr){
                pd=1;
                break;
            }
            if(q[i]=='R'&&totr<tr) ans[i]=sr[++totr];
        }
        if(pd==1||(q[0]=='R'&&s[0]!='R')||(q[q.size()-1]=='L'&&s[s.size()-1]!='L')){
            cout<<"NO\n";
            continue;        
            }
            for(int i=0;i<q.size()-1;i++){
                if(ans[i]>ans[i+1]){
                    cout<<"NO\n";
                    pd=1;
                    break;
                }
            }
        if(pd==0) cout<<"YES\n";
    }
}

signed main () {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
