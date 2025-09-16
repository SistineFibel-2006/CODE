#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    double ans = 0.0;

    for (int i = 0; i < n; i ++) {
        for (int j = i + 2; j < n; j ++) {
            if (S[i] == 't' && S[j] == 't') {
                int cnt = 0;
                for (int k = i; k <= j; ++k) {
                    if (S[k] == 't') {
                        cnt++;
                    }
                }
                double rate = static_cast<double>(cnt - 2) / (j - i - 1);
                if (rate > ans) {
                    ans = rate;
                }
            }
        }
    }

    cout << fixed << setprecision(17) << ans << endl;
    return 0;
}