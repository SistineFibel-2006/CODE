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

void solve(){
    vector<int> vis(123, 0), flag(1000, 0);
    string s;
    char q;
    int n, ans = 0;
    bool dian = false;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> q >> s;
        if (dian) {
            if (q != '.')
                ans++;
            continue;
        }
        if (q == '!') {
            fill(all(vis), 0);
            for (int j = 0; j < s.length(); j++) {
                vis[s[j]] = true;
                flag[s[j]] = flag[s[j]] != -1 ? 1 : flag[s[j]];
            }
            for (char j = 'a'; j <= 'z'; j++)
                if (!vis[j])
                    flag[j] = -1;
        }
        else if (q == '.')
            for (int j = 0; j < s.length(); j++)
                flag[s[j]] = -1;
        else
            flag[s[0]] = -1;
        int cnt = 0, f = 0;
        for (char j = 'a'; j <= 'z'; j++) {
            if (flag[j] == 1)
                cnt++;
            else if (flag[j] == -1)
                f++;
        }
        if (cnt == 1 || f == 25) { //��֤�Ƿ�ֻʣһ��
            dian = true;
        }
    }
    cout << ans;
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
