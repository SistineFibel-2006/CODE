#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve();

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    //int t; cin >> t; while(t --) solve();

    int n,m,k;
    cin >> n >> m >> k;
    if(m != 0 && m > k){
        cout << "No" << endl;
        return 0;
    }
    if(m==k){
        cout << "Yes" << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << 'a';
            }
            cout << endl;
        }
    }
    else if(m==1){
        cout << "Yes" << endl;
        int step=m+1;
        int cnt=0;
        int iv1=0,iv2=0;

        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){

                if(j%step==0){

                    cout << char('a'+iv1);

                }
                else{

                    cout << char('a'+iv2);
                    
                }
            }
            cout << endl;
            iv1++;
            if(iv1==26){
                iv2++;
                iv1=iv2;
            }
            cnt++;
            if(cnt==n)break;
        }
    }
    else if(k<m){
        cout << "No" << endl;
    }
    else if(m==0&&k>=1&&n>26){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
        int step=m+1;
        int cnt=0;
        int iv1=0,iv2=0;

        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){

                if(j%step==0){

                    cout << char('a'+iv1);

                }
                else{

                    cout << char('a'+iv2);
                    
                }
            }
            cout << endl;
            iv1++;
            if(iv1==26){
                iv2++;
                iv1=0;
            }
            cnt++;
            if(cnt==n)break;
        }
    }


    return 0;
}

void solve() {
    




}