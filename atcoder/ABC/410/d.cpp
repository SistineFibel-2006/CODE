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
const int MAXN = 1005;


signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

// vector<pair<int, int>> adj[MAXN];
// int dis[MAXN];
// bool vis[MAXN];
// vector<int> cnt;
// void work(int v) {
//     for (int b : cnt) {
//         v = min(v, v ^ b);
//     }
//     if (v > 0) {
//         cnt.push_back(v);
//     }
// }
// void dfs(int u) {
//     vis[u] = true;
//     for (auto& edge : adj[u]) {
//         int v = edge.first;
//         int w = edge.second;
//         if (vis[v]) {
//             int ans1 = dis[u] ^ w ^ dis[v];
//             work(ans1);
//         } 
//         else {
//             dis[v] = dis[u] ^ w;
//             dfs(v);
//         }
//     }
// }


void solve(){
int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    
    for (int i = 0; i < M; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }

    vector<vector<bool>> vis(N + 1, vector<bool>(1024, false));
    queue<pair<int, int>> q; //BFs
    
    vis[1][0] = true;
    q.push(make_pair(1, 0));

    while (!q.empty()) {
        int u = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for (const auto& ad : adj[u]) {
            int v = ad.first;
            int w = ad.second;
            int ans1 = x ^ w;  
 
            if (!vis[v][ans1]) {
                vis[v][ans1] = true;
                q.push(make_pair(v, ans1));
            }
        }
    }

    int ans = INF;
    for (int x = 0; x < 1024; x ++) {
        if (vis[N][x]) {
            ans = min(ans, x);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;  
    } 
    else {
        cout << ans << endl; 
    }
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
