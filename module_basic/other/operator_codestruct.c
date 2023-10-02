#include "stdio.h"

#define bool int
#define True 1
#define False 0

int main_goto() {

    bool flag = False;

    if (flag) {
        printf("before goto End1\n");
        goto End1;
        printf("after goto End1\n");

    } else {
        printf("before goto End2\n");
        goto End2;
        printf("after goto End2\n");
    }


    End1:
    {
        printf("The End1 code\n");
    }

    End2:
    {
        printf("The End2 code\n");
    }

    int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_len = sizeof(num) / sizeof(num[0]);
    printf("sizeof num : %d , num length : %d \n", sizeof(num), num_len);


    return 0;
}

int main() {
    main_goto();
    return 0;
}