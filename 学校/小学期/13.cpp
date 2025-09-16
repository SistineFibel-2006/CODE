#include <bits/stdc++.h>
using namespace std;

struct Node{
    int id;
    char * name;
    int age;
    float salary;
    Node * nxt;
};

Node *head = (Node * )malloc(sizeof(Node));
       
void create(){
    head->nxt = NULL;
    int num[] = {201,105,103,152};
    char * name[] = {"zhang", "wang", "li", "wu"};
    int age[] = {22, 25, 44, 26};
    float salary[] = {8000, 6800, 7200, 1000};
    Node * p = head;
    for(int i = 0; i < 4; i ++){
        Node * nn = (Node * )malloc(sizeof(Node));
        nn->id = num[i];
        nn->name = name[i];
        nn->age = age[i];
        nn->salary = salary[i];
        p->nxt = nn;
        p = nn;
    }
}

void output(){
    Node * p = head;
    p = head->nxt;
    for(; p; p = p->nxt)
        cout << p->id << ' ' << p->name << ' ' << p->age << ' ' << p->salary <<'\n';
    cout << '\n';
}

void search(int x){
    Node * p = head; p = head->nxt;
    for( ; p; p = p->nxt)
        if(p->id == x) {
            cout << p->id << ' ' << p->name << ' ' << p->age << ' ' << p->salary << '\n'; 
            return;
        }
    cout << "CAN NOT FINd!!!\n";
    return;
}



void remove() {
    int maxid = 0;
    Node * x = head; x = head->nxt;
    for(; x; x = x->nxt) {
        if(x->id >= maxid) {
            maxid = x->id;
        }
    }
    cout << maxid << '\n';
    Node * p = head; 
    for(; p; p = p->nxt){
        if(p->nxt->id == maxid){
            Node *t = p->nxt;
            p->nxt = t->nxt;
            t->nxt = NULL;
            return;
        }
    }
}

void sort_() {
    int ok;
    Node *p;
    Node *q = NULL;
    // cout << "1 \n";
    do {
        ok = 0;
        p = head->nxt;
        while(p->nxt != q) {
            if(p->id > p->nxt->id) {
                ok = 1;
                auto t = p->nxt;
                swap(p->age, t->age);
                swap(p->id, t->id);
                swap(p->name, t->name);
                swap(p->salary, t->salary);
            }
            p = p->nxt;
        }
        q = p;
    }while(ok != 0);

    cout << "OK\n";
}

void insert() {
    Node * nn = (Node *)malloc(sizeof(Node)); nn->nxt = NULL;
    char name[100];
    cin >> nn->id >> name >> nn->age >> nn->salary;
    nn->name = name;
    Node * p = head->nxt;
    for(; p; p = p->nxt) {
        if(nn->id > p->id && (p->nxt->id < nn->id || p->nxt == NULL)) {
            nn->nxt = p->nxt->nxt; p->nxt = nn;
        }
    }
}

signed main (){
    create();
    // output();
    // search(103); search(1001);
    // cout << '\n';
    // remove();
    cout << "\n\n\n";
    sort_();
    output();

}


// void insert(Node *head, int idx, int x){
//     Node tt = {0, head}, * p = &tt;
//     for(int i = 0; p->nxt && i < idx; i ++)
//         p = p->nxt;
//     Node *nn = (Node *)malloc(sizeof(Node));
//     nn->val = x;
//     nn->nxt = p->nxt;
//     p->nxt = nn;
// }

