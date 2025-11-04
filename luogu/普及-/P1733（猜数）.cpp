#include <bits/stdc++.h>
#define int long long 
using namespace std;
int l=1, r=1000000000;
int re=0,mid;

signed main(){
    do
    {
        mid = (l+r) >> 1;
        cout << mid << endl;
        cin >> re;
        if(re = 0) break;
        else if (re = -1) l = mid;
        else r = mid;
    } while (re!=0);
    return 0;
}