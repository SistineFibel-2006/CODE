#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;


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

namespace shunxu{
  int A[MAXN];
  int len = 0;
  void insert() {
    puts("insert data~");
    int x = rd();
    puts("index? (1-based)");
    int id = rd();
    if(id > len + 1 || id < 1) {puts("ERROR!"); return;}
    for(int i = len; i >= id ; i --)
      A[i] = A[i - 1];
    A[id - 1] = x;
    len ++;  
  }
  void del() {
    puts("del idx? (1-based)");
    int id = rd();
    if(id >= len || id < 0) {puts("ERROR!"); return;}
    for(int i = id - 1; i < len - 1; i ++)
      A[i] = A[i + 1];
    len --;
  }
  void length() {
    cout << "LENGTH : " << len << '\n';
  }
  void output() {
    puts("output :");
    for(int i = 0; i < len; i ++)
      cout << A[i] << ' ';
    puts("");
  }
  void init() {
    puts("SQlist initing! please enter your data length");
    len = rd();
    puts("enter item!");
    for(int i = 0; i < len; i ++)
      A[i] = rd();
  }

}
using namespace shunxu;

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
    LstN * p = head; 
    for(int i = 0; i < len; i ++) {
      LstN * nn = new LstN;
      nn->next = nullptr;
      nn -> val = rd();
      p->next = nn;
      p = p->next;
    }
  }
  void insert() {
    puts("insert data~");
    int x = rd();
    puts("index?");
    int id = rd();
    if(id > len + 1 || id < 1) {puts("ERROR!"); return;}
    LstN * p = head;
    for(int i = 1; i < id; i ++)
      p = p->next;
    LstN * nn = new LstN;
    nn->val = x;
    nn->next = p->next;
    p->next = nn;
    len ++;
  }
  void del() {
    puts("insert idx to delete!");
    int id = rd();
    if(id > len || id < 1) {puts("ERROR!"); return;}
    LstN * p = head;
    for(int i = 1; i < id; i ++)
      p = p->next;
    LstN * q = p->next;
    p->next = p->next->next;
    delete q;
    len --;
  }
  void printx() {
    puts("insert idx to print");
    int id = rd();
    if(id > len || id < 1) {puts("ERROR!"); return;}
    LstN * p = head -> next;
    for(int i = 1; i < id; i ++)
      p = p->next;
    cout << p->val << '\n';
  }
  void output() {
    puts("outputing ListNODEs !");
    LstN *p = head->next;
    for(; p; p = p->next)
      cout << p->val << ' ';
    puts("");
  }
}

signed main() {
  shunxu::init();
  List::init();
  while(1) {
    puts("Insert option!");
    puts("1 顺序表插入");
    puts("2 顺序表删除");
    puts("3 顺序表长度");
    puts("4 顺序表输出");
    puts("5 链表插入");
    puts("6 链表删除");
    puts("7 链表第i个");
    puts("8 链表输出");
    puts("9 退出？(Y/n)");
    int op; cin >> op;
    if(op == 9) {
      puts("Sure? Y/ n");
      char y; cin >> y;
      if(y == 'Y' || y == 'y')
        return 0;
    } 
    if(op == 1) {
      shunxu::insert();
    }
    else if(op == 2) {
      shunxu::del();
    }
    else if(op == 3) {
      shunxu::length();
    }
    else if(op == 4) {
      shunxu::output();
    }
    else if(op == 5)
      List::insert();
    else if(op == 6)
      List::del();
    else if(op == 7)
      List::printx();
    else if(op == 8)
      List::output();
  }
}
