#include <bits/stdc++.h>
using namespace std;

string hx;
string dw;
long long int h=1,d=1;
int main(){
    cin >> hx >> dw;
    for(long unsigned int i=0;i<hx.length();i++) h *= hx[i] - 'A' + 1;
    for(long unsigned int i=0;i<dw.length();i++) d *= dw[i] - 'A' + 1;
    if(h % 47 == d % 47) cout << "GO";
    else cout << "STAY";
    return 0;
}