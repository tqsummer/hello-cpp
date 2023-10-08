#include <stdio.h>
#include "scope.h"
/**
 * 以下int val中三个是声明一个是定义
 * 尽量声明变量或函数时，使用extern进行修饰
 */
//int val;
//int val;
//int val;
//int val;

/**
 * 全局变量重复定义会编译报错
 */
//int val1=10;
//int val1=10;
int scope01_num = 0;
static int scope01_num2;

int main() {
    scope01_num = 100;
    printf("before call scope02.c scope02_func , scope01_num : %d\n", scope01_num);
    scope02_func();
    printf("after call scope02.c scope02_func , scope01_num : %d\n", scope01_num);

    scope03_func();
}

int *scope01_func() {
    /**
     * 静态局部变量
     * 静态局部变量始初化只会在main函数运行之前执行，调用期间不会再重复执行初始化操作。
     */
    static int func_num = 1;
    {
        func_num += 11;
    }
    return &func_num;
}

int *scope01_func2() {
    /**
     * 局部变量
     * 函数调用结束之后就会释放空间,函数外无法获取变量地址。
     */
    int func_num2;
    {
        func_num2 = 20;
    }

    return &func_num2;
}