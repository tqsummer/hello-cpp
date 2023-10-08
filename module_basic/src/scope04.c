#include <stdio.h>

/**
 * 这个全局变量可以在整个工程使用
 * scope03.c声明的__scope_v变量，就是在这里定义的
 */
int __scope_v = 7;

/**
 * 这个全局函数可以在整个工程使用
 * scope03.c声明的__scope_func()函数，就是在这里定义的
 */
int __scope_func() {
    int __scope_v = 17;
    return __scope_v;
}


