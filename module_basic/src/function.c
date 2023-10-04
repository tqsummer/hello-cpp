#include <stdio.h>
#include "my_math.h"

//swap声明函数
//extern void swap(int a, int b);
//void swap(int a, int b);
void swap(int, int);


void main_function_swap01() {
    swap(1, 2);
}

void main_function_my_math01() {
    int max = my_max(1, 2);
    printf("a = 1 ,b = 2,max : %d", max);
    printf("");
}

int main() {
    main_function_my_math01();
    return 0;
}

//swap函数实现
void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
    printf("a = %d , b = %d \n", a, b);
}



