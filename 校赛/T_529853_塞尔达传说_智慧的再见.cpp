#include <bits/stdc++.h>
using namespace std;
long long int a,b;
int main(){
    cin >> a >> b;
    if (a == 0 && b == 0) {
        cout << "-1";
        return 0;
    }
    if (a == 0 or b == 0){
        cout << "1";
        return 0;
    }
    if (a != b){
        cout << "1";
        return 0;
    }
    if (a == b){
        cout << "0";
        return 0;
    }
}