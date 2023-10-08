# 内存与指针

## 指针

指针===内存地址编号

### 指针输出

%p : 打印指针地址

### 指针变量

指针变量：存放指针(地址)的变量

32位编译器：
> 内存地址编号：0x00000000 ~ 0xffffffff  
> 指针变量长度：32位(4个字节)


64位编译器：
> 内存地址编号：0x0000 0000 0000 0000 ~ 0xffff ffff ffff ffff    
> 指针变量长度：64位(8个字节)

### 指针变量定义

1. *与符号结代表是一个指针变量
2. 要保存谁的地址，将他的定义形式放在此处
3. 用*p替换掉定义的变量

int a =10;  
int *p;  
p = &a;
> 与*结合代表这个是一个指针变量  
> p是变量，p的指针变量的类型：int *
> 指针变量p用来保存什么类型数据的地址，这里存的是int类型数据的地址

*p = 100
> 在使用时，*与p结合代表，取p指针所指向那块空间存放的内容。  
> p指向的地址编号是存放a变量的地址，就是a变量的地址所存放的内容：10  
> 现在把地址存放的值改为100，所以a变量地址指定的值也为100

int a =10;
int *p = &a;
int **q = &p
> 在使用时，对一个表达式取*，就会对表达式减一级*，如果对表达式取&，就会加一级*  
> 对指针表达式取*，就会对指针类型减一级*。int *p = &a; p的类型是int * , *p减一级* -> int * 减一级* -> int。所以
*p的类型是int    
> 对指针表达式取&，就会对指针类型加一级*。int **q = &p;p的类型是 int * ,&p加一级* -> int * 加一级* -> int *
> 。所以&p的类型是int **

int b[10];
int *p[10]=&b;

### 指针变量的大小

不管什么类型的指针，大小只和系统编译器有关
> 32位编译器指针变量大小：32位(4个字节)  
> 64位编译器指针变量大小：64位(8个字节)

### 指针英度和步长

通过*取指针变理所指向那块空间内容时，取的内存的宽度和变量本身的类型有关。

不同类型的指针变量，取指针指向的内容的宽度  
指针的宽度 = sizeof(去除指针变量与批针变量最近的*,剩余部分的类型)    
宽度也叫步长：指针加1跨过多少个字节

| 指针变量类型  | 取指针指向内容的长度 |
|---------|------------|
| char *  | 1个字节       |
| short * | 2个字节       |
| int *   | 4个字节       |

```c
void main_pointer_step01() {
    int num = 0x1020314;
    char *p1 = (char *) &num;
    short *p2 = (short *) &num;
    int *p3 = &num;
    printf("char * , *p num : %x \n", *p1); //取char类型长度为：1个字节
    printf("short * , *p num : %x \n", *p2);//取short类型长度为：2个字节
    printf("int * , *p num : %x \n", *p3);//取int类型长度为：4个字节

    printf("char * , p : %p , p + 1 : %p , step : %lld\n", p1, p1 + 1, (long long) (p1 + 1) - (long long) p1);
    printf("short * , p : %p , p + 1 : %p , step : %lld\n", p2, p2 + 1, (long long) (p2 + 1) - (long long) p2);
    printf("int * , p : %p , p + 1 : %p , step : %lld\n", p3, p3 + 1, (long long) (p3 + 1) - (long long) p3);

    /**
     * 输出结果为：
     * char * , *p num : 14
     * short * , *p num : 314
     * int * , *p num : 1020314
     * char * , p : 000000cf0e1ffb64 , p + 1 : 000000cf0e1ffb65 , step : 1
     * short * , p : 000000cf0e1ffb64 , p + 1 : 000000cf0e1ffb66 , step : 2
     * int * , p : 000000cf0e1ffb64 , p + 1 : 000000cf0e1ffb68 , step : 4
     */
}
```

## 野指针

野指针:没有初始化的指针。
指针保存的地址一定是定义的(向系统申请过的)

```c
/**
 * 野指针
 */
void main_pointer_wild_pointer01() {
int *p; //指针没有初始化 ->野指针
*p = 10; //指针p没有指向地址，通过*p向指针指向地址直接赋值，因为没有初始化指针指向地址，所以这里有问题，程序会这里异常退出。
printf("*p : %d\n", *p);
}
```

## 空指针

空指针：将指针的值赋值为0或0x00000000或NULL  
空指针的作用：如果使用完指针将指针赋值为NULL,在使用时判断一下指针是否为NULL,就知道有没有被使用

