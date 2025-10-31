#include <bits/stdc++.h>
using namespace std;

struct State {
    int prev_c, prev_s;
    int s_val, c8;
    State(): prev_c(-1), prev_s(-1), s_val(-1), c8(-1) {}
};


void solve() {
	int N;
  cin >> N;
  int S = 81181819 - N;
  
  vector<int> digits(8);
  int tmp = S;
  for (int i = 0; i < 8; i++) {
    digits[i] = tmp % 10;
    tmp /= 10;
  }
  
  bool found = false;
  int k_found = -1;
  vector<int> s_vals(8), c8_vals(8);
  
  for (int k = 1; k <= 9 && !found; k++) {
    int max_carry = 8 * k;
    vector<vector<vector<bool>>> dp(9, 
        vector<vector<bool>>(max_carry + 1, 
        vector<bool>(k + 1, false)));
    vector<vector<vector<State>>> prev(9,
        vector<vector<State>>(max_carry + 1,
        vector<State>(k + 1)));
    
    dp[0][0][0] = true;
    
    for (int pos = 0; pos < 8; pos++) {
      for (int carry = 0; carry <= max_carry; carry++) {
        for (int slots = 0; slots <= k; slots++) {
          if (!dp[pos][carry][slots]) continue;
          
          int need = (digits[pos] - carry) % 10;
          if (need < 0) need += 10;
          
          for (int s = need; s <= 8 * k; s += 10) {
            int total = s + carry;
            if (total < digits[pos]) continue;
            int new_carry = (total - digits[pos]) / 10;
            if (new_carry > max_carry) continue;
            
            int min_c8 = max(0, (s - k + 6) / 7);
            int max_c8 = min(k, s / 8);
            
            for (int c8 = min_c8; c8 <= max_c8; c8++) {
              int slots_add = s - 7 * c8;
              if (slots_add < 0) continue;
              int new_slots = min(k, slots + slots_add);
              
              if (!dp[pos + 1][new_carry][new_slots]) {
                dp[pos + 1][new_carry][new_slots] = true;
                State st;
                st.prev_c = carry;
                st.prev_s = slots;
                st.s_val = s;
                st.c8 = c8;
                prev[pos + 1][new_carry][new_slots] = st;
              }
            }
          }
        }
      }
    }
    
    if (dp[8][0][k]) {
      found = true;
      k_found = k;
      int carry = 0, slots = k;
      for (int pos = 8; pos > 0; pos--) {
          State st = prev[pos][carry][slots];
          s_vals[pos - 1] = st.s_val;
          c8_vals[pos - 1] = st.c8;
          carry = st.prev_c;
          slots = st.prev_s;
      }
      break;
    }
  }
  
  if (!found) {
      cout << S << '\n';
      for (int i = 0; i < S; i++) cout << "1\n";
    	return;
  }
  
  int k = k_found;
  vector<string> nums(k, string(8, '0'));
  vector<int> need_zero;
  for (int i = 0; i < k; i++) need_zero.push_back(i);
  
  for (int pos = 0; pos < 8; pos++) {
      int c8 = c8_vals[pos];
      int c1 = s_vals[pos] - 8 * c8;
      
      while (c8 > 0 && !need_zero.empty()) {
          int idx = need_zero.back();
          need_zero.pop_back();
          nums[idx][pos] = '8';
          c8--;
      }
      
      while (c1 > 0 && !need_zero.empty()) {
          int idx = need_zero.back();
          need_zero.pop_back();
          nums[idx][pos] = '1';
          c1--;
      }
      
      int idx = 0;
      while (c8 > 0) {
          nums[idx % k][pos] = '8';
          idx++;
          c8--;
      }
      
      idx = 0;
      while (c1 > 0) {
          if (nums[idx % k][pos] == '0') {
              nums[idx % k][pos] = '1';
              c1--;
          }
          idx++;
      }
  }
  
  cout << k << '\n';
  for (int i = 0; i < k; i++) {
    string num = nums[i];
    reverse(num.begin(), num.end());
    int start = 0;
    while (start < 7 && num[start] == '0') start++;
    cout << num.substr(start) << '\n';
  }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}