#include <stdio.h>

/**
 * 这个静态全局变量只能在当前文件使用
 */
static int __scope_v = 27;

/**
 * 这个静态函数只能在当前文件调用
 * @return
 */
static int __scope_func() {
    return __scope_v;
}

int __scope_func2() {
    return __scope_func();
}


