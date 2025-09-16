#include <stdio.h>
#include <string.h>
struct stu {
  char * a;
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

stu * unp(stu *students, int n, int * cnt){
  *cnt = 0;
  static stu umpp[4];
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < 3; j ++){
      if(students[i].score[j] < 60){
        umpp[*cnt] = students[i];
        (*cnt) ++;
        break;
      }
    }
  }

  return umpp;
}

void print(stu * students, int n){
  char * name[4];
  char ** pp = name;
  for(int i = 0; i < n; i ++)
    pp[i] = students[i].a;
  
  for(int i = 0; i < n - 1; i ++)
    for(int j = 0; j < n - i - 1; j ++)
      if(strcmp(pp[j], pp[j + 1]) > 0) {
        char * tt = pp[j];
        pp[j] = pp[j + 1];
        pp[j + 1] = tt;
      }

  for(int i = 0; i < n; i ++)
    printf("%s \n", pp[i]);
}


int main () {
  stu students[4] = {
    {"zhang", 1, {88, 85, 95}, 0},
    {"wang", 2, {89, 90, 92}, 0},
    {"li", 3, {55, 65, 75}, 0},
    {"wu", 4, {80, 59, 92}, 0},
  };
  average(students, 4);
  int unpasscnt;
  stu * unpass = unp(students, 4, &unpasscnt);

  for(int i = 0; i < unpasscnt; i ++)
    printf("unpass : %s, %d\n", unpass[i].a, unpass[i].id);

  print(students, 4);
}
