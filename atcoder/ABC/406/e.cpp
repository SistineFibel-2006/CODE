#include <bits/stdc++.h>

using namespace std;
#define int long long
const long long INF = 0x3f3f3f3f;
const int MOD = 998244353;
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()

int popcnt(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}


int find(int N, int K) {
    if (K == 0) return 0; 
    if (K > 60) return 0; 
    if (N <= 1000000) {
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            if (popcnt(i) == K) {
                sum = (sum + i) % MOD;
            }
        }
        return sum;
    }
    
    vector<int> bits;
    int temp_N = N;
    while (temp_N > 0) {
        bits.push_back(temp_N & 1);
        temp_N >>= 1;
    }
    reverse(bits.begin(), bits.end());
    int n = bits.size();
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(K + 1, vector<int>(2, -1)));
    
    function<int(int, int, bool)> cntN = [&](int pos, int cnt, bool tight) -> int {
        if (cnt > K) return 0;
        if (pos == n) return (cnt == K) ? 1 : 0;
        
        if (dp[pos][cnt][tight] != -1) return dp[pos][cnt][tight];
        
        int result = 0;
        int limit = tight ? bits[pos] : 1;
        
        result = (result + cntN(pos + 1, cnt, tight && 0 == bits[pos])) % MOD;
        
        if (limit == 1) {
            result = (result + cntN(pos + 1, cnt + 1, tight && 1 == bits[pos])) % MOD;
        }
        
        return dp[pos][cnt][tight] = result;
    };
    
    vector<vector<vector<int>>> sum_dp(n + 1, vector<vector<int>>(K + 1, vector<int>(2, -1)));
    
    function<int(int, int, bool)> sumN = [&](int pos, int cnt, bool tight) -> int {
        if (cnt > K) return 0;
        if (pos == n) return 0;
        
        if (sum_dp[pos][cnt][tight] != -1) return sum_dp[pos][cnt][tight];
        
        int result = 0;
        int limit = tight ? bits[pos] : 1;
        
        result = (result + sumN(pos + 1, cnt, tight && 0 == bits[pos])) % MOD;
        
        if (limit == 1) {
            int power = (1 << (n - 1 - pos)) % MOD;
            int count = cntN(pos + 1, cnt + 1, tight && 1 == bits[pos]);
            result = (result + (power * count) % MOD) % MOD;
            result = (result + sumN(pos + 1, cnt + 1, tight && 1 == bits[pos])) % MOD;
        }
        
        return sum_dp[pos][cnt][tight] = result;
    };
    return sumN(0, 0, true);
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    int T;
    cin >> T;
    
   	for ( ;T --; ) {
        int N;
        int K;
        cin >> N >> K;
        
        cout << find(N, K) << "\n";
    }
    
    return 0;
}