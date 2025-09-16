#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //ģ��


signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

const int N = 2e5 + 5;
vector<int > v[N], ans;
int a[N], b[N];
int dfs(int x) {
    ans.push_back(x);
    a[x] = ans.size();
    int now = 0;
    for(int i = 0; i < v[x].size(); i ++)
        now += dfs(v[x][i]);
    return b[x] = now + 1;
}
void solve(){
    int n, q;
    cin >> n >> q;

    for(int i = 2; i <= n; i ++){
        int t; cin >> t;
        v[t].push_back(i);
    }

    dfs(1);

    for(int i = 1; i <= q; i ++){
        int x, y;
        cin >> x >> y;
        if(b[x] < y)
            cout << -1 << endl;
        else
            cout << ans[a[x] + y - 2] << endl;
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
