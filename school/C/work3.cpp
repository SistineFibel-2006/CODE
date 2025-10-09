#include <bits/stdc++.h>
using namespace std;

int st[1000];
int p = 0;
void push(int x) {
  st[p ++] = x;
}
int top(){
  return st[p - 1];
}
void pop(){
  p --;
}
bool empty(){
  return p == 0 ? 0 : 1;
}

int main () {
  char op;
  do{
    puts("输入N和M");
    int n, m; cin >> n >> m;
    stack<int> s;
    while(n) {
      s.push(n % m);
      n /= m;
    }
    while(!s.empty()) {
      cout << s.top() << ' ';
      s.pop();
    }
    puts("");
    puts("是否继续？Y/n");
    cin >> op;
  }while(op != 'n' || op != 'N');
}
