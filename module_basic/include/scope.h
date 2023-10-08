/**
 * .h文件中只声明，不定义
 * 如果在.h文件中定义，如果多个文件引用.h文件，会出重复定义，全局变量重复定义会编译报错
 */
#pragma once
extern int scope01_num;

/**
 * 不能声明静态全局变量，编译报错
 * 静态全局变量只能在定义静态全局变量的文件中使用
 */
//extern static int scope01_num2;

extern int *scope01_func();

extern int *scope01_func2();

extern void scope02_func();

extern void scope03_func();
