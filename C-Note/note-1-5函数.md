# 函数

## 函数定义格式

```c
返回类型 函数名(形式参数列表){
    数据定义部分;
    执行语句部分;
}
```

函数名字、形参、函数体、返回值

## 函数的声明

声明的作用就是告诉编译器函数在这里定义

> 函数的声明：把函数的定义形式放在调用之前
> 函数的声明：没有函数体，函数的定义(函数的实现)：有函数体  
> 函数的声明：格式最后需要加分号结束声明。
> 函数的声明：可以加extern，也可以不加，形参可以不加变量名。

```c
#include <stdio.h>

//swap声明函数
//声明函数，可以使用extern
//extern void swap(int a, int b);

//声明函数，可以不写extern
//void swap(int a, int b);

//声明函数，可以不写extern,可以不写形参变量名
void swap(int, int);


void main_function_swap() {
swap(1, 2);
}

int main() {
main_function_swap();
return 0;
}

//swap函数定义（函数实现）
void swap(int a, int b) {
int tmp = a;
a = b;
b = tmp;
printf("a = %d , b = %d \n", a, b);
}
```

## return和exit区别

return结束当前函数。
> 如果return在子函数中调用只会结束子函数。
> 如果return在main函数中，会结束整个程序。

exit是一个库函数，用来结束整个程序。  
不管exit在哪里调用，都会结束整个程序。

## 函数分文件

1. 函数的声明写在.h头文件中。(头文件中只声明，不定义)
2. 函数的定义(实现)写在.c文件中。

#include <>  -> <>从系统目录开始找  
#include ""  -> ""从当前目录开始找

```h
//# my_math.h文件
//函数的声明写在.h文件中
int my_max(int a, int b);

int my_min(int a, int b);

int my_div(int a, int b);

int my_sub(int a, int b);

int my_sum(int a, int b);

```

```c
//# my_math.c文件
//函数的定义(实现)写在.c文件中
int my_max(int a, int b) {
return a > b ? a : b;
}

int my_min(int a, int b) {
return a < b ? a : b;
}

int my_div(int a, int b) {
return a / b;
}

int my_sub(int a, int b) {
return a - b;
}

int my_sum(int a, int b) {
return a + b;
}
```

## 防止头文件重复包含

两种方法

第一种方法：
> #ifndef 宏(宏的名字最后和头文件相同，用大写)
> #define 宏
> ...
> #endif

```c
//函数的声明写在.h文件中
#ifndef MY_MATH_H
#define MY_MATH_H

int my_max(int a, int b);

int my_min(int a, int b);

int my_div(int a, int b);

int my_sub(int a, int b);

int my_sum(int a, int b);

#endif
``` 

特点：

* ifndef的方式受C/C++语言标准支持。它不仅可以保证同一个文件不会被包含多次，也能保证内容完全相同的两个文件（或者代码片段）不会被不小心同时包含。
* 当然，缺点就是如果不同头文件中的宏名不小心“撞车”，可能就会导致你看到头文件明明存在，但编译器却硬说找不到声明的状况——这种情况有时非常让人郁闷。
* 由于编译器每次都需要打开头文件才能判定是否有重复定义，因此在编译大型项目时，ifndef会使得编译时间相对较长，因此一些编译器逐渐开始支持#pragma
  once的方式。

第二种方法：
> #pragma once

```c
//函数的声明写在.h文件中

#pragma once

int my_max(int a, int b);

int my_min(int a, int b);

int my_div(int a, int b);

int my_sub(int a, int b);

int my_sum(int a, int b);

```

特点：

* pragma once 一般由编译器提供保证：同一个文件不会被包含多次。注意这里所说的“同一个文件”是指物理上的一个文件，而不是指内容相同的两个文件。
* 你无法对一个头文件中的一段代码作pragma once声明，而只能针对文件。
* 其好处是，你不必再担心宏名冲突了，当然也就不会出现宏名冲突引发的奇怪问题。大型项目的编译速度也因此提高了一些。
* 对应的缺点就是如果某个头文件有多份拷贝，本方法不能保证他们不被重复包含。当然，相比宏名冲突引发的“找不到声明”的问题，这种重复包含很容易被发现并修正。
* 另外，这种方式不支持跨平台！

链接：https://juejin.cn/post/7090412395964661791