```c
/**
 * 空指针
 */
void main_pointer_null_pointer01() {
/**
 *将指针的值赋值为0，0x00000000，NULL
 */
int *p = NULL; //指针p赋值为0x00000000的地址
*p = 10; //指针p指向0x00000000的地址，这个地址是不可以使用的(非法)，所以这里有问题，程序会这里异常退出。
printf("*p : %d\n", *p);
}
```

### 万能指针

万能指针就是可以保存任意的地址

```c
/**
 * 万能指针
 */
void main_pointer_universal_pointer01() {
int a = 10;
//不可以定义void类型的变量，因为编译器不知道给变量分配多大的空间。
// void b;

// 但是可以定义void *类型，因为指针都是4(或8)个字节
//万能指针可以保存任意的地址
void *p = &a;

//void * 万能指针类型需要取值时，需要强转取值指针类型
//格式：*((int *)地址) -> 这里强转为int *指针类型,取值的类型为int类型，int类型的步长为4。
//如果不强转，直接*p取值会编译报错，原因：void *为万针指针类型,取值的类型为void类型。void类型，无法确定取几个字节的大小，所以无法取值。
printf("*p : %d\n", *(int *) p);
}
```

### const修饰的指针

```c
/**
 * const修饰指针
 */
void main_pointer_const01() {
int a = 10;
int b = 20;
/**
 * a.可以通过p修改地址
 * b.可以通过*p修改地址指向空间的内容
 */
int *p1 = &a;
p1 = &b; //通过p修改地址
*p1 = 200; //通过*p修改地址指向空间的内容

/**
 * a.可以通过p修改地址
 * b.不可以通过*p修改地址指向空间的内容
 */
const int *p2 = &a;
p2 = &b; //通过p修改地址
// *p2 = 200; //这行报错，不可以通过*p修改地址指向空间的内容

/**
 * a.不可以通过p修改地址
 * b.可以通过*p修改地址指向空间的内容
 */
int *const p3 = &a;
//p3 = &b; //这行报错，不可以通过p修改地址
*p3 = 200; //通过*p修改地址指向空间的内容


/**
 * a.不可以通过p修改地址
 * b.不可以通过*p修改地址指向空间的内容
 */
const int *const p4 = &a;
//p4 = &b; //这行报错，不可以通过p修改地址
//*p4 = 200; //这行报错，不可以通过*p修改地址指向空间的内容

/**
 * const修饰的c,不能通过c来修改内容
 * 但可以通过指针p指向c的地址，*p来修改c地址空间的内容
 */
const int c = 30;
int *p5 = &c;
printf("before , c : %d , &c : %llx , p : %llx , *p : %d\n", c, &c, p5, *p5);
*p5 = 300;
printf("after , c : %d , &c : %llx , p : %llx , *p : %d\n", c, &c, p5, *p5);

}

```

### 多级指针

```c
/**
 * 多级指针
 */
void main_pointer_multi_level() {
int a = 10;
/**
 * &a => &(int) => int *
 */
int *p = &a;
/**
 * &p => &(int *) => int **
 */
int **q = &p;
/**
 * &q => &(int **) => int ***
 */
int ***r = &q;

/**
 * r -> int *** -> &q
 * r指向的是q的地址
 */
printf("r : %llx , &q : %llx\n", r, &q);

/**
 * *r -> *(int ***r) -> int **q -> &p
 * *r -> *(&q) -> q -> &p
 * 1.r指向的是q的地址
 * 2.*r指向的是q的地址指向的内容是&p(p的地址)
 */
printf("*r : %llx , &p : %llx\n", *r, &p);

/**
 * **r -> **(int ***r) -> *(int **q) -> int *p -> &a
 * **r - > **(&q) -> *q -> *(&p) -> p -> &a
 * 1.r指向的是q的地址
 * 2.*r指向的是q的地址指向的内容是&p(p的地址)
 * 3.**r->*(&p)->p->&a 是p地址指向的内容&a(a的地址)
 */
printf("**r : %llx , &a : %llx\n", **r, &a);

/**
 * **r -> ***(int ***r) -> **(int **q) -> *(int *p) -> int a -> a
 * ***r - > ***(&q) -> **q -> **(&p) -> *p -> *(&a) -> a
 * 1.r指向的是q的地址
 * 2.*r指向的是q的地址指向的内容是&p(p的地址)
 * 3.**r->*(&p)->p->&a 是p地址指向的内容&a(a的地址)
 * 4.***r->*(&a)->a 是a地址指向的内容a(a的值)
 */
printf("***r : %d , a : %d\n", ***r, a);


/**
 * 执行结果：
 * r : 8f983ffc30 , &q : 8f983ffc30
 * *r : 8f983ffc38 , &p : 8f983ffc38
 * **r : 8f983ffc44 , &a : 8f983ffc44
 * **r : 10 , a : 10
 */
}
```

