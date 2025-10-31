#include <bits/stdc++.h>
using namespace std;
#define sz(a) a.length()

vector<int> cntnxt(string s) {
  int sz = s.length();
  vector<int> p(sz);
  for(int i = 1; i < sz; i ++) {
    int g = p[i - 1];
    while(g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]); 
  }
  for(int i = 1; i < sz; i ++)
    p[i] += 1;
  return p;
}

vector<int> cnt(string s) {
  int sz = s.length();
  vector<int> p(sz);
  for(int i = 1; i < sz; i ++) {
    int g = p[i - 1];
    while(g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]); 
  }
  return p;
}


int BF(string s, string t) {
  int n = s.length(), m = t.length(), j;
  vector<int> ans;
  for(int i = 0; i < n - m + 1; i ++) {
    for(j = 0; j < m; j ++)
      if(s[i + j] != t[j]) break;
    if(j == m) return i;
  }
  return -1;
}

int KMP(string s, string t) {
  vector<int> nxt = cnt(t);
  int n = sz(s), m = sz(t), i, j = 0;
  for(i = 0; i < n; i ++) {
    while(j > 0 && s[i] != t[j]) {
      j = nxt[j - 1];
    }
    if(s[i] == t[j]) j ++;
    if(j == m) return i - m + 1;
  }
  return -1;
}



int main() {
  string s, t; cin >> s >> t;
  vector<int> ans = cntnxt(t);
  cout << "NEXT : ";
  for(auto c : ans) cout << c << ' ';
  cout << endl;
  cout << "BF : ";
  cout << BF(s, t) << endl; 
  cout << "KMP : ";
  int j = KMP(s, t);
  cout << j << endl;
}
