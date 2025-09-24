#include <bits/stdc++.h>
#include <cstddef>
using namespace std;



int rd() {
  int x;
  while(1) {
    if(cin >> x) return x;
    else {
      cout << "ERROR ! enter integer!" << '\n';
      cin.clear();
      cin.ignore(1e9, '\n');
    }
  }
}

namespace List {
  struct LstN{
    LstN * next;
    int val;
  };
  int len = 0;
  LstN * head = nullptr;
  void init() {
    head = new LstN;
    head->next = nullptr;
    puts("ListNode initing! enter length!");
    len = rd();
    puts("insert data!");
    for(int i = 0; i < len; i ++) {
      LstN * nn = new LstN;
      nn->next = head->next;
      nn -> val = rd();
      head->next = nn;
    }
  }
  LstN * rever() {
    LstN * nh = new LstN;
    nh -> next = nullptr;
    LstN * p = head->next;
    while(p) {
      LstN * nn = new LstN;
      nn -> val = p -> val;
      nn -> next = nh -> next;
      nh->next = nn;
      p = p->next;
    }
    return nh;
  }
  void output(LstN* h = nullptr) {
    if(h == nullptr) h = head;
    puts("outputing ListNODEs !");
    LstN *p = h->next;
    for(; p; p = p->next)
      cout << p->val << ' ';
    puts("");
  }
}



signed main() {
  List::init();
  puts("original List (逆序!)");
  List::output();
  auto New = List::rever();
  puts("reversed List (new!)");
  List::output(New);
}
