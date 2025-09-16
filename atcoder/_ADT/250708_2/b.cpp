#include <bits/stdc++.h>
using namespace std;

int main () {
  string s;
  cin >> s;
  map<char, int> a;
  for(auto c : s)
    a[c] ++;
  if(a['1']== 1 && a['2'] == 2 && a['3'] == 3)
    puts("Yes");
  else
    puts("No");
}
