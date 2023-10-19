# C语言

参考手册：https://www.w3cschool.cn/c/c-standard-library.html

gcc配置到环境变量：C:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin

命令行编译:  
gcc <源文件.c> -o <输出文件.exe>

## C语言的编译步骤

1. 预处理

* 带#的语语名就是预处理指令，预处理指令在预处理的时候处理了。
* 头文件展开：#include <stdio.h>(预处理时将#include的文件内容拷贝到预处理文件中)
* 删除注释，注释有两种方式：// 和 /* */
* 宏替换：# define 代表是声明一个宏，在预处理时会将宏给替换
* 条件编译：条件不成立(#if 0 -> #endif)代码不进预处理文件 条件成立(#if1 -> #endif)代码进预处理文件
* 预处理时不会检查语法错误

2. 编译

* 将预处理文件编译成汇编文件.s
* 检查语法错误

3. 汇编

* 将汇编文件编译生成二进制文件.o

4. 链接

* 设置运行环境，堆栈等，链接其他库

gcc编译过程  
分步编译

| 步骤  | 命令                        |
|-----|---------------------------|
| 预处理 | gcc -E hello.c -o hello.i |
| 编译  | gcc -S hello.i -o hello.s |
| 汇编  | gcc -c hello.s -o hello.o |
| 链接  | gcc  hello.o -o hello     |

| 选项      | 描述             |
|---------|----------------|
| -E      | 只进行预处理         |
| -S      | 只进行预处理和编译      |
| -c      | 只进行预处理、编译和汇编   |
| -o file | 指定生成的输出文件名file |

hello程序

```c
/**
 * # 预处理指令，在预编译时处理
 * #include <stdio.h> 包含stdio.h文件 ，stdio.h类似于菜单
 * // 两个斜杠是注释
 * main()是主函数，整个程序中仅且只有一个main函数，程序从main函数开始执行
 * int 代表main函数结束之后的返回值类型
 * return 结束这个函数，然后返回值，返回值灰一幕才函数定义时返回值类型一致
 * ｛｝里面是函数体，所有需要执行的代码必须写在{}中
 * 每一条代码必须以分号(;)结尾
 * printf是一个库函数，printf()就是函数调用
 */
#include
<stdio.h>

int main() {
printf("hello world!");
return 0;
}
```

## system库函数

需要#include <stdlib.h>  
在程序中启动另一个程序:system("<程序路径>")

启动window画板：system("mspaint");    
启动xshell：system("C:\\Program Files (x86)\\NetSarang\\Xshell 7\\Xshell.exe");   
暂停程序等用户输入任意按键：system("pause")

## cpu 寄存器 缓存 内存 之间的关系

cpu > 寄存器 > 缓存 > 内存

## C语言中嵌套汇编

```c
#include <stdio.h>

int main3() {
    int a, b, c;

    // 使用内联汇编实现相应的功能
    asm (
            "mov %[value_a], %[a]\n"     // 将 3 移动到 a
            "mov %[value_b], %[b]\n"     // 将 4 移动到 b
            "mov %[a], %%eax\n"          // 将 a 的值移动到 eax
            "add %[b], %%eax\n"          // 将 b 的值加到 eax
            "mov %%eax, %[c]\n"          // 将 eax 的值移动到 c"
            : [a] "=r"(a), [b] "=r"(b), [c] "=r"(c)
    : [value_a] "i"(3), [value_b] "i"(4)
    : "%eax"
    );

    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}


int main() {
    main3();
    return 0;

}

```

## 代码4996警告编号去除

两都选其一

1. #define _CRT_SECURE_NO_WARNINGS //定义宏放到c代码文件第一行
2. #pragma warning(disable:4996) //或都使用这个


