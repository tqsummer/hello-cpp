#include <stdio.h>

/**
 * 指针数组
 */
void main_pointer_array_pointer04() {
    int a = 10;
    int b = 20;
    int c = 30;
    int *pa[3] = {&a, &b, &c};

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

/**
 * 指针[]操作
 */
void main_pointer_array_pointer03() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = a;
    /**
     * []取值格式:[]=*()
     * a[i]=*(a+i)
     * p[i]=*(p+i)=*(a+i)=a[i]
     */

    printf("a[1] : %d ,*(a+i) : %d , p[1] : %d , *(p+1) : %d \n", a[1], *(a + 1), p[1], *(p + 1));

    /**
     * 执行结果：
     * a[1] : 2 ,*(a+i) : 2 , p[1] : 2 , *(p+1) : 2
     */
}

/**
 * 指针运算
 */
void main_pointer_array_pointer02() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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
     * q-p得到的是两个地址之间的步长为9
     *
     * 两个指针之间相加没有意义，报错
     *
     */

    printf("p+1 : %llx , p+9 : %llx , p : %llx , q : %llx ,  q-p : %d\n", p + 1, p + 9, p, q, q - p);


}

/**
 * 数组与指针
 */
void main_pointer_array_pointer01() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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
    //如果不强转*p取值会编译报错，原因：void *为万针指针类型,取值的类型为void类型。void类型，无法确定取几个字节的大小，所以无法取值。
    printf("*p : %d\n", *(int *) p);
}

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

/**
 * 野指针
 */
void main_pointer_wild_pointer01() {
    int *p; //指针没有初始化 ->野指针
    *p = 10; //指针p没有指向地址，通过*p向指针指向地址直接赋值，因为没有初始化指针指向地址，所以这里有问题，程序会这里异常退出。
    printf("*p : %d\n", *p);
}

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

void main_pointer_sizeof01() {
    char *p1;
    short *p2;
    int *p3;
    int **p4;
    printf("char * , sizeof : %d \n", sizeof(p1));
    printf("short * , sizeof : %d \n", sizeof(p2));
    printf("int * , sizeof : %d \n", sizeof(p3));
    printf("int ** , sizeof : %d \n", sizeof(p4));
}

void main_pointer_use01() {
    int a = 10;
    int *p = &a;

    printf("a : %d ,&a : %lx, p : %lx , *p : %d\n", a, &a, p, *p);

    *p = 1000;

    printf("after *p = 1000 \n");

    printf("a : %d ,&a : %lx, p : %lx , *p : %d\n", a, &a, p, *p);


}

int main() {
    printf("-----------------start pointer------------------\n");
    main_pointer_array_pointer04();
    printf("-----------------end pointer------------------\n");

    return 0;
}