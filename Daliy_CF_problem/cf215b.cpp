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
int n;
bool check(vector<int> a, vector<int> b){
    for(int i = 1; i <= n; i ++)
        if(a[i] != b[i])
            return false;
    return true;
}

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

void solve(){
    int k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), d(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++)
	    c[i]=i;
	for(int i = 1; i <= n; i ++)
	    cin >> a[i];
	for(int i = 1; i <= n; i ++)
	    cin >> b[i];
    int s = 0, t = 0; //û��ʼ�� WA һ������
	for(int i = 1; i <= k; i ++){
		for(int j = 1; j <= n; j ++)
		    d[j]=c[a[j]];
		for(int j = 1; j <= n; j ++)
		    c[j]=d[j];
		if(check(c, b)) {
			s=i;
			break;
		}
	}
	for(int i = 1; i <= n; i ++)
	    c[i]=i;
	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= n; j ++)
		    d[a[j]]=c[j];
		for(int j = 1; j <= n; j ++)
		    c[j]=d[j];
		if(check(c, b)) {
			t=i;
			break;
		}
	}
	for(int i = 1; i <= n; i ++)
	    c[i]=i;
	if(check(c, b))
	    printf("NO");
	else if(s == 1 && t == 1 && k > 1)
	    printf("NO");
	else if((k - s) % 2 == 0 && s)
	    printf("YES");
	else if((k - t) % 2 == 0 && t)
	    printf("YES");
	else
	    printf("NO");
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
