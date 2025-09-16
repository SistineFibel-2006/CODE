#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(auto &c : a)
		cin >> c;
	if(d == 0){
		sort(a.begin(),a.end());
		int cnt_uni = unique(a.begin(),a.end()) - a.begin();
		cout << n - cnt_uni << endl;
		return;
	}

	// sort(a.begin(), a.end());

	// int ans = 0;
	// int L = 1;
	// for(int i = 1; i < n; i ++){
	// 	if(a[i] - a[i - 1] == d)
	// 		L ++;
	// 	else {
	// 		ans += (L + 1) / 2;
	// 		L = 1;
	// 	}
	// }

	// ans += (L + 1) / 2;
	// cout << n - ans << endl;


    // unordered_map<int, int> freq;
    // for (int num : a) freq[num]++;
    
    // int deletions = 0;
    // for (auto& [num, count] : freq) {
    //     if (freq.count(num + D)) {
    //         deletions += min(count, freq[num + D]);
    //         freq[num + D] = 0; // 避免重复计算
    //     }
    // }
    
    // cout << deletions << '\n';
    unordered_map<int, int> freq;
    for (int num : a) freq[num]++;
    
    int deletions = 0;
    unordered_set<int> processed;  // 记录已处理的元素
    
    for (auto& [num, cnt] : freq) {
        if (processed.count(num)) continue;  // 避免重复处理
        
        int target = num + D;
        if (freq.count(target)) {
            // 选择保留出现次数更多的一方，删除另一方
            deletions += min(cnt, freq[target]);
            processed.insert(target);  // 标记目标元素已处理
        }
        processed.insert(num);  // 标记当前元素已处理
    }
    
    cout << deletions << '\n';
}
//test
/*
ඞ
// ٩ (◕‿◕｡) ۶
*/