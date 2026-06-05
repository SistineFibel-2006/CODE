#include<bits/stdc++.h>
using namespace std;


const int N = 100000;

vector<int> pri;
bool not_prime[N];

void pre(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        break;
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  pre(n);

  for(auto c : pri){
    cout << c <<", ";
    
  }

}
