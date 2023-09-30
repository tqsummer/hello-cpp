#include "stdio.h"

//进制实例01
int main_system_of_numeration_01() {
    printf("variable_type----------------------\n");
    char char1 = -111;
    /**
     * -111 在计算机中存的是补码
     *
     * 原码：1110 1111
     * 反码：1001 0000
     * 补码：1001 0001
     * -111在计算机中存的补码是：1001 0001
     *
     * %d是输出十进制，需要转成原码输出，所以
     * 补码：1001 0001
     * 反码：1110 1110
     * 原码：1110 1111
     * 因为是有符号位：最高位为1，所以是负数：- (2^6 + 2^5 + 2^3 + 2^2 + 2^1+ 2^0) = -(64+32+8+4+2+1) = -111
     *
     * */
    printf("char1 = %d , %x\n", char1, char1);
    char char2 = 145;
    /**
     * 145  在计算机中存的是补码，(超出 -128~127) ，正数的补码就是原码
     * 原码：1001 0001
     * 补码：1001 0001
     * 145在计算机中存的补码是：1001 0001
     *
     * %d是输出十进制，需要转成原码输出，所以
     * 补码：1001 0001
     * 反码：1110 1110
     * 原码：1110 1111
     * 因为是有符号位：最高位为1，所以是负数：- (2^6 + 2^5 + 2^3 + 2^2 + 2^1+ 2^0) = -(64+32+8+4+2+1) = -111
     *
     * 所以 -111 与 145 输出的结果一样，因为他们存的补码都一样，所以最终输出值也一样。
     *
     * */
    printf("char2 = %d\n", char2);

    char char3 = 0x91;
    printf("char3 = %d\n", char3);

    int int1 = 0xffffffff;
    printf("%d\n", int1);

    unsigned int int2 = 0xffffffff;
    printf("%d\n", int2);
}

//进制实例02
int main_system_of_numeration_02() {
    int a = 123;
    int b = 056;
    int c = 0xab;
    printf("a=%d\n", a);
    printf("b=%o,%#o\n", b, b);
    printf("c=%x,%X,%#x,%#X", c, c, c, c);

    return 0;
}

//整数实例01
int main_int_01() {
    int i1, i2;
    //注意，这里需要传参的是变量的地址，变量前需要加&符号。
    //以下实例是接收两个整数，两个整数之前以空格隔开。
    scanf("%d %d", &i1, &i2);
    printf("input value : i1 = %d , i2 = %d \n", i1, i2);
    return 0;
}

//整数实例02
int main_int_02() {
    char a;
    short b;
    int c;
    long d;
    long long e;

    //sizeof 用来测数据类型的大小(字节数)
    printf("char len : %d\n", sizeof(a));
    printf("short len : %d\n", sizeof(b));
    printf("int len : %d\n", sizeof(c));
    printf("long len : %d\n", sizeof(d));
    printf("long long len : %d\n", sizeof(e));

    printf("int len : %d\n", sizeof(int));
    printf("long long len : %d\n", sizeof(long long));
    //

    short s1 = 10; //也可以定义为： short int s1 = 10; 10是int型，会隐形转成short型
    int i1 = 10;
    long l1 = 10l;
    long long ll1 = 10ll; //这里ll不写也可以，int型10会隐形转成long long型
    //%u代表无符号整型
    printf("s1 len : %u\n", sizeof(s1));
    printf("i1 len : %u\n", sizeof(i1));
    printf("l1 len : %u\n", sizeof(l1));
    printf("ll1 len : %u\n", sizeof(ll1));

    printf("s1 : %hd\n", s1);
    printf("i1 : %d\n", i1);
    printf("l1 : %ld\n", l1);
    printf("ll1 : %lld\n", ll1);

    //u代表无符号整型
    unsigned short s2 = 20u;
    unsigned int i2 = 20u;
    unsigned long l2 = 20lu;
    unsigned long long ll2 = 20llu;

    printf("s1 : %hu\n", s2);
    printf("i1 : %u\n", i2);
    printf("l1 : %lu\n", l2);
    printf("ll1 : %llu\n", ll2);


    return 0;
}


