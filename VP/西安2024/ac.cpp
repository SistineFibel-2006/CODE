#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f;


signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int a,b;
    cin >> a >> b;
    if(a==b){
        cout <<(a*(a-1)/2+a) << endl;
    }
    else if(a%2==0||b%2==0){

        cout << (a*b/2) << endl;

    }
    else{
        cout << ((a*b+1)/2) << endl;
    }



    return 0;
}