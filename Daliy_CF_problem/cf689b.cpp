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
const int N = 2e5 + 10;

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}
int h[N];
vector <int> adj[N];
bool vis[N];
void solve(){
	int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    adj[1].push_back(2);adj[n].push_back(n - 1);
    for(int i = 2; i <= n - 1; i ++){
        adj[i].push_back(i - 1);
        adj[i].push_back(i + 1);
    }

    auto bfs = [&]() {
        queue<int> s;
        s.push(1);
        h[1] = 0;
        while (s.size()) {
            int x = s.front();
            vis[x] = 1;
            s.pop();
            for (int v : adj[x]) {
                if (!vis[v] && (h[v] > h[x] + 1 || !h[v])) {
                    s.push(v);
                    if (h[v] > h[x] + 1 || !h[v]) h[v] = h[x] + 1;
                }
            }
        }
    };

    bfs();
    for(int i = 1; i <= n; i ++)
        cout << h[i] << ' ';
    cout << endl;
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