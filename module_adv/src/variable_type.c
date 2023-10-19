#include "stdio.h"


struct Person {

    char a;       //0~7 char占1字节,内存对齐,后7位不用
    long long b;  //8~15  long long 占8字节
    char c;       //16~17 char占1字节
    int d;        //18~23 int占4字节,内存对齐，后3位不用

};

struct Person2 {

    char a;
    int d;
    char c;
    struct Person person;

};
/**
 *有效对齐值与指定对齐值，取对齐值=min(有效对齐值,指定对齐值)
 */
#pragma pack(2)
struct Person3 {

    char a;
    int b;

};
#pragma pack()

/**
 * 变量指针步长
 */
void main_variable_pointer_step01() {

    struct Person p1 = {'x', 164, 'y', 12};
    struct Person2 p2 = {'z', 123, 'n', p1};
    struct Person3 p3 ;
    printf("p3 sizeof : %d\n", sizeof(p3));
    char *p1p = &p1;
    printf("a = %c\n", *p1p);
    printf("b = %d\n", *(long long *) (p1p + 8));
    printf("c = %c\n", *(char *) (p1p + 16));
    printf("d = %d\n", *(int *) (p1p + 20));

    char *p2p = &p2;
    printf("p2 a = %c\n", *p2p);
    printf("p2 d = %d\n", *(p2p + 4));
    printf("p2 c = %c\n", *(p2p + 8));
    printf("p2 person.a = %c\n", *(p2p + 16));
}

void void01_func(void) {
    /**
     * 定义void类型返回，如果return加上返回值，会有警告，但可以程序可以运行
     */
    return 10;
}

/**
 * 1.void 无类型，不可以通过void创建变量
 * 2.void 用途：限定函数返回值，函数参数
 * 3.void * 万能指针
 *   3.1 可以直接转为任意类型指针，不用强转
 *   3.2 sizeof(void *) 64位编译器8个字节，32位编译器4个字节
 * @return
 */
int main_type_void01() {

    void01_func();

    void *p = NULL;
    int *pInt = NULL;
    char *pChar = NULL;
    pChar = (char *) pInt; //不同类型指针之间，需要强制类型转换才不会报警告。
    pChar = p;//万能指针，不通过强制类型转换，就可以转为任意类型指针。
    return 0;
}

int main() {
    printf("-----------------start variable_type------------------\n");
    main_variable_pointer_step01();
    printf("-----------------end variable_type------------------\n");
    return 0;
}