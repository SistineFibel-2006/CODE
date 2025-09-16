#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //ģ��


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
        puts("1.��������");
        puts("2.��ӡ����");
        puts("3.��������");
        puts("4.ɾ������");
        puts("5.��������");
        puts("0.�˳�");
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
1. С���ݣ��������ݣ��� n = 1?
2. ��Сֵ�����ֵȡ���٣��Ƿ�������
3. ��ʼֵ��û�и�ֵ����û�н�����
4. �����С���Ƿ�Խ�磿
5. ˼��������ʱ�򣬿����Ƿ�����Ƕ�������Σ������Ǹ�����ȷ���޷��������Ƿ���Է��α�����
6. ������ϸ�ķ�������?
7. ѡ��������Ƿ����Ϊ�գ�

Trick:
1.
2.
3.

About implementation skills:
1. ȫ�ֳ�������д��ĸ�����ֲ���������ʱ�������ͺ������ݵĲ���ʹ��Сд��ĸ��
2. ��ģ�⾡����ѭ����ô������ôд��
3. ����һЩ���ݺ�С����Ҫά������������Ҫ��������ʱ�����Կ��ǰ����������ɱ�����
4. д�ɶ��������
*/
