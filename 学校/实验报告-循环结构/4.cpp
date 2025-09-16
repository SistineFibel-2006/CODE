#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a;
  scanf("%d", &n);
  scanf("%d", &a);
  int sum = 0;
  for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= i; j ++){
      sum += a * pow(j - 1, 10);
    }
  }
  printf("%d", sum);
  return 0;
}