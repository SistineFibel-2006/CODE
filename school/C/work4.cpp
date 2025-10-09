#include <bits/stdc++.h>
#include <cctype>
using namespace std;

char pr(char a, char b) {
  if(a == '+' || a == '-') return (b == '+' || b == '-' || b == ')' || b == '#') ? '>' : '<';
  if(a == '*' || a == '/') return b == '(' ? '<' : '>';
  if(a == '(') return b == ')' ? '=' : '<';
  if(a == '#') return b == ')' ? '?' : '<';
  return '?';
}

int main() {
  string s, in;
  double n;
  char c;
  int o;
  while(1) {
    cout << "括号匹配\n1.输入\n2.输出\n3.计算\n4.退出\n选择：";
    cin >> o;
    if(o == 1) {
      puts("输入字符串");
      cin >> s;
    } else if(o == 2) {
      cout << "String : " << s << '\n';
    } else if(o == 3) {
      stack<char> st;
      bool ok = 1;
      for(char x : s) {
        if(x == '(') st.push(x);
        else if(x == ')') {
          if(st.empty()) {ok = 0; break;}
          st.pop();
        }
      }
      if(!st.empty()) ok = 0;
      if(!ok) {
        puts("ERROR!!!!");
        continue;
      }
      stack<char> op;
      stack<double> num;
      op.push('#');
      s += '#';
      for(int i = 0; i < s.length(); ) {
        if(i < s.length() && isdigit(s[i])) {
          n = 0;
          while(i < s.length() && isdigit(s[i])) n = n * 10 + (s[i ++] - '0');
          num.push(n);
        } else {
          c = (i < s.length() ? s[i ++] : '#');
          if(c == ' ') continue;
          while(!op.empty() && pr(op.top(), c) == '>') {
            char t = op.top(); op.pop();
            double b = num.top(); num.pop();
            double a = num.top(); num.pop();
            if(t == '+') num.push(a + b);
            else if(t == '-') num.push(a - b);
            else if(t == '*') num.push(a * b);
            else num.push(a / b);
          }
          if(op.top() == '#' && c == '#') break;
          if(pr(op.top(), c) == '<') op.push(c);
          else if(pr(op.top(), c) == '>') op.pop();
          else op.pop();
        }
      } cout << "匹配成功， val = " << num.top() << '\n';
    } else break;
  }  
}
