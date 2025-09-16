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
	int N, H, M;
    cin >> N >> H >> M;

    vector<int> dp(H + 1, -1);
    dp[H] = M; 

    int ans = 0;

    for (int i = 0; i < N; i ++) {
        int A, B;
        cin >> A >> B;
        vector<int> F(H + 1, -1);
        bool isok = false;

        for (int hp = 0; hp <= H; hp ++) {

            if (dp[hp] != -1) {
            	
                if (hp >= A) {
                    int hp_tt = hp - A;
                    int mp = dp[hp];
                    F[hp_tt] = max(F[hp_tt], mp);
                    isok = true;
                }

                if (dp[hp] >= B) {
                    int hp_tt = hp;
                    int mp = dp[hp] - B;
                    F[hp_tt] = max(F[hp_tt], mp);
                    isok = true;
                }
            }
        }

        if (!isok) {
            break;
        } 
        else {
            dp = F;
            ans ++;
        }
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