### 数组与指针

```c
/**
 * 数组与指针
 */
void main_pointer_array_pointer() {
int a[10] = {
1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};

/**
 * 数组a
 * a = &a[0]
 */
/**
 * 将首元素地址赋值给指针p
 * p -> a -> &a[0]
 * *p -> *(&a[0]) -> a[0]
 * *p就是&a[0](a[0]地址)指向的内容a[0]的值
 */
int *p = a;
printf("*p : %d , a[0] : %d \n", *p, a[0]);

/**
 * *(p+1) -> *(a+1) -> *(&a[0]+1) -> *(&a[1]) -> a[1]
 * p+1是p加一个步长，等价于a加一个步长，等价于&a[0]加一个步长，int的一个步长是4个字节，正好是&a[1]
 * *(p+1)->*(&a[1])->a[1]
 * *(p+1)等价于&a[1](a[1]地址)指向的内容
 */
printf("*(p+1) : %d , a[0]+1 : %d ,a[0]+1 = a[1] : %d\n", *(p + 1), a[0] + 1, a[1]);


/**
 * &a : 25affff900 , &a+1 : 25affff928
 * &a与&a+1  十六进制相差28,十进制相差40，所以&a+1就是正好跨整个数组。
 */
printf("&a : %llx , &a+1 : %llx \n", &a, &a + 1);

printf("a sizeof : %d\n", sizeof(a));

for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
printf("&a[%d] : %llx \n", i, &a[i]);
}

/**
 * 执行结果：
 *
 * *p : 1 , a[0] : 1
 * *(p+1) : 2 , a[0]+1 : 2 ,a[0]+1 = a[1] : 2
 * &a : 25affff900 , &a+1 : 25affff928
 * a sizeof : 40
 * &a[0] : 25affff900
 * &a[1] : 25affff904
 * &a[2] : 25affff908
 * &a[3] : 25affff90c
 * &a[4] : 25affff910
 * &a[5] : 25affff914
 * &a[6] : 25affff918
 * &a[7] : 25affff91c
 * &a[8] : 25affff920
 * &a[9] : 25affff924
 *
 *
 *
 */

}

```

### 指针运算

```c
/**
 * 指针运算
 */
void main_pointer_array_pointer02() {
int a[10] = {
1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};

/**
 * int *p = a 等价于 int *p = &a[0]
 */
int *p = a;

/**
 * (int *) (&a + 1) - 1 -> &a[9]
 * 1.&a+1:跨过整个数组得到的地址
 * 2.强转为int *的指针类型
 * 3.(int *) (&a + 1) - 1 ，(int *)的指针类型减去一个步长，int类型的步长为4个字节，减去4个字节正好是&a[9](a[9]的地址)
 */
int *q = (int *) (&a + 1) - 1;


/**
 * p+1 -> &a[0]+1 -> &a[1]
 * p+9 -> &a[0]+9 -> &a[9] ->q
 *
 * q-p -> &a[9]-&a[0] -> &a[0]+9-&a[0] -> 9
 *
 * 两个指针之间相减得到的是两个地址之间的步长
 * *两个指针相减要保证两个指针类型一致
 * q-p得到的是两个地址之间的步长为9
 *
 * 两个指针之间相加没有意义，报错
 *
 */

printf("p+1 : %llx , p+9 : %llx , p : %llx , q : %llx ,  q-p : %d\n", p + 1, p + 9, p, q, q - p);


}

```

### 指针[]操作

```c
/**
 * 指针[]操作
 */
void main_pointer_array_pointer03() {
int a[10] = {
1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};
int *p = a;
/**
 * []取值格式:[]=*()
 * a[i]=*(a+i)
 * p[i]=*(p+i)=*(a+i)=a[i]
 */

printf("a[1] : %d ,*(a+i) : %d , p[1] : %d , *(p+1) : %d \n", a[1], *(a + 1), p[1], *(p + 1));

}
```

### 指针数组

整型数组：是一个数组，数组的每一个元素是整型    
指针数组：是一个数组，数组的每一个元素是指针

