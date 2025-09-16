#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve();

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t; cin >> t; while(t --) solve();
    return 0;
}

void solve() {
    int n;
    cin>>n;
    string s[n+1];
    int ans=0;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int l1,l2;
            if(s[i].length()>s[j].length()) l1=i,l2=j;
            else l1=j,l2=i;
            int ll=s[l2].length();
            for(int k=-ll;k<signed(s[l1].length());k++){
                //cout<<k<<" ";
                int len=0;
                for(int l=0;l<s[l2].length();l++){
                    if(l+k>s[l1].length()||l+k<0){
                        ans=max(ans,len),len=0;
                        continue;
                    }
                    if(s[l1][l+k]==s[l2][l]) len++;
                    else ans=max(ans,len),len=0;
                }
                ans=max(ans,len);
            }
            // for(int k = 0; k < s[l1].length(); k ++){
            //     int len = 0;
            //     for(int l = 0; l < s[l2].length(); l ++){
            //         if(s[l1][k] != s[l2][l]){
            //             ans = max(ans, len);
            //             continue;
            //         }
            //         len++;
            //         ans = max(ans, len);
            //     }
            // }
        }
    }    
    cout<<ans<<"\n";
}