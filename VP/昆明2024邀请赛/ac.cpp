#include <bits/stdc++.h>
using namespace std;
#define int long long
#define se second
#define fi first
const int MN = 1e5 + 10;
const int INF = 1e9;
int point_x[MN];
int point_y[MN];
int n;
int qiu_S(int L,int R){
    vector<pair<int,int> > po;
    int tt = 0;
    for(int i = L; i != R; ) {
        pair<int , int> temp;
        temp.fi = point_x[i]; temp.se = point_y[i];
        po.push_back(temp);
        i --;tt ++;
        if(i == (-1))
        i = (n - 1);
    }
    vector<pair<int,int> > vec;
    for(int i = 0; i < tt; i ++){
        pair<int , int> temp;
        temp.fi = po[i].fi - point_x[R];
        temp.fi = po[i].se - point_y[R];
        vec.push_back(temp);
    }
    int ansS = 0;
    for(int i = 0; i < tt - 1; i ++)
        ansS += abs(vec[i].fi * vec[i + 1].se - vec[i + 1].fi * vec[i].se);

    return ansS;
}
void solve() {
    int px,py,r;
    cin >> n >> px >> py >> r;
    
    double dis[n+10];
    for(int i=0;i<n;i++){
        cin >> point_x[i] >> point_y[i];
    }
    for(int i=0;i<n-1;i++){
        int A=point_y[i+1]-point_y[i];
        int B=point_x[i]-point_x[i+1];
        int C=-(point_x[i]*(point_y[i+1]-point_y[i])+point_y[i]*(point_x[i+1]-point_x[i]));
        dis[i]=abs((A*px+B*py+C)/sqrt(A*A+B*B));
    }
    int p;
    for(int i=0;i<n-1;i++){
        int nmin=INF;
        if(dis[i]<nmin){
            nmin=dis[i];
            p=i;
        }
    }
    int L=p-1,R=p+2;
    while(abs(L-R)>1){
        if(L==-1){
            L=n-1;
        }
        if(R==n){
            R=0;
        }
        int A=point_y[L]-point_y[R];
        int B=point_x[R]-point_x[L];
        int C=-(point_x[R]*(point_y[L]-point_y[R])+point_y[R]*(point_x[L]-point_x[R]));
        int dis_t=abs((A*px+B*py+C)/sqrt(A*A+B*B));
        if(dis_t>=r){
            cout << qiu_S(L, R) << endl;
            return;
        }

        int s1=-1,s2=-1;//mianji

        int save_L=L;
        L--;
        if(L==-1){
            L=n-1;
        }
        A=point_y[L]-point_y[R];
        B=point_x[R]-point_x[L];
        C=-(point_x[R]*(point_y[L]-point_y[R])+point_y[R]*(point_x[L]-point_x[R]));
        dis_t=abs((A*px+B*py+C)/sqrt(A*A+B*B));
        if(dis_t>=r){
            s1=qiu_S(L,R);
        }


        int save_R=R;
        R++;
        L=save_L;
        if(R==n){
            R=0;
        }
        A=point_y[L]-point_y[R];
        B=point_x[R]-point_x[L];
        C=-(point_x[R]*(point_y[L]-point_y[R])+point_y[R]*(point_x[L]-point_x[R]));
        dis_t=abs((A*px+B*py+C)/sqrt(A*A+B*B));
        if(dis_t>=r){
            s2=qiu_S(L,R);
        }

        if(s1==-1&&s2==-1){
            L=save_L;
            R=save_R;
            L--;
            R++;
        }
        else{
            cout << max(s1,s2) << endl;
            return;
        }
    }
}

signed main () {
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}