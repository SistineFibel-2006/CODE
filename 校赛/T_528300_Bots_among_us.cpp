#include <bits/stdc++.h>
using namespace std;
int getcodepoint() {
    unsigned char c = getchar();
    if (c == 255) return -1;
    if (c >> 7 == 0) return c;
    int r = 0;
    #pragma push_macro("PAT")
    #define PAT(t) \
    if (c >> t == 31 >> (t - 2) << 1) {\
        r = c & 31 >> (5 - t);\
        for (int i = 1; i <= 6 - t; ++i) {\
            c = getchar();\
            if (c >> 6 != 2) return -2;\
            r <<= 6, r |= c & 63;\
        }\
    }
    PAT(5) else PAT(4) else PAT(3) else return -2;
    #undef PAT
    #pragma pop_macro("PAT")
    return r;
}
int now1;
int count1=0;
int main(){
    while (now1 != -1){
        now1 = getcodepoint();
        if(now1 = 40)
            count1++;
        else if(now1 = 41)
            count1--;
        if(count1 < 0){
            cout << "ill-formed";
            return 0;
        }
    }
    if(count1 == 0){
        cout << "well-formed";
        return 0;
    }
    if(count1 != 0){
        cout << "ill-formed";
        return 0;
    }
}