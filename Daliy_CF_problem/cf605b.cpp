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
	int n, m;
    cin >> n >> m;
    vector<pair<int, int > > part, notp;
    vector<pair<int, int > > ans(m);
    int p = 0;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        if(b == 1)
            part.push_back({a, i});
        else
            notp.push_back({a, i}), p ++;
    }
    if(part.size() >= n) {puts("-1"); return;}
    sort(all(part)); sort(all(notp));
    for(int i = 1; i <= part.size(); i ++)
        ans[part[i - 1].second] = {i, i + 1};
    int s = 0, cnt = 1;
    for(int i = 0; i < notp.size(); i ++){
        if(notp[i].first >= part[s + 1].first) {
            ans[notp[i].second] = {cnt, s + 3};
            cnt --;
            if(cnt == 0){
                cnt = s + 2;
                s ++;
            }
        }
        else {puts("-1"); return;}
    }

    for(auto c : ans)
        cout << c.first << ' ' << c.second << endl;
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