//char实例01
int main_char_01() {
    char ch1 = 'a';
    printf("ch1 -> ascii : %d\n", ch1); //output : 97
    printf("ascii 86 -> char : %c\n", 86);

    //A (65) 转 a(97) ,之间差32
    char ch2 = 'A';
    ch2 = ch2 + 32; //或者 ch2 -' ' ,因为' '空格字符的ascii值是32
    printf("A + 32 -> : %c\n", ch2);


    char ch3 = 'a';
    printf("ch3 sizeof : %d\n", sizeof(ch3)); // output : 1
    printf("'a' sizeof : %d\n", sizeof('a')); // output : 4  因为 'a'是 97 ,97是整数,int类型的sizeof是4字节。


    //字符'8'转数字8
    char ch4 = '8';
    ch4 = ch4 - '0'; // 或者 ch4 -48 ,因为'0'的ascii值是48
    printf("ch4 - '0' -> %d\n", ch4);


    return 0;
}

int main_char_02() {
    char ch1;
    char ch2;
    //只会从标准输入读取一个字符

    //语句1
    scanf("%c", &ch1);
    printf("1. ch1 : %c,%d\n", ch1, ch1);

    //语句2
    scanf("%c", &ch1);
    printf("2. ch1 : %c,%d\n", ch1, ch1);

    //语句3
    scanf("%c", &ch1);
    printf("3. ch1 : %c,%d\n", ch1, ch1);

    /**
     * 情况1：输入一个字符后按回车
     * 语句1：输出这个字符
     * 语句2：输出回画车
     * 语然3：等待输入
     *
     * 情况2：输入二个字符后按回车
     * 语句1：输出第一个字符
     * 语句2：输出第二个字符
     * 语然3：输出回车
     *
     * 情况3：输入三个字符或三个以上的字符后按回车
     * 语句1：输出第一个字符
     * 语句2：输出第二个字符
     * 语然3：输出第三个字符
     */
    return 0;
}

int main_char_03() {

    //语句1
    char ch1 = getchar();
    printf("1. ch1 : %c,%d\n", ch1, ch1);

    //语句2
    char ch2 = getchar();
    printf("2. ch2 : %c,%d\n", ch2, ch2);

    //语句3
    char ch3 = getchar();
    printf("3. ch3 : %c,%d\n", ch3, ch3);


    /**
     * 情况1：输入一个字符后按回车
     * 语句1：输出这个字符
     * 语句2：输出回画车
     * 语然3：等待输入
     *
     * 情况2：输入二个字符后按回车
     * 语句1：输出第一个字符
     * 语句2：输出第二个字符
     * 语然3：输出回车
     *
     * 情况3：输入三个字符或三个以上的字符后按回车
     * 语句1：输出第一个字符
     * 语句2：输出第二个字符
     * 语然3：输出第三个字符
     *
     * 效果与使用scanf()一样
     */

    return 0;
}


int main_float_01() {
    float f1 = 3.1415926456;
    double d1 = 3.1415926456;

    //默认输出6位小数
    printf("f1 : %f\n", f1);
    printf("d1 : %lf\n", d1);

    //float类型能够保证的精度是7位有效数字
    //double类型能够保证的精度是15位有效数字
    printf("f1 : %.8f\n", f1); // 3.14159274 保证的精度是：3.141592 ,7位
    printf("d1 : %.8lf\n", d1);

    //%e或%E打印科学计数
    printf("f1 : %e , %E\n", f1, f1);
    printf("d1 : %e , %E\n", d1, d1);

    return 0;
}

int main_str_01() {
    printf("%s\n", "hello world");

    return 0;
}

//输出格式
int main_output_format_01() {
    printf("here%20s\n", "hello world");

    return 0;
}

int main() {
    main_char_03();
    return 0;
}