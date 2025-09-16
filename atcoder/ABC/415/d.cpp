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


struct all {
    long long A, B, C; 
    int id;
};

bool comparealls(const all& a, const all& b) {
    if (a.A != b.A) {
        return a.A < b.A;
    }
    return a.C < b.C;
}

const all& better_deal(const all& a, const all& b) {
    if (a.C < b.C) {
        return a;
    }
    if (b.C < a.C) {
        return b;
    }
    if (a.A < b.A) {
        return a;
    }
    return b;
}
signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

void solve(){
    int n;
    int m;
    cin >> n >> m;

    vector<all> alls(m);
    for (int i = 0; i < m; ++i) {
        alls[i].id = i;
        cin >> alls[i].A >> alls[i].B;
        alls[i].C = alls[i].A - alls[i].B;
    }

    sort(alls.begin(), alls.end(), comparealls);

    vector<all> pre(m);
    pre[0] = alls[0];
    for (int i = 1; i < m; ++i) {
        pre[i] = better_deal(pre[i - 1], alls[i]);
    }

    int now = n;
    int ans = 0;

    while (true) {
        auto it = upper_bound(alls.begin(), alls.end(), now, 
            [](int val, const all& ex) {
            return val < ex.A;
        });

        if (it == alls.begin()) {
            break;
        }

        int idx = distance(alls.begin(), it) - 1;

        const all& best = pre[idx];
        
        int ax = best.A;
        int cx = best.C;

        if (now < ax) {
            break;
        }

        int sum = (now - ax) / cx + 1;

        ans += sum;
        now -= sum * cx;
    }

    cout << ans << endl;
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
