#include <bits/stdc++.h>
//using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数
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
1. 小数据？特殊数据？如 n = 1?
2. 最小值，最大值取多少？是否会溢出？
3. 初始值有没有赋值？有没有建树？
4. 数组大小？是否越界？
5. 思考暴力的时候，考虑是否可能是多个连续段？或者是个数不确定无法暴力？是否可以分治暴力？
6. 进行详细的分类讨论?
7. 选择的区间是否可以为空？

Trick:
1.
2.
3.

About implementation skills:
1. 全局常量均大写字母，而局部变量，临时变量，和函数传递的参数使用小写字母。
2. 大模拟尽量遵循：怎么方便怎么写。
3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
4. 写成多个函数。
*/
