#include <stdio.h>

void module1_min2(int a, int b) {
    int v = a < b ? a : b;
    printf("module1 min2 : %d\n", v);
}