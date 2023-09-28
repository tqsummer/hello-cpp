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

#include <stdio.h>
#include <stdlib.h>

//hello world程序函数
int main1() {
    //system("mspaint");
    printf("hello world!");
    return 0;
}

//C程序中嵌套汇编
//参考文档：https://www.ibm.com/docs/zh/openxl-c-and-cpp-aix/17.1.0?topic=features-inline-assembly-statements
int main2() {
#include <stdio.h>

    int a = 5, b = 7, result;

    // 使用汇编代码实现加法操作
    asm (
            "add %[input2], %[input1]"  // 注意指令的顺序
            : [result] "=r"(result)
    : [input1] "r"(a), [input2] "r"(b)
    );

    printf("result: %d\n", result);
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    return 0;


}

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
    main2();
    return 0;

}
