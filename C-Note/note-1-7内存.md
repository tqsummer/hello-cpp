# 内存

## 作用域

变量起作用的范围

## 变量

1. 局部变量  : 在｛｝内定义的变量,auto int c,默认是auto
2. 静态局部变量 ：在｛｝内定义的变量,用static修饰变量, static int d
3. 全局变量 ：在函数之外定义的变量
4. 静态全局变量 ：在函数之外定义的变量,用static修饰变量

```c
//全局变量
int a;
//静态全局变量
static int b;

void func(){
//局部变量
int c;
//静态局部变量
static int d;
{
//局部变量
int e;
//静态局部变量
static int f;
}
}

```

生命周期：什么时候开辟空间（出生），释放空间（死亡），这个过程叫生命周期

### 局部变量

1. 作用域：在定义变量的{}之内有效
2. 生命周期：定义变量开辟空间开始~该变量所在函数结束之后释放空间
3. 未初始化的值：随机

### 静态局部变量

1. 作用域：在定义变量的{}之内有效
2. 生命周期：执行main函数运行之前开辟空间开始~程序结束之后释放空间
3. 未初始化的值：0

### 全局变量

* 在其他文件使用extern进行声明，并且可使用。

1. 作用域：整个工程，所有文件
2. 生命周期：执行main函数运行之前开辟空间开始~程序结束之后释放空间
3. 未初始化的值：0

### 静态全局变量

不能通过extern进行声明

1. 作用域：当前文件
2. 生命周期：执行main函数运行之前开辟空间开始~程序结束之后释放空间
3. 未初始化的值：0

> 作用域：局部变量(普通局部和静态局部)在{}范围；普通全局变量作用域在整个工程；静态全局变量作用域在当前文件。  
> 生命周期：只有局部变量是定义变量开辟空间开始~
> 该变量所在函数结束之后释放空间，其他变量都是执行main函数运行之前开辟空间开始~程序结束之后释放空间。        
> 未初始化的值：只有局部变量是随机，其他变量都是0

### 变量重名问题

参见：  
scope01.c  
scope02.c  
scope03.c  
scope04.c  
scope05.c

### 静态函数

静态函数：定义时，用static修饰的函数，静态函数只能当前文件调用。
static void func(){}

普通函数：定义时，没有加任何修饰的函数，也称全局函数，整个工程可以调用。    
void func(){}

## 内存分布

gcc Module2.c -o Module2.exe  
size Module2.exe
(base) PS D:\Workspace\StudyWorkspace\CppProjects\hello-cpp\cmake-build-debug\module2> size .\Module2.exe          
text data bss dec hex filename  
39892 3352 2912 46156 b44c .\Module2.exe

参考：https://www.processon.com/view/link/6522b46d68a84825481a20af

## 内存操作

### 内存处理函数

```c
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
int aa[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
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
char aa2[10] = { 1, 2, 3, 0, 5, 6, 7, 8, 9, 10 };
char ab2[10] = { 1, 2, 3, 0, 6, 6, 7, 8, 9, 10 };
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
```

总之：内存处理函数遇到0或\0都不会结束操作，而str字符串处理函数遇到0或\0都会结束。

### 内存申请

> 在内存的动态存储区(堆区)
> 中分配一块长底为size字节的连续区域，用户指定的类型。分配的内存空间内容不确定，一般使用memset初始化。  
> 返回值：  
> 成功：分配空间的起始地址  
> 失败：NULL  
> void *malloc(size_t size)

### 内存释放

> 释放内存空间  
> malloc申请的空间不能释放两次，申请一次，释放一次。  
> 传的值是申请空间的初始地址，地址必须是上一次malloc申请过的地址，不能改变这个地址。  
> void free(void *p)

## 内存管理

### 内存泄漏

内存申请，不释放，导致程序使用的内存空间一直增长。

### 内存污染

向没有申请过的内存空间写入数据。
