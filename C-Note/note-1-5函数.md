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

1. 函数的声明写在.h头文件中。
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

