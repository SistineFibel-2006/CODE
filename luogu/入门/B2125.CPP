#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000;
struct n {
    int a[MAXN];
    string b[MAXN];
};

struct n tx;
int x;
int main(){
    cin >> x;
    for (int i=0 ; i < x ; i++ ) cin >> tx.a [i] >> tx.b [i];
    sort(tx , tx+x-1);
    cout << tx.b[x-1];
    return 0;
}