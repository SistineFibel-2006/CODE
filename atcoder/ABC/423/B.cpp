#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; ++i) 
        cin >> L[i];
    

    int r = 0;
    for (int i = 0; i < N; i ++) {
        if (L[i] == 1) {
            r = i;
            break;
        }
        if (i == N - 1) 
            r = N;
    }

    int l = N;
    for (int i = N - 1; i >= 0; i --) {
        if (L[i] == 1) {
            l = i + 1;
            break;
        }
        if (i == 0) 
            l = 0;
    }
    
    int ans = max(0, l - r - 1);
    
    cout << ans << endl;

    return 0;
}