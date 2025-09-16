// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'


// signed main (){ 
// 	std::ios::sync_with_stdio(false);std::cin.tie(0);
// 	int t;
// 	int n;
// 	while(t --){
// 		cin >> n;
// 		map<int, int> mp;
// 		int tt;
// 		for(int i = 1; i <= n; i ++){
// 			cin >> tt;
// 			mp[tt] ++;
// 		}

//  		for(auto x : mp)


 
// 	}




// }

// void solve(){

// }

#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<unordered_set<int>> dice(N);
    vector<int> K(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> K[i];
        dice[i].clear();
        for (int j = 0; j < K[i]; ++j) {
            int num;
            cin >> num;
            dice[i].insert(num);
        }
    }
    
    double max_prob = 0.0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int common = 0;
            for (int num : dice[i]) {
                if (dice[j].count(num)) {
                    ++common;
                }
            }
            double prob = static_cast<double>(common) / (K[i] * K[j]);
            if (prob > max_prob) {
                max_prob = prob;
            }
        }
    }
    
    cout << fixed << setprecision(10) << max_prob << endl;
    
    return 0;
}