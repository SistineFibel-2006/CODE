#include <bits/stdc++.h>
using namespace std;
//#define int long long

const int mod = 1e9 + 7;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>>dot(n);
    for(auto &[x, y] : dot){
        cin >> x >> y;
    }
    unordered_map<pair<double,double>,set<int>>lineToDotIndexs;//k b to set
    unordered_map<double,set<int>>kToBs;
    unordered_map<double,int>kToCnt;
    int cnt1 = 1, cnt2 = 1;
    for(auto &[x1,y1] : dot){
        for(auto &[x2,y2] : dot){
            if(x1 == x2 && y1 == y2) continue;
            double k = double(y2-y1)/double(x2-x1);
            double b = y2 - double(y2-y1)*x2/double(x2-x1);;
            
            linesToDotIndexs[{k,b}].insert(cnt1);
            linesToDotIndexs[{k,b}].insert(cnt2);
            kToBs[k].insert(b);
            cnt2 ++; 
        }
        cnt1 ++;
    }
    for(auto &[k,vals] : kToBs){
        for(auto &b : vals){
            kToCnt[k] += linesToDotIndexs[{k,b}].size();
        }
    }

    for(auto &[key,vals] : kToBs){
        if(vals.size() == k && kToCnt[key] == n){
            for(auto &[k,vals] : kToBs){
                for(auto &b : vals){
                    cout << linesToDotIndexs[{k,b}].size() << ' ';
                    for(auto &index : linesToDotIndexs[{k,b}]){
                        cout << index << ' ';
                    }
                    cout << '\n';
                }
            }
        }
    }
}

signed main() {
    int t = 1;
    //cin >> t;
    while(t --) solve();
}
