#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin >> s;
    int nl=0,nr=0;
    int step=0;
    int n=s.length();
    while(step<n&&s[step]!='R'){
        step++;
        nl++;
    }
    step=n-1;
    while(step>=0&&s[step]!='L'){
        step--;
        nr++;
    }
    
    int qt;
    cin >> qt;
    for(int i=0;i<qt;i++){
        string s1;
        cin >> s1;
        int q=s1.length();
        int ql=0,qr=0;
        int step=0;
        while(step<q&&s1[step]!='R'){
            step++;
            ql++;
        }
        step=q-1;
        while(step>=0&&s1[step]!='L'){
            step--;
            qr++;
        }
        if(ql==0&&nl!=0){
            cout << "NO" << endl;
            continue;
        }
        if(qr==0&&nr!=0){
            cout << "NO" << endl;
            continue;
        }
        int st=min(nl,ql);
        int rmin=min(nr,qr);
        bool stat=0;
        for(int j=nl;j<n-nr;j++){
            if(s[j]==s1[st]){
                st++;
            }
            if(st>=q-rmin){
                cout << "YES" << endl;
                stat=1;
                break;
            }
        }
        
        if(stat==1){
            continue;
        }
        if(st>=q-min(nr,qr)){
            cout << "YES" << endl;
            stat=1;
            continue;
        }
        cout << "NO" << endl;

    
    }
}

signed main () {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
