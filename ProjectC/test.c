#include <stdio.h>

#define STR(x) #x
#define CONCAT(a, b) a##b
#define add(a,b) a+b 

int main() {
    int ab = 10, a = 2, b = 6;
    printf("%s", STR(CONCAT(a, b)));
}// 7 8 2 6

