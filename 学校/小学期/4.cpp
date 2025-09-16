#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数


typedef struct Node{
    int val;
    Node * nxt;
}Node;

Node * create(int n){
    Node * head = NULL, *tail = NULL;
    for(int i = 0, x; i < n; i ++){
        cin >> x;
        Node *nn = (Node *)malloc(sizeof (Node));
        nn->val = x;
        nn->nxt = NULL;
        if(!head)
            head = tail = nn;
        else
            tail = tail->nxt = nn;
    }
    return head;
}

void output(Node *head){
    for(; head; head = head->nxt)
        cout << head->val <<' ';
    cout << '\n';
}

int search(Node *head, int x){
    for(int p = 1; head; head = head->nxt)
        if(head->val == x)
            return p;
    return -1;
}

void remove(Node *head, int x) {
    Node tt = {0, head}, * p = &tt;
    for(; p->nxt; p = p->nxt){
        if(p->nxt->val == x){
            Node *t = p->nxt;
            p->nxt = t->nxt;
            t->nxt = NULL;
            return;
        }
    }
    puts("ERROR to remove");
}

void insert(Node *head, int idx, int x){
    Node tt = {0, head}, * p = &tt;
    for(int i = 0; p->nxt && i < idx; i ++)
        p = p->nxt;
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->val = x;
    nn->nxt = p->nxt;
    p->nxt = nn;
}

signed main (){
int n, p;
    Node * head = NULL;
    while(1){
        puts("1.创建数组");
        puts("2.打印数组");
        puts("3.查找数据");
        puts("4.删除数据");
        puts("5.插入数据");
        puts("0.退出");
        int y;
        cin >> y;
        if(y == 0)
            break;
        switch (y){
            case 1:
                cin >> n;
                head = create(n);
                break;
            case 2:
                output(head);
                break;
            case 3:
                cin >> n;
                p = search(head, n);
                if(p != -1)
                    cout << p << '\n';
                else
                    cout << "can not find\n";
                break;
            case 4:
                cin >> n;
                remove(head, n);
                break;
            case 5:
                int idx, y; cin >> idx >> y;
                insert(head, idx, y);
                break; 
        }
    }
}



void solve(){
    
}
//test
/*
?
// ? (?????) ?
*/

/*
What's wrong with my code?
1. 小数据？特殊数据？如 n = 1?
2. 最小值，最大值取多少？是否会溢出？
3. 初始值有没有赋值？有没有建树？
4. 数组大小？是否越界？
5. 思考暴力的时候，考虑是否可能是多个连续段？或者是个数不确定无法暴力？是否可以分治暴力？
6. 进行详细的分类讨论?
7. 选择的区间是否可以为空？

Trick:
1.
2.
3.

About implementation skills:
1. 全局常量均大写字母，而局部变量，临时变量，和函数传递的参数使用小写字母。
2. 大模拟尽量遵循：怎么方便怎么写。
3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
4. 写成多个函数。
*/
