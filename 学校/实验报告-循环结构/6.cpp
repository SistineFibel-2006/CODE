#include<bits/stdc++.h>
using namespace std;
int main(){
  for(int i = 1; i <= 9; i ++){
    int a = i * i;
    if(a % 10 == i)
      printf("%d\n", i);
  }
  for(int i = 10; i < 100; i ++){
    int a = i * i;
    if(a % 100 == i)
      printf("%d\n", i);
  }
  return 0;
}