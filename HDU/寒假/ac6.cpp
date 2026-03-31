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
// 	int t = 1;
// 	cin >> t;
// 	while(t --)
// 		solve();
// }

// void solve(){

// }
// //test
// /*
// ඞ
// // ٩ (◕‿◕｡) ۶
// */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n1, n2;
        cin >> n1 >> n2;

        vector<int> drum1(n1), drum2(n2);
        set<int> times;

        for (int i = 0; i < n1; ++i) {
            int p, q;
            cin >> p >> q;
            drum1[i] = p / gcd(p, q);
            times.insert(drum1[i]);
        }

        int count = 0;
        for (int i = 0; i < n2; ++i) {
            int p, q;
            cin >> p >> q;
            int start = p / gcd(p, q);
            if (times.count(start)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}