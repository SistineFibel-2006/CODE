#include <iostream>
using namespace std;

int main() {
    int T;  
    cin >> T;
    while (T--) {
        int n;  
        cin >> n;

        int a, b, countA = 0, countB = 0;
        bool is = 1;
        cin >> a;  
        countA ++;
        int f = 0;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            if (x == a) {
                countA++; 
                f = 1;
            } else if (countB == 0) {
                b = x; 
                countB++;
            } else if (x == b) {
                countB++; 
            } else {
                is = 0; 
            }
        }

        //cerr << countA << " " <<countB << " " <<f; 
        if (is && countA == countB && n % 2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}