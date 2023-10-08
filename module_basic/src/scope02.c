#include <stdio.h>
#include "scope.h"


void scope02_func() {
    /**
     * 执行两次scope01_func(),scope01_func函数中的func_num静态局部变量，进行了累加。
     * 说明static int func_num = 1; 这行没有执行，没有进行重复初始化。
     * 静态局部变量在main函数运行之前就进行始初化了
     */
    printf("call scope01.c scope01_func 1: %d\n", *scope01_func());
    printf("call scope01.c scope01_func 2: %d\n", *scope01_func());

    /**
     * 返回局部变量，外部无法获取局部变量地址
     * 局部变量的生命周期：定义变量开辟空间开始~该变量所在函数结束之后释放空间
     */
    printf("call scope01.c scope01_func: %s\n", scope01_func2());

    /**
     * 这里可以改变全局变量值
     * 全局变量作用范围：整个工程，所有文件
     */
    printf("scope02_func get scope01.c scope01_num : %d\n", scope01_num);
    scope01_num = 200;
    printf("scope02_func set scope01.c scope01_num : %d\n", scope01_num);

    /**
     * 静态全局变量只能在定义静态全局变量的文件中使用
     * 所以variable_scope01.c文件中定义的静态全局变量scope01_num2无法使用。
     */
//    printf("scope02_func get scope01_num2 : %d\n", scope01_num2);
//    scope01_num2 = 210;
//    printf("scope02_func set scope01_num2 : %d\n", scope01_num2);

}
