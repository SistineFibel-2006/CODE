#include <stdio.h>
#include <stdlib.h>

typedef enum {
  teacher, student
}ocu;

struct peo{
  int id;
  char name[100];
  ocu ocu;
  union el{int class1; char title[100];}el;
}a[10];

typedef struct node{
  struct peo data;
  node * nxt;
}List;


void create() {
  for(int i = 0; i < 10; i ++) {
    scanf("%d %s", &a[i].id, a[i].name);
    // puts("input 0 if it is a teacher and 1 for student");
    int n;
    scanf("%d", &n);
    a[i].ocu = (ocu)n;
    if(a[i].ocu == student) 
      scanf("%d", &a[i].el.class1);
    else
      scanf("%s",a[i].el.title);   
  }
  return;
}

void printarray() {
  for(int i = 0; i < 10; i ++) {
    printf("%d %s %d ", a[i].id, a[i].name, a[i].ocu);
    if(a[i].ocu == teacher)
      printf("%s\n", a[i].el.title);
    else
      printf("%d\n", a[i].el.class1);
  }
}

void save() {
  const int n = 10;
  FILE *fp = fopen("stupro.dat", "wb");
  if(fp == NULL) return;
  fwrite(&n, sizeof(int), 1, fp);
  for(int i = 0; i < n; i ++)
    fwrite(&a[i], sizeof(peo), 1, fp);
  fclose(fp);
}

List * head, * tail;
void init() {
  head = (List *)malloc(sizeof(List));
  head->nxt = NULL;
}
void load() {
  FILE *fp = fopen("stupro.dat", "rb");
  if(fp == NULL) return;
  tail = head;
  const int n = 10;
  for(int i = 0; i < n; i ++) {
    List * nn = (List *)malloc(sizeof(List));
    fread(&nn->data, sizeof(peo), 1, fp);
    nn->nxt = NULL;
    tail->nxt = nn;
    tail = nn;
  }
  fclose(fp);
}

void printlist() {
  List * p = head->nxt;
  for(;p;p = p->nxt) {
    printf("%d %s %d ", p->data.id, p->data.name, p->data.ocu);
    if(p->data.ocu == teacher)
      printf("%s\n",p->data.el.title);
    else
      printf("%d\n",p->data.el.class1);
  }
}

void remove() {
  int x; scanf("%d", &x);
  List * p = head;
  for(;p;p = p->nxt) {
    if(p->nxt->data.id == x) {
      if(p->nxt->nxt != NULL)
        p->nxt = p->nxt->nxt;
      else
        p->nxt = NULL;
    }
  }
}

void insert() {
  peo b;
    scanf("%d %s", &b.id, b.name);
    // puts("input 0 if it is a teacher and 1 for student");
    int n;
    scanf("%d", &n);
    b.ocu = (ocu)n;
    if(b.ocu == student) 
      scanf("%d", &b.el.class1);
    else
      scanf("%s", b.el.title);
  List * nn = (List *)malloc(sizeof(List));
  nn->data = b;
  List * p = head;
  for(;p;p = p->nxt) {
    if(p->nxt->data.id < nn->data.id && p->nxt->nxt->data.id > nn->data.id) {
      nn->nxt = p->nxt->nxt->nxt;
      p->nxt->nxt = nn;
    }
    else if(p->nxt->data.id < nn->data.id && p->nxt->nxt == NULL) {
      p->nxt->nxt = nn;
      nn->nxt = NULL;
    }
    else if(p == head && nn->data.id < p->nxt->data.id) {
      nn->nxt = p->nxt;
      head->nxt = nn;
    }
  }   
}

signed main() {
  create();  
  printarray();
}
