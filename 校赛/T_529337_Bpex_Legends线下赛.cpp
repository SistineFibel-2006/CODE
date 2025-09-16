#include <bits/stdc++.h>
using namespace std;
int n,p;
string fuck;
int main(){
    cin >> n >> p;
    int fen[n];
    for (int i = 0; i < p ; i++){
        cin >> fuck;
        cout << fuck << " ";
        int fen123 = 0;
        for (int x = 0; x < n ; x++)
            cin >> fen[x];
        for (int x = 0; x < n ; x++){
            if (fen[x] == 1)
                fen123+=12;
            else if (fen[x] == 2)
                fen123+=9;
            else if (fen[x] == 3)
                fen123 +=7;
            else if (fen[x] == 4)
                fen123 +=5;
            else if (fen[x] == 5)
                fen123+=4;
            else if (fen[x] == 6 or fen[x] == 7)
                fen123+=3;
            else if (fen[x]>7 && fen[x] < 11)
                fen123+=2;
            else if (fen[x]>10 && fen[x] < 16)
                fen123+=1;
        }
        cout << fen123 <<endl;
    }
    return 0;
}