```c
/**
 * 指针数组
 */
void main_pointer_array_pointer04() {
int a = 10;
int b = 20;
int c = 30;
int *pa[3] = { &a, &b, &c };

/**
 * 64位编译器，每个指针长度为64位(8个字节)
 * 3个元素，每个元素8个字节，3*8 = 24个字节
 * pa sizeof : 24
 */
printf("pa sizeof : %d \n", sizeof(pa));

printf("a : %d <=> *pa[0] : %d\n", a, *pa[0]);
printf("b : %d <=> *pa[1] : %d\n", b, *pa[1]);
printf("c : %d <=> *pa[2] : %d\n", c, *pa[2]);


/*
 * 定义一个指针来保存指针数组的地址（这里指针数组的地址相当于指针数组第一个元素的地址）
 * pa = &pa[0] , &(int *) ==> int **
 * 所以int **p = pa;  等价于 int **p = &pa[0]
 */
int **p = pa;

for (int i = 0; i < sizeof(pa) / sizeof(pa[0]); i++) {
/**
 * **(p+0) -> **(&pa[0]) -> *(pa[0]) -> *(&a) -> a
 * **(p+1) -> **(&pa[0]+1) -> **(&pa[1]) -> *(pa[1]) -> *(&b) -> b
 * **(p+1) -> **(&pa[0]+2) -> **(&pa[2]) -> *(pa[2]) -> *(&c) -> c
 */
printf("**(p+%d) : %d\n", i, **(p + i));
}

/**
 * 执行结果：
 * pa sizeof : 24
 * a : 10 <=> *pa[0] : 10
 * b : 20 <=> *pa[1] : 20
 * c : 30 <=> *pa[2] : 30
 * **(p+0) : 10
 * **(p+1) : 20
 * **(p+2) : 30
 */
}
```

### 指针作为函数的形参

指针作为函数的形参，可以改变实参的值

```c
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * 指针作为形参
 */

void main_pointer_parameter04() {
    int a = 10;
    int b = 20;
    printf("before a : %d , b : %d \n", a, b);
    swap(&a, &b);
    printf("after a : %d , b : %d \n", a, b);

    /**
     * 执行结果:
     * before a : 10 , b : 20
     * after a : 20 , b : 10
     */
}
```

### 数组作为函数的参数

```c
/**
 * void print_array(int a[])  -> void print_array(int *a) 数组作为函数的形参会退化为指针
 *
 * 这个函数需要传len，主要原因是传入的a实际是&a[0](a[0]的地址)，这个地址无法知道数组长度，所以需要传数组元素个数。
 * @param a 数组参数
 * @param len 数组元素个数
 */
void print_array(int *a, int len) {
/**
 * 32位编译器下，n值为1
 * 64位编译器下，n值为2
 *
 * 64位编译器下
 *
 * 1.sizeof(a) -> sizeof(&a[0])
 * 地址类型的sizeof为8 ，这里的8是8个字节
 *
 * 2.sizeof(a[0]) -> sizeof(*(a+0)) -> sizeof(*(a)) -> sizeof(*(&a[0])) -> sizeof(a[0]) ->sizeof(1)
 * sizeof(a[0]),a[0]的值为1，是int类型 -> sizeof(int)  int类型的sizeof为4 ，这里的4是4个字节
 *
 * 3.所以int n = sizeof(a) / sizeof(a[0])的值为2
 *
 */
int n = sizeof(a) / sizeof(a[0]);
printf("n : %d\n", n);

for (int i = 0; i < len; i++) {
/**
 * a[i] = *(a+i) = *(&a[0]+i) = *(&a[i]) = a[i]
 */
printf("a[%d] : %d\n", i, a[i]);
}
}

/**
 * 数组作为函数形参
 */

void main_pointer_parameter05() {
int a[10] = {
1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};
print_array(a, sizeof(a) / sizeof(a[0]));
/**
 * 执行结果：
 * n : 2
 * a[0] : 1
 * a[1] : 2
 * a[2] : 3
 * a[3] : 4
 * a[4] : 5
 * a[5] : 6
 * a[6] : 7
 * a[7] : 8
 * a[8] : 9
 * a[9] : 10
 */

}

```

### 指针作为函数的返回值

```c
/**
 * 在函数外面定义的变量叫全局变量，束个工程 都可以使用。
 * 整个变量程 序启动开辟空间，直到程序结束释放空间
 */
int num = 0;

int *getnum() {
/**
 * {}下义的变量叫局部变量，局部变量在函数结束之后的空间会被释放
 */
srand(time(NULL));
/**
 * 如果这里定义的是局部变量
 * int num = rand();
 * 函数main_pointer_return01()调用时num的地址已经被释放
 * 执行结果是：getnum p : 0000000000000000 ，然后程序异常退出。
 */
num = rand();
return &num;
}

/**
 * 指针作为函数返回值
 */

void main_pointer_return01() {
int *p = getnum();
printf("getnum p : %p\n", p);
printf("getnum *p : %d\n", *p);
}

```

### 指针与字符数组

```c
/**
 * 指针与字符数组
 */

void main_pointer_char_array01() {
/**
 * 定义了一个字符数组，字符数组内容为helloworld\0
 * 数组a的长度为11
 */
char a[] = "helloworld";
char *p = a;
/**
 * a相当于&a[0]
 * 打印一个字符串，要的是首个字符&a[0](a[0]的地址)的地址开始到\0字符结束
 * 打印结果是:helloworld
 */
printf("p str : %s\n", p);
/**
 *  p+2 -> a+2 -> &a[0]+2 -> a[2]
 * 打印一个字符串，首个字符&a[2](a[2]的地址)开始到\0字符结束
 * 打印结果是:lloworld
 */
printf("p+2 str : %s\n", p + 2);
/**
 * p+4 -> a+4 -> &a[0]+4 -> &a[4]
 * *(p+4) -> *(&a[4]) -> a[4]
 * 打印一个a[4]地址指向的内容
 * 打印结果是:o
 */
printf("*(p+4) char : %c\n", *(p + 4));


/**
 * sizeof(a):字符数组字节长度，这里11个字符，长度是11个字节
 * sizeof(p):指针类型字节长度，64位编译器是8个字节，长度是8个字节
 */
printf("sizeof(a) : %d\n", sizeof(a));
printf("sizeof(p) : %d\n", sizeof(p));

/**
 * strlen(a) = strlen(p):a与p指向的地址都是&a[0],得到的字符串的有效长度相同
 */
printf("strlen(a) : %d\n", strlen(a));
printf("strlen(p) : %d\n", strlen(p));

/**
 * *p -> *(&a[0]) -> a[0] ,相当于给a[0]赋值
 * 所以字符数组a打印出来的字符串为:melloworld
 */
*p = 'm';
printf("p str : %s\n", p);

/**
 * 指针可以用++运算符，但是字符数组a不可以。
 * p++相当于p = p+1,将指针步长加1赋值给p,p指向&a[1]
 * 此时打印的结果是:elloworld
 */
p++;
printf("p str : %s\n", p);
}

```

### 字符串常量

```c
/**
 * 字符串常量
 */

void main_pointer_str_const01() {
/**
 * 定义了一个字符数组，字符数组内容为helloworld\0
 */
char a[] = "helloworld";
/**
 * 定义了一个指针，指向了a相当于指向了&a[0]
 */
char * p = a;
/**
 * abcdefg是一个字符串常量，字符串常量存在文字常量区，现在p重新指向到这个字符串常量的首元素地址。
 */
p = "abcdefg";

/**
 * p指向到字符串常量的首元素地址
 * 这里打印的是:abcdefg
 */
printf("p str : %s\n", p);

/**
 * 以下代码会报错，
 * 1.因为p现在指向的是字符串常量的首元素地址
 * 2.字符串常量存在文字常量区
 * 3.文字常量区的内容不可以被改变
 * 所以会报错
 */
//*p = 'm';
}

```

### 字符指针作为形参

```c
/**
 * 将dest字符串拼接到src上
 * @param src
 * @param dest
 * @return
 */
char *my_strcat(char *src, char *dest) {
int n_src = strlen(src);
int i = 0;
while (dest[i] != '\0') {
/**
 * 这行代码等价于:*(src+n_src+i) = *(dest+i)
 */
src[n_src + i] = dest[i];
i++;
}
src[n_src + i] = '\0';
return src;
}

/**
 * 字符指针作为形参
 */

void main_pointer_str02() {
char a[128] = "hello world";
char b[128] = ",let's go!";
printf("my_strcat() str : %s \n", my_strcat(a, b));

}
```

### 字符指什数组

参号：https://www.processon.com/view/link/6520e2592c86306603f3fe31

```c
/**
 * 字符指针数组
 * 
 */

void main_pointer_str03() {

/**
 * 以下代码等价于：
 * char* h1 = "hehe";
 * char* h2 = "haha";
 * char* h3 = "hoho";
 * char *str_arr[] = {h1,h2,h3};
 */
char *str_arr[] = {
"hehe", "haha", "hoho"
};

printf("**str_arr : %c\n", **str_arr);

/**
 * 打印字符指针数组的字符串内容
 */
for (int i = 0; i < sizeof(str_arr) / sizeof(str_arr[0]); i++) {
/**
 * 打印字符串，需要的是元素首地址
 * str_arr[i]是char * 类型，保存的是字符数组首元素地址
 */
printf("str_arr[%d] = %s\n", i, str_arr[i]);
}

/**
 * 定义一个指针保存str_arr首元素地址
 * 因为字符串数组，每个元素的类型是char *
 * 所以获取字符串数组的首元素地址的类型是 char **
 */
char **p = str_arr;

/**
 * *p指向的是&str_arr[0](首元素地址)指向的内容，*p =*(&str_arr[0]) = str_arr[0] -> 是char * 字符数组指针 -> hehe\0字符数组首元素地址
 * 所以打印的结果是:hehe
 */
printf("*p str : %s\n", *p);



/**
 * 定义一个指针保存str_arr第i个元素的地址，这里i=1
 * 因为str_arr[i]的类型是char *
 * 所以定义的这个指针的类型为char **
 */
char **p1 = &str_arr[1];

/**
 * p1 等价于 p+1
 * str_arr+1 -> &str_arr[0]+1 -> &str_arr[1]
 * p+1 -> &str_arr[0]+1 -> &str_arr[1]
 * p1 = &str_arr[1]
 *
 */
printf("str_arr+1 : %p , p+1 : %p , p1 : %p \n", str_arr + 1, p + 1, p1);

/**
 * p+2 -> &str_arr[0]+2 -> &str_arr[2]
 * *(p+2) -> *(&str_arr[2]) -> str_arr[2]-> 这里得到的是字符数组(hoho\0)首元素地址
 * %s输出是首元素开始到\0结束，所以输出结果是hoho
 */
printf("*(p+2) : %p , %s\n", *(p + 2), *(p + 2));

/**
 * 因为：*(p+2) -> *(&str_arr[2]) -> str_arr[2]-> 这里得到的是字符数组(hoho\0)首元素地址
 * 所以**(p+2)得到的是字符数组首元素地址指向的字符h
 *
 * *(p+2)+1 -> 字符数组(hoho\0)首元素地址+1 -> 字符数组(hoho\0)第二个元素地址
 * *(*(p+2)+1)得到的是字符数组第二个(下标为1的)元素地址指向的字符o
 *
 * str_arr[2]-> 字符数组(hoho\0)首元素地址
 * str_arr[2][2]-> 字符数组(hoho\0)第三个(下标为2的)元素地址指向的字符h
 */
printf("**(p+2) : %c , *(*(p+2)+1) : %c , str_arr[2][2] : %c\n", **(p + 2), *(*(p + 2) + 1), str_arr[2][2]);


}

```

### 字符串指针数组作为main函数参数

main函数支持参数  
参数一argc:参数个数,类型int  
参数二argv:参数内容,类型char *[]

```c
/**
 * 字符串指针数组作为main函数参数
 */

void main_pointer_main_parameter01(int argc, char *argv[]) {
printf("argc : %d\n", argc);
for (int i = 0; i < argc; i++) {
printf("argv[%d] : %s\n", i, argv[i]);
}
/**
 * 执行未带参数结果：
 * argc : 1
 * argv[0] : D:\Workspace\StudyWorkspace\CppProjects\hello-cpp\cmake-build-debug\module_basic\MB-PointerMain.exe
 * 执行文件作为第一个参数值，所以argc至少有一个参数，就是执行文件本身。
 *
 * 执行D:\Workspace\StudyWorkspace\CppProjects\hello-cpp\cmake-build-debug\module_basic\MB-PointerMain.exe a=hello b=world
 * 结果：
 * argc : 3
 * argv[0] : D:\Workspace\StudyWorkspace\CppProjects\hello-cpp\cmake-build-debug\module_basic\MB-PointerMain.exe
 * argv[1] : a=hello
 * argv[2] : b=world
 */

}


int main(int argc, char *argv[]) {
printf("-----------------start pointer------------------\n");
main_pointer_main_parameter01(argc, argv);
printf("-----------------end pointer------------------\n");

return 0;
}
```

### 字符串常用库函数

```c
/**
 * 字符串反转
 * @param str
 * @return
 */
char *my_str_reverse(char *str) {
char *start = str;
char *end = str + strlen(str) - 1;
while (end > start) {
char tmp = *start;
*start = *end;
*end = tmp;
start++;
end--;
}
return str;
}

/**
 * 字符串修剪(把两头空白字符删除)
 * @param str
 * @return
 */
char *my_str_trim(char *str) {
char *start = str;
char *end = str + strlen(str) - 1;
/**
 * 这里比较的时地址，end地址肯定大于start地址
 */
if (start == end) {
return str;
}
while (*start == ' ' && *start != '\0') {
start++;
}

while (*end == ' ' && end != start) {
*end = 0;
end--;
}
strncpy(start, start, end-start+1);
return start;
}

/**
 * 找出字符串str1中出现字符串str2的次数
 * @param str1
 * @param str2
 * @return
 */
int my_strstr_num(char *str1, char *str2) {
char *p = str1;
int str2_len = strlen(str2);
int n = 0;
do {
p = strstr(p, str2);
if (p != NULL) {
n++;
p = p + str2_len;
}
} while (p != NULL);

return n;
}

/**
 * 从字符串str1中找到字符串str2出现的位置，如找到返回位置的地址，如果没有找到返回NULL
 * @param str1
 * @param str2
 * @return
 */
char *my_strstr(char *str1, char *str2) {
int str2_len = strlen(str2);
int i = 0;
while (str1[i] != 0) {
if (strncmp(str1 + i, str2, str2_len) == 0) {
return str1 + i;
}
i++;

}
return NULL;
}

/**
 * 从字符串中找到符合字符出现的位置，如找到返回位置的地址，如果没有找到返回NULL
 * @param p
 * @param ch
 * @return
 */
char *my_strchr(char *p, char ch) {
int i = 0;
while (p[i] != 0) {
if (p[i] == ch) {
return &p[i];
}
i++;
}
return NULL;
}

/**
 * 字符串常用库函数
 */
void main_pointer_str04() {
/**
 * strcpy(char *str1,char *str2)
 * 将str2的字符拷贝至str1数组中，注意，str2遇到\0结束，会将\0拷贝至str1
 */
char str1[32] = "helloworld";
char str2[32] = "sky";
strcpy(str1, str2);
printf("str1 : %s\n", str1);
for (int i = 0; i < 32; i++) {
printf("%c", str1[i]);
}
printf("\n\n");

/**
 * strncpy(char *str1,char *str2,int n)
 * 将str2中的前n个字符拷贝至str1数组中，如果str2遇到\0并且不足n个，后面都补\0直到满n个
 */

char str3[32] = "helloworld";
char str4[32] = "s\0kyabc";
strncpy(str3, str4, 5);
printf("str3 : %s\n", str3);
for (int i = 0; i < 32; i++) {
printf("%c", str3[i]);
}
printf("\n\n");

/**
 * strcat(char *str1,char *str2)
 * 将str2中的字符连接至str1数组中，如果str2遇到\0结束
 *
 * strncat(char *str1,char *str2,int n)
 * 将str2中的前n个字符连接至str1数组中，如果str2遇到\0并且不足n个，后面都补\0直到满n个
 */

/**
 * strcmp(char *str1,char *str2)
 * str1数组中和str2数组中取一个元素比较，相等继续往后比较
 * 比较的是字符的ascii值
 * 如果str1>str2 返回1
 * 如果str1=str2 返回0
 * 如果str1<str2 返回-1
 *
 *
 * strncmp(char *str1,char *str2,int n)
 * str1数组中和str2数组中取一个元素比较，相等继续往后比较，最多比较n个字符
 *
 */

/**
 * 组包函数
 * int sprintf(char *__stream, const char *__format, ...)
 * __stream：组包存放的字符数组
 * __format：格式
 * ... ：数据参数
 * int 返回的组包存的有效长度
 */
int year = 2023;
int month = 10;
int day = 7;
char buf[128];
int len = sprintf(buf, "year : %d ,month : %d ,day : %d", year, month, day);
printf("sprintf len : %d , str : [%s]\n", len, buf);

/**
 * 拆包函数
 * int sscanf(char *__stream, const char *__format, ...)
 * __stream：拆包读取的字符数组
 * __format：格式
 * ... ：拆包参数地址
 * int 返回值 成功则返回成功转换的值的个数，失败则返回-1
 */
//scanf("%d-%d-%d",year,month,day);//这个是从标准输入(键盘)中拆包
char buf2[] = "2024-11-08";
int ret = sscanf(buf2, "%d-%d-%d", &year, &month, &day);
printf("sscanf year : %d ,moth : %d ,day : %d , ret : %d\n", year, month, day, ret);


/**
 * char * strchr(char * str,char ch)
 * 从字符串中找到符合字符的位置，如找到返回位置的地址，如果没有找到返回NULL
 */
char str[] = "hi,let's go!Ok";
//char *p = my_strchr(str, 'l');
char *p = strchr(str, 'l');
if (p) {
printf("p : %p , *p : %c , str : %s\n", p, *p, p);
} else {
printf("p not found!\n");
}

/**
 * char * strstr(char *str1,char * str2)
 * 从字符串str1中找到字符串str2出现的位置，如找到返回位置的地址，如果没有找到返回NULL
 */
char str5[] = "aliyundrive.com";
char str6[] = "drive";
//char *p2 = my_strstr(str5, str6);
char *p2 = strstr(str5, str6);
if (p2) {
printf("p2 : %p , *p2 : %c , str : %s\n", p2, *p2, p2);
} else {
printf("p2 not found!\n");
}

/**
 * char * strtok(char *str1,char * str2)
 * 从str1中切割字符串，切割符为str2中的任意字符。切割成功返回字符串首元素地址，切割失败已结束则返回NULL
 * 首次切割调用传字符串，后几次传NULL，直到切割完成为止。
 */
//初始化字符串数组，全部初始化为NULL
char str7[] = "2018#09#18&ha&he&ho";
char str8[] = "#&";
char *str_arr[10] = {};
for (int i = 0; i < sizeof(str_arr) / sizeof(str_arr[0]); i++) {
printf("str_arr[%d] : %s\n", i, str_arr[i]);
}
int i = 0;
do {
if (i == 0) {
str_arr[i] = strtok(str7, str8);
} else {
str_arr[i] = strtok(NULL, str8);
}
} while (str_arr[i++] != NULL);

i = 0;
while (str_arr[i] != NULL) {
printf("str_arr[%d] : %s\n", i, str_arr[i]);
i++;
}

/**
 * int atoi(char * num)
 * 将字符串转成整数，+-0~9的字符就开始转，如果不是+-0~9的字符结束
 * 如果前面有空格，跳过
 *
 * float atof(char * num)
 * long atol(char * num)
 * long long atoll(char * num)
 *
 */
char str9[] = " 1250";
char str10[] = "3.1415";
printf("str9 atoi : %d\n", atoi(str9));
printf("str10 atof : %f\n", atof(str10));

/**
 * int my_strstr_num(char *str1, char *str2)
 * 找出字符串str1中出现字符串str2的次数
 */
char str11[] = "abc11111abc2ab34abc7865abcd";
char str12[] = "abc";
printf("my_strstr_num : %d\n", my_strstr_num(str11, str12));

/**
 *char *my_str_trim(char *str)
 * 字符串修剪
 */
char str13[] = "     abcdefghijklmn       ";
char *new_str13 = my_str_trim(str13);
printf("my_str_trim : %s,strlen : %d\n", new_str13, strlen(new_str13));

/**
 * char *my_str_reverse(char *str)
 * 字符串反转
 */
char str14[] = "abcdefghijklmn";
printf("my_str_reverse : %s\n", my_str_reverse(str14));

}

```

## 内存

### 作用域

变量起作用的范围

### 变量

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

#### 局部变量

1. 作用域：在定义变量的{}之内有效
2. 生命周期：定义变量开辟空间开始~该变量所在函数结束之后释放空间
3. 未初始化的值：随机

#### 静态局部变量

1. 作用域：在定义变量的{}之内有效
2. 生命周期：执行main函数运行之前开辟空间开始~程序结束之后释放空间
3. 未初始化的值：0

#### 全局变量

* 在其他文件使用extern进行声明，并且可使用。

1. 作用域：整个工程，所有文件
2. 生命周期：执行main函数运行之前开辟空间开始~程序结束之后释放空间
3. 未初始化的值：0

#### 静态全局变量

不能通过extern进行声明

1. 作用域：当前文件
2. 生命周期：执行main函数运行之前开辟空间开始~程序结束之后释放空间
3. 未初始化的值：0

> 作用域：局部变量(普通局部和静态局部)在{}范围；普通全局变量作用域在整个工程；静态全局变量作用域在当前文件。  
> 生命周期：只有局部变量是定义变量开辟空间开始~
> 该变量所在函数结束之后释放空间，其他变量都是执行main函数运行之前开辟空间开始~程序结束之后释放空间。        
> 未初始化的值：只有局部变量是随机，其他变量都是0

#### 变量重名问题

#### 静态函数

静态函数：定义时，用static修饰的函数，静态函数只能当前文件调用。
static void func(){}

普通函数：定义时，没有加任何修饰的函数，也称全局函数，整个工程可以调用。    
void func(){}