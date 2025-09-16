#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> a;
    vector<int> cnt;
    vector<int> now;

    while(T--){
        int n, m, c;
        cin >> n >> m >> c;
        a.resize(n);
        for(int i = 0; i < n; ++i) 
            cin >> a[i];

        int t = n / c;

        cnt.assign(m + 1, 0);
        for(int x : a) 
            cnt[x] ++;

        int kk = 0;
        bool inf = true;
        for(int v = 0; v <= m; v ++){
            if(cnt[v]){
                if(cnt[v] != t){
                    inf = false;
                    break;
                }
                kk ++;
            } 
        }
        if(inf && kk == c){
            cout << "-1\n";
            continue;
        }

        now.resize(m+1);  

        vector<int> ans;
        ans.reserve(16);

        for(int k = c; k <= m; k ++){
            fill(now.begin(), now.begin() + k, 0);

            bool bad = false;
            int good = 0;
            for(int r = 0; r < k; ++r){
                int sum = 0;
                for(int x = r; x <= m; x += k){
                    sum += cnt[x];
                    if(sum > t) {
                        bad = true;
                        break;
                    }
                }
                if(bad) break;
                if(sum == 0) continue;
                if(sum != t){
                    bad = true;
                    break;
                }
                if(++good > c){
                    bad = true;
                    break;
                }
            }
            if(!bad && good == c){
                ans.push_back(k);
            }
        }

        cout << ans.size();
        for(int k : ans) 
            cout << ' ' << k;
        cout << '\n';
    }

    return 0;
}