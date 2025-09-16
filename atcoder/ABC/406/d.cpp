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


signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

void solve(){
	int H, W, N;
    cin >> H >> W >> N;

    vector<unordered_set<int>> row(H + 1), col(W + 1);
    vector<int> X(N), Y(N);

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;
        row[x].insert(i);
        col[y].insert(i);
    }

    vector<bool> erased(H + 1, 0), removed(W + 1, 0);

    int Q;
    cin >> Q;

    while (Q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            if (erased[x]) {
                cout << 0 << '\n';
                continue;
            }

            int ans = row[x].size();
            cout << ans << '\n';

            for (int i : row[x]) {
                int y = Y[i];
                col[y].erase(i);
            }

            row[x].clear();
            erased[x] = 1;
        } else {
            if (removed[x]) {
                cout << 0 << '\n';
                continue;
            }

            int ans = col[x].size();
            cout << ans << '\n';

            for (int i : col[x]) {
                int x_row = X[i];
                row[x_row].erase(i);
            }

            col[x].clear();
            removed[x] = 1;
        }
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