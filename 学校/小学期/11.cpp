#include <stdio.h>
// #include <string.h>
struct stu {
  char a[100];
  int id;
  int score[3];
  float aver;
};

void average(stu *students, int n){
  for(int i = 0; i < n; i ++){
    float sum = 0;
    for(int j = 0; j < 3; j ++)
      sum += students[i].score[j];
    students[i].aver = sum / 3;
  }
}


void print(stu * students, int n){
  for(int i = 0; i < n; i ++)
    printf("%s %f\n", students[i].a, students[i].aver);
}


void input(stu s[], int n){
  for(int i = 0; i < 4; i ++)
    scanf("%s %d %d %d %d", s[i].a, &s[i].id, &s[i].score[0], &s[i].score[1], &s[i].score[2]);
}

void findmax(stu a[], int n){
  int p = -1, maxn = 0;
  for(int i = 0; i < 4; i ++)
    for(int j = 0; j < 3; j ++)
      if(a[i].score[j] > maxn)
        maxn = a[i].score[j], p = i;
  printf("HIGHEST : %s\n", a[p].a);
}

stu search(stu a[], int id, int n){
  for(int i = 0; i < n; i ++)
    if(a[i].id == id)
      return a[i];
  printf("Error to find!");
}

void SortAndPrint(stu a[], int n){
  for(int j = 0; j < n; j ++) {
    float minx = 0x3f3f3f3f; int mi = -1;
    for(int i = j; i < n; i ++)
      if(minx > a[i].aver)
        minx = a[i].aver, mi = i;
    stu tt = a[mi];
    a[mi] = a[j];
    a[j] = tt;
  }
  for(int i = 0; i < n; i ++)
    printf("%s %d %d %d %f\n",a[i].a, a[i].score[0], a[i].score[1], a[i].score[2], a[i].aver);
}

int main () {
  stu students[4];
  input(students, 4);
  average(students, 4);
  print(students, 4);
  findmax(students, 4);
  int id; scanf("%d", &id);
  auto p = search(students, id, 4);
  printf("find : %s %d %d %d %f\n", p.a, p.score[0], p.score[1], p.score[2], p.aver);
  SortAndPrint(students, 4);
}
