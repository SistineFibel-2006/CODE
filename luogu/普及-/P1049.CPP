#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int V,n;
int p=1;
int max1[30];
int i[30];
int num=0;
int main(){
    max1[0]=0;
    cin >> V >> n;
    for (int a=0;a<n;a++) {cin >> i[a];};
    sort(i,i[n]);
    while(1){
        max1[p]= max1[p] + i[p];
        if (max1[p]>V){
            max1[p] = max1[p] - max1[num];
            num++;
        }
        if (max1[p-1]>=max1[p-2] and max1[p-1]<=max1[p]){
            break;;
        };
    };
    cout << V-max1[p-1];
    return 0;
}