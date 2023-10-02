#include <stdio.h>

void module1_max(int a, int b) {
    int v = a > b ? a : b;
    printf("module1 max : %d\n", v);
}