#include <string.h>
#include "stdio.h"
#include "string.h"


void main_array_name01() {
    int a[5];
    printf("&a[0] address : %u\n", &a[0]);
    printf("a address : %u\n", a);
    printf("&a address : %u\n", &a);

    printf("-------------add 1--------------\n");

    printf("&a[0]+1 address : %u\n", &a[0] + 1);
    printf("a+1 address : %u\n", a + 1);
    printf("&a+1 address : %u\n", &a + 1);

    /**
     * 执行结果
     * &a[0] address : 322959232
     * a address : 322959232
     * &a address : 322959232
     * -------------add 1--------------
     * &a[0]+1 address : 322959236
     * a+1 address : 322959236
     * &a+1 address : 322959252
     *
     */
}

void main_array_swap01() {
    //数组元素交换
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    int size = sizeof(a) / sizeof(a[0]);
    int j = size - 1;
    int tmp;

    printf("------------before swap elements------------\n");
    for (int k = 0; k < size; k++) {
        printf("a[%d] = %d\n", k, a[k]);
    }

    while (i < j) {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }

    printf("------------after swap elements------------\n");

    for (int k = 0; k < size; k++) {
        printf("a[%d] = %d\n", k, a[k]);
    }

}

void main_array_sort01() {
    //数组元素冒泡排序
    int a[10] = {2, 1, 5, 7, 3, 6, -7, -8, 9, -10};
    int n = sizeof(a) / sizeof(a[0]);
    int temp;
    printf("------------before sort elements------------\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    for (int i = 0; i < n - 1; i++) { //比较的轮数 size-1轮
        for (int j = 0; j < n - 1 - i; j++) { //比较的次数
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("------------after sort elements------------\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

}

void main_array_init01() {
    int a[5] = {1, 2, 3, 4, 5};

    //二维数组部分元素初始化，其他元素为0
    int aa1[3][4] = {{11, 12, 13, 14},
                     {12, 13, 14, 15},
                     {13, 14, 15, 16}};

    int aa2[3][4] = {{21, 22, 23},
                     {22, 23, 24, 25},
                     {23, 24, 25}};

    int aa3[3][4] = {31,
                     32,
                     33,
                     34,
                     35,
                     36};
    //二维数组定义时，不能省略列的下标，可以省略行的下标
    int aa4[][4] = {41, 42, 44, 45, 46, 47};

    int row1 = sizeof(aa1) / sizeof(aa1[0]);
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < 4; j++) {
            printf("aa1[%d][%d]=%d\n", i, j, aa1[i][j]);
        }
    }
    printf("----------------------------------\n");

    int row2 = sizeof(aa2) / sizeof(aa2[0]);
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("aa2[%d][%d]=%d\n", i, j, aa2[i][j]);
        }
    }
    printf("----------------------------------\n");

    int row3 = sizeof(aa3) / sizeof(aa3[0]);
    for (int i = 0; i < row3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("aa3[%d][%d]=%d\n", i, j, aa3[i][j]);
        }
    }
    printf("----------------------------------\n");

    int row4 = sizeof(aa4) / sizeof(aa4[0]);
    for (int i = 0; i < row4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("aa4[%d][%d]=%d\n", i, j, aa4[i][j]);
        }
    }
    printf("----------------------------------\n");
}

void main_array_init02() {
    char s1[7] = {'1', 'e', 'l', 'l', 'o', '1', '\0'};

    char s2[8] = {'2', 'e', 'l', 'l', 'o', '2', '\0', 'a'};

    char s3[] = "hello3";

    int s1_size = sizeof(s1) / sizeof(s1[0]);
    printf("-------------s1 size : %d------------\n", s1_size);
    for (int i = 0; i < s1_size; i++) {
        printf("%c", s1[i]);
    }
    printf("\n");
    printf("s1 str : %s\n", s1);

    int s2_size = sizeof(s2) / sizeof(s2[0]);
    printf("-------------s2 size : %d------------\n", s2_size);
    for (int i = 0; i < s2_size; i++) {
        printf("%c", s2[i]);
    }
    printf("\n");
    printf("s2 str : %s\n", s2);

    int s3_size = sizeof(s3) / sizeof(s3[0]);
    printf("-------------s3 size : %d------------\n", s3_size);
    for (int i = 0; i < s3_size; i++) {
        printf("%c", s3[i]);
    }
    printf("\n");
    printf("s3 str : %s\n", s3);

    char s4[10] = "hello4";
    int s4_size = sizeof(s4) / sizeof(s4[0]);
    printf("-------------s4 size : %d------------\n", s4_size);
    printf("s4 ascii :");
    for (int i = 0; i < sizeof(s4) / sizeof(s4[0]); i++) {
        printf(" %d", s4[i]);
    }
    printf("\n");


    printf("\n");
    char s5[6] = {'h', 'e', 'l', 'l', 'o', '5'};
    printf("s5 str : %s\n", s5);

}

void main_array_init03() {
    char s5[6] = {'h', 'e', 'l', 'l', 'o', '5'};
    printf("s5 str : %s\n", s5);
}

void main_array_stdin01() {
    char a[128] = "";

    /**
     * 1.%要求传的参数是存放读取字符串的地址
     * 2.scanf(%s)遇到\n结束并且遇到空格也结束
     * 3.键盘输入 hello world,a字符串得到的是：hello
     * 4.如果存放读取字符的空间不足，继续向后存放，会造成内存污染
     */
    scanf("%s", a);
    printf("a = %s\n", a);
}

void main_array_stdin02() {
    char a[128] = "";
    /**
     * 1.()里面的参数要的是存放读取字符串的地址
     * 2.gets遇到\n结束，但是遇到空格不结束
     * 3.键盘输入 hello world,a字符串得到的是：hello world
     * 4.也会造成内存污染
     */
    gets(a);
    printf("a = %s\n", a);
}


/**
 * 自定义strlen函数
 * @param buf
 * @return
 */
int my_strlen(const char buf[]) {
    int i = 0;
    while (buf[i] != '\0') {
        i++;
    }
    return i;
}

void main_array_stdin03() {
    char buf[10] = "";
    /**
     * 1.参数1：buf读取后存放的字符数组，参数2：sizeof(buf)最大读取的字节数，参数3：stdin键盘标准输入
     * 2.键盘输入 hello world,buf字符串得到的是：hello wor（9个可见字符：hello wor，1个不可见字符：\0，正好10个字符）
     * 3.不会造成内存污染
     * 4.如果buf空间足，最后键盘输入的回车键\n也会被读取
     */
    fgets(buf, sizeof(buf), stdin);
    /**
     * 解决fgets读取回车键\n问题
     * strlen获取有效字符长度
     * 最后一个字符设置为\0,来解决读取的回车键\n问题
     */
    int len = strlen(buf);
    //int len = my_strlen(buf);
    buf[len - 1] = '\0';
    /**
     *
     */
    printf("buf = %s\n", buf);
}


int main() {
    main_array_stdin03();
    return 0;
}