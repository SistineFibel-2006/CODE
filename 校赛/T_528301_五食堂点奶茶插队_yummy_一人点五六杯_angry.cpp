#include <bits/stdc++.h>
using namespace std;

long long int n,x,p,a;
long long int ans;
int main(){
    cin >> n >> x >> p;
    int tap=0;
    for (int i = 0;i < n + 2 ; i++){
        cin >> a;
        if(a > 0){
            ans += ((a%p)*((x^i)%p)) % p;
        }
        else if (a == 0)
            ans += 0;
        else {
            ans += (p- ((a%p)*((x^i)%p)) % p);
        }
    }
    cout << ans%p;
}