#include <bits/stdc++.h>
//using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //ģ��
const int N = 5000;

int num[N];
int score[N][3];
double aver[N];
int n;

void avera(int *p){
    for(int i = 0; i < n; i ++)
        aver[i] = (*(p + i * 3) + *(p + i * 3 + 1) + *(p + i * 3 + 2)) / 3;
    for(int i = 0; i < n; i ++)
        std::cout << aver[i] << '\n';
}

void search(int t, int score[][3]){
    for(int i = 0; i < n; i ++){
        if(num[i] == t){
            std::cout << score[i][0] << ' ' << score[i][1] << ' ' << score[i][2] << '\n';
        }
    }
    puts("Error to find!");
}

void sort(int score[][3]){
    for(int i = 0; i < n; i ++){
        for(int j = i; j < n - i - 1; j ++){
            if(aver[j] < aver[j + 1]){
                std::swap(aver[j], aver[j + 1]);
                std::swap(num[j], num[j + 1]);
                for(int k = 0; i < 3; i ++)
                    std::swap(score[j][k], score[j + 1][k]);
            }
        }
    }

    for(int i = 0; i < n; i ++)
        std::cout << num[i] << ' ' << aver[i] << '\n';
}

signed main (){
    std::cin >> n;
    for(int i = 0; i < n; i ++)
        std::cin >> num[i] >> score[i][0] >> score[i][1] >> score[i][2];
    avera(*score);
    while(1){
        int x ;
        std::cin >> x;
        if(x == 0)
            break;
        std::cin >> x;
        search(x, score);
    }
    sort(score);
    return 0;
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
