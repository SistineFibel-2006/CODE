#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;

int add(int a,int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int mul(long long a,long long b){ return int((a*b)%MOD); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> qs(T);
    int nmax = 0;
    for(int i = 0; i < T; i++){
        cin >> qs[i];
        nmax = max(nmax, qs[i]);
    }

    // 预处理到 nmax
    vector<int> S0(nmax+1), S1(nmax+1), S2(nmax+1), S3(nmax+1);
    S0[0] = 1;  // 0! = 1
    S1[0] = S2[0] = S3[0] = 0;

    for(int n = 1; n <= nmax; n++){
        // S0 = n!
        S0[n] = mul(S0[n-1], n);
        // 递推 S1, S2, S3
        // S1(n)=n*S1(n-1)+S0(n-1)
        S1[n] = add( mul(n, S1[n-1]), S0[n-1] );
        // S2(n)=n*S2(n-1)+2*S1(n-1)+S0(n-1)
        S2[n] = add( add( mul(n, S2[n-1]),
                          mul(2, S1[n-1]) ),
                     S0[n-1] );
        // S3(n)=n*S3(n-1)+3*S2(n-1)+3*S1(n-1)+S0(n-1)
        int t = add( mul(3, S2[n-1]),
                     mul(3, S1[n-1]) );
        S3[n] = add( add( mul(n, S3[n-1]), t ),
                     S0[n-1] );
    }

    // 回答查询
    for(int x: qs){
        cout << S3[x] << "\n";
    }
    return 0;
}
