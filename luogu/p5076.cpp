#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x7fffffff;
const long long MOD = 1e9; //ģ��

multiset<int>q;

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
    int i,j,n,x,y;
    cin>>n;
    vector <int> tr;
    for(i=0;i<n;i++){
        cin >> x >> y;
        if(x == 5){
            if(tr.empty()) tr.push_back(y);
            else{
                auto it = upper_bound(tr.begin(),tr.end(),y);
                tr.insert(it, y);
            }
        }
        else if(x == 1){
            auto it = lower_bound(tr.begin(),tr.end(),y);
            cout<<it-tr.begin()+1<<endl;
        }
        else if(x == 2){
            cout<<tr[y-1]<<endl;
        }
        else if(x == 3){
            auto it = lower_bound(tr.begin(),tr.end(),y);
            cout<<*(it-1)<<endl;
        }
        else{
            auto it = upper_bound(tr.begin(),tr.end(),y);
            if(it != tr.end()) cout<<*it<<endl;
            else cout<<"2147483647"<<endl;
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