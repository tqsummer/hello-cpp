#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

/**
 * parameter02_func_call函数中，&p(p地址0x00e0)，p指向文字常量区"hello"首元素地址0x00f0。
 * 调用parameter02_func02函数，将&p(即0x00e0)作为实参传入，局部变量k在parameter02_func02函数栈区分配，将&p的值(0x00e0,即文字常量区"hello"首元素地址)存入局部变量k中
 * 在函数中k = "parameter02_func01 hello";，此时*k的值(相当于p地址的值)改变了，指向文字常量区"parameter02_func01 hello"首元素地址0x00e7。
 * parameter01_func02函数结束,局部变量k空间释放。
 * &p的指向已经是文字常量区"parameter02_func01"首元素地址0x00e7。
 * parameter02_func01 hello。
 * @param k
 */
void parameter02_func02(char **k) {
    *k = "parameter02_func01 hello";
}

void parameter02_func01(int *k) {
    *k = *k + 10;
}

void parameter02_func_call() {
    int a = 1;
    parameter02_func01(&a);
    printf("parameter02_func_call a : %d\n", a);

    char *p = "hello";
    parameter02_func02(&p);
    printf("parameter02_func_call p : %s\n", p);
}

/**
 * 传形参传地址,可以改变实参的值
 */
void main_memory_parameter02() {
    parameter02_func_call();
}


/**
 * 这里返回的是文字常量区"parameter01_func01 hello"首元素地址
 * @param k
 * @return
 */
char *parameter01_func03(char *k) {
    k = "parameter01_func01 hello";
    return k;
}

/**
 * parameter01_func_call函数中，p指向文字常量区"hello"首元素地址0x00f0。
 * 调用parameter01_func02函数，将p作为实参传入，局部变量k在parameter01_func02函数栈区分配，将p的值(0x00f0,即文字常量区"hello"首元素地址)存入局部变量k中
 * 在函数中k = "parameter01_func01 hello";，此时k的值指向文字常量区"parameter01_func01 hello"首元素地址
 * parameter01_func02函数结束,局部变量k空间释放。
 * p的指向任然是文字常量区"hello"首元素地址0x00f0。
 * 所以打印还是hello。
 * @param k
 */
void parameter01_func02(char *k) {
    k = "parameter01_func01 hello";
}


void parameter01_func01(int k) {
    k = k + 1;
}

void parameter01_func_call() {
    int a = 1;
    parameter01_func01(a);
    printf("parameter01_func_call a : %d\n", a);

    char *p = "hello";
    parameter01_func02(p);
    printf("parameter01_func_call p : %s\n", p);

    /**
     * 这里p重新赋值，指向了文字常量区"parameter01_func01 hello"首元素地址
     */
    p = parameter01_func03(p);
    printf("parameter01_func_call p : %s\n", p);
}

/**
 * 传形参传值,不会改变实参的值
 */
void main_memory_parameter01() {
    parameter01_func_call();
}

/**
 * 传参
 */
void main_memory_parameter() {
    main_memory_parameter01();
    main_memory_parameter02();
}

/**
 * 内存申请
 */
void main_memory_malloc01() {
    /**
     * 在内存的动态存储区(堆区)中分配一块长底为size字节的连续区域，用户指定的类型。分配的内存空间内容不确定，一般使用memset初始化。
     * 返回值：
     * 成功：分配空间的起始地址
     * 失败：NULL
     * void *malloc(size_t size)
     *
     */

    int *p = (int *) malloc(sizeof(int));
    *p = 128;
    printf("*p : %d\n", *p);

    /**
     * 释放内存空间
     * malloc申请的空间不能释放两次，申请一次，释放一次。
     * 传的值是申请空间的初始地址，地址必须是上一次malloc申请过的地址，不能改变这个地址。
     * void free(void *p)
     */
    /**
     * 传入的p是上次malloc申请的地址
     * //free(p+1) ，这里执行，程序会异常退出，不能传非malloc申请的地址
     */
    free(p);

    printf("after free , *p : %d\n", *p);


    /**
     * 申请一个10个字节的堆空间
     * char *类型的p2指向这个堆空间的首地址
     */
    char *p2 = (char *) malloc(sizeof(char) * 10);
    //将这个10个字节都设置为0
    memset(p2, 0, sizeof(char) * 10);
    //将第一个字节的值设置为1
    *p2 = 1;
    //将第二个字节的值设置为2
    *(p2 + 1) = 2;
    *(p2 + 4) = 3;
    /**
     * 将int * p3指向p2的地址
     * int是4个字节的，p3的步长是4个字节
     * *p3是int型，4个字节,32位
     * 通过*p2 = 1, *(p2+1) = 2
     * 第一个字节值设置为1 -> 二进制 00000001
     * 第二个字节值设置为2 -> 二进制 00000010
     * 第三个字节值没有设置，memset初始设置为0 -> 二进制 00000000
     * 第四个字节值没有设置，memset初始设置为0 -> 二进制 00000000
     * 内存中存储是低位在前，高位在后
     * 计算值时低位在右，高位在左，如下：
     * 00000000 00000000 00000010 00000001 -> 十进制是：513
     *
     * p3+1，int *类型一个步长是一个int类型的字节数，指向的是第五个字节(p2+4或&p2[4])的地址
     * 通过*(p2 + 4) = 3，那么p3+1
     * 第一个字节值设置为3 -> 二进制 00000011
     * 第二个字节值没有设置，memset初始设置为0 -> 二进制 00000000
     * 第三个字节值没有设置，memset初始设置为0 -> 二进制 00000000
     * 第四个字节值没有设置，memset初始设置为0 -> 二进制 00000000
     * 00000000 00000000 00000000 00000011 -> 十进制是：3
     *
     */
    int *p3 = p2;
    printf("*p3 : %d , *(p3+1) : %d \n", *p3, *(p3 + 1));

    int a = 10;
    /**
     * 这里不允许释放栈区申请的空间
     * free(&a)不可用，程序会异常退出
     */
    //free(&a);

}

/**
 * 内存处理
 */
void main_memory_process01() {
    int a = 10;
    /**
     * 将s的内存区域的前n具字节以参数c填入
     * void *memset(void *s, int c, size_t n);
     */
    /**
     * a是int型，sizeof为4个字节，32位
     * 1个字节8位，所以每个字节填1
     * 得到以下二进制值
     * 00000001 00000001 00000001 00000001
     * 转成十进制：16843009
     * 最终打印：16843009
     */
    memset(&a, 1, sizeof(0));
    printf("a : %d\n", a);

    char buf[10] = "";
    strcpy(buf, "hello");
    printf("buf : %s\n", buf);
    /**
     * 将buf字符数组清空
     */
    memset(buf, 0, sizeof(buf));
    printf("buf : %s\n", buf);
    /**
     * 将buf前9个字符设置为a字符
     */
    memset(buf, 'a', 9);
    printf("buf : %s\n", buf);

    /**
     * 拷贝src所指的内存内容的前n个字节到dest所指的内存地址上
     * void *memcpy(void *dest,const void *src,size_t n);
     */
    int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ab[10] = {};
    /**
     * 从aa数组中拷贝5个int型=20个字节到ab数组中去
     */
    memcpy(ab, aa, sizeof(int) * 5);
    for (int i = 0; i < sizeof(ab) / sizeof(ab[0]); i++) {
        printf("ab[%d]=%d ", i, ab[i]);
    }
    printf("\n");

    /**
     * 比较s1和s2所指向内存区域的前n个字节的大小
     * 返回值：
     * 相等：0
     * 大于：1
     * 小于：-1
     * int memcmp(const void *s1,const void *s2,size_t n);
     *
     */
    char aa2[10] = {1, 2, 3, 0, 5, 6, 7, 8, 9, 10};
    char ab2[10] = {1, 2, 3, 0, 6, 6, 7, 8, 9, 10};
    /**
     * 这个比较7个字节，比较到aa2[4]<ab[4]，所以结果是-1
     */
    printf("aa2 memcmp ab2 : %d\n", memcmp(aa2, ab2, sizeof(char) * 7));
    /**
     * strncmp也是比较前7个字符，一个字符等于一个字节，也是比较前7个字节
     * strncmp比较到aa[3]和ab[3]都为0，都终止，此时比较的结果是相等 ，所以返回结果是0
     */
    printf("aa2 strcmp ab2 : %d\n", strncmp(aa2, ab2, sizeof(char) * 7));


}

/**
 * 内存分布
 */
int e;
static int f;
int g = 10;
static int h = 10;

void main_memory_distribution01() {
    int a;
    int b = 10;
    static int c;
    static int d = 10;
    char *i = "test";
    char *k = NULL;

    printf("&a\t %p\t //局部未初始化变量\n", &a);
    printf("&b\t %p\t //局部初始化变量\n", &b);
    printf("&c\t %p\t //静态局部未初始化变量\n", &c);
    printf("&d\t %p\t //静态局部初始化变量\n", &d);
    printf("&e\t %p\t //全局未初始化变量\n", &e);
    printf("&f\t %p\t //静态全局未初始化变量\n", &f);
    printf("&g\t %p\t //全局初始化变量\n", &g);
    printf("&h\t %p\t //静态全局初始化变量\n", &h);
    printf("&i\t %p\t //局部初始化变量\t,i\t %p\t  //只读数据(文字常量区) \n", &i, i);

    k = (char *) malloc(20);
    printf("&k\t %p\t //局部未初始化变量\t,k\t %p\t //动态分配的内存 \n", &k, k);
}

int main() {
    printf("-----------------start memory------------------\n");
    main_memory_parameter();
    printf("-----------------end memory------------------\n");
}