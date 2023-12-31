# 变量和数据类型

## 变量

常量：程序运行中不能改变的量

* 整型常量： 1、200
* 字符常量： 'A'
* 字符串常量："ABC"
* 浮点型常量：3.14

变量：程序运行中可以被改变的量，存在于内存中  
变量需要定义：  
定义：在内存中开辟空间，告诉编译器有这个变量（声明）

变量的定义形式：  
数据类型 变量名

* int 4字节
* short 2字节
* long windows中 4字节、linux 32位4字节；64位8字节
* char 1字节
* float 4字节
* double 8字节

extern short SUM //声明变量SUM，并没有开辟空间，不能进行赋值操作，告诉编译器有这个变量（可能在其他文件中定义了）

### const

const修饰的变量，不能通过变量名进行修改内容

## 进制

* 二进制(BIN)：逢二进一
* 八进制(OCT)：逢八进一
* 十进制(DEC)：逢十进一
* 十六进制(HEX)：逢十六进一

| 进制   | 规则    | 缩写  | 数字区间    | 书写             |
|------|-------|-----|---------|----------------|
| 二进制  | 逢二进一  | BIN | 0,1     | 不支持            |
| 八进制  | 逢八进一  | OCT | 0~7     | 以0开头，例0123     | 
| 十进制  | 逢十进一  | DEC | 0~9     | 正常数字           | 
| 十六进制 | 逢十六进一 | HEX | 0~9,a-f | 以0x或0X开头，例0X2A |

<strong>C语言中不可以书写二进制</strong>

### 八进制数、十进制数和十六进制数的输出

|      | short       | 	int      | 	long       |
|------|-------------|-----------|-------------|
| 八进制  | 	%ho        | 	%o       | 	%lo        |
| 十进制  | 	%hd        | 	%d       | 	%ld        |
| 十六进制 | 	%hx 或者 %hX | 	%x 或者 %X | 	%lx 或者 %lX |

```c
int a = 123;
int b = 056;
int c = 0xab;
printf("a=%d\n", a); //a=123
printf("b=%o,%#o\n", b, b); //b=56,056
printf("c=%x,%X,%#x,%#X", c, c, c, c); //c=ab,AB,0xab,0XAB

```

### 十进制转二进制

例：13

| 进制数 | 转换数 | 余数 | 说明    |
|-----|-----|----|-------|
| 2   | 17  |    | 开始除以2 |
| 2   | 6   | 1  | 得商6余1 | 
| 2   | 3   | 0  | 得商3余0 | 
| 2   | 1   | 1  | 得商1余1 | 
|     | 0   | 1  | 得商0余1 |

得到的结果余数需要倒序，下面的是高位，所以结果是：1101

### 二进制转十进制

| 1     | 0     | 1     | 0     | 1     | 1     |
|-------|-------|-------|-------|-------|-------|
| 1*2^5 | 0*2^4 | 1*2^3 | 0*2^2 | 1*2^1 | 1*2^0 |
| 32    | 0     | 8     | 0     | 2     | 1     |

结果是：32+0+8+0+2+1=43

### 八进制转二进制

因为八进制最大值是7，7可以用三位二进制表示，所以三个二进制表示一个八进制  
例0257,八进制257转二进制

| 2  | 5   | 7   |
|----|-----|-----|
| 10 | 101 | 111 |

结果就是：10101111

### 二进制转八进制

1101010101010101111  
001 101 010 101 010 101 111

| 001 | 101 | 010 | 101 | 010 | 101 | 111 |
|-----|-----|-----|-----|-----|-----|-----|
| 1   | 5   | 2   | 5   | 2   | 5   | 7   |

结果是：01525257

### 十进制转十六进制

例：123

| 进制数 | 转换数 | 余数    | 说明                 |
|-----|-----|-------|--------------------|
| 16  | 123 |       | 开始除以16             |
| 16  | 7   | 11(b) | 得商7余11,十六进制11用b来表示 |
|     | 0   | 7     | 得商0余7              |

得到的结果余数需要倒序，下面的是高位，所以结果是：7b

### 十六进制转十进制

例：0x27b

| 2      | 7      | b      |
|--------|--------|--------|
| 2*16^2 | 7*16^1 | b*16^0 |
| 512    | 112    | 11     |

结果是：512+112+11=635

### 十六进制转二进制

因为八进制最大值是15，15可以用四位二进制表示，所以四个二进制表示一个十六进制

例：0x27b

| 2  | 7    | b    |
|----|------|------|
| 10 | 0111 | 1011 |

结果就是：1001111011

### 二进制转十六进制

例：1001010111101  
0001 0010 1011 1101

| 0001 | 0010 | 1011  | 1101  |
|------|------|-------|-------|
| 1    | 2    | 11(b) | 13(d) |

结果是：0x12bd

### 十六进制转八进制

先转二进制，再二进制转八进制

### 八进制转十六进制

先转二进制，再二进制转十六进制

## 数据类型

作用：告诉编译器数据在内存中需要占用的空间

### 有符号数和无符号数

|                  | char         | short          | int , long int | long long , __int64) |
|------------------|--------------|----------------|----------------|----------------------|
| 位数               | 1字节(8位)      | 2字节(16位)       | 4字节(32位)       | 8字节(64位)             |
| signed (default) | 1符号位,7数据位    | 1符号位,15数据位     | 1符号位,31数据位     | 1符号位,63数据位           |
| unsigned         | 8数据位         | 16数据位          | 32数据位          | 64数据位                |
| signed 数范围       | -2^7 ~ 2^7-1 | -2^15 ~ 2^15-1 | -2^31 ~ 2^31-1 | -2^63 ~ 2^63-1       |
| unsigned 数范围     | 0 ~ 2^8-1    | 0 ~ 2^16-1     | 0 ~ 2^32-1     | 0 ~ 2^64-1           |

signed char num; # 有符号数 (默认有符号数)  
unsigned char num; # 无符号数

有符号：可以表示正数和负数  
无符号：只能表示正数

* signed char |符号位|数据位|数据位|数据位|数据位|数据位|数据位|数据位|    
  有符号char：第一位代表符号位，后面七位代表数据位  
  符号位：1代表负数，0代表正数
  例：10000001为-1，00001001为9
  数的范围
  > 负数：10000000 ~ 11111111 -> -0 ~ -127  
  > 正数：00000000 ~ 01111111 -> +0 ~ +127  
  > 规定：将-0表示成-128  (-2^7 ~ 2^7-1)
  > signed char的数值范围为：-128 ~ +127 ，共256个数

* unsigned char |数据位|数据位|数据位|数据位|数据位|数据位|数据位|数据位|  
  八位都是数据位  
  例：10000001为129，00001001为9
  > unsigned char数的范围:0 ~ 255 (0 ~ 2^8-1)

### 原码、反码、补码

|    | 正数     | 负数                     |
|----|--------|------------------------|
| 原码 | 不变(原码) | 原始二进制码                 |
| 反码 | 不变(原码) | 符号位不变，数据位取反(0->1,1->0) |
| 补码 | 不变(原码) | 反码+1                   |

为了保证负数计算的准确性，以及0状态的唯一性，所以计算机中有符号数存的是补码，正数的补码就是原码。

* 赋值时，赋的是十进制，给的是原码。如果赋值给的是八进制或十六进制给的是补码。
* 打印时，十进制打印要的是原码，如果是八进制或十六进制打印要的是补码。


* 注意
    1. 负数计算机中如果存原码，会导致两个问题，负数运算不正确，0的状态有两种(-0和+0)
    2. 负数计算机中如果存反码，负数运算结果正确，但是0的状态还是两种。
    3. 负数计算机中如果存补码，负数运算结果正确，0的状态只有一种，也正确。

原码：数原始的二进制码
> -0 ： 1000 0000  
> +0 ： 0000 0000  
> -1 ： 1000 0001  
> +1 ： 0000 0001
>
> 1 + (-1) = ?  
> 0000 0001  
> 1000 0001  
> 1000 0010 = -2 计算不正确

反码：正数的反码不变，负数的反码(符号位不变，数据位取反)
> -0 ： 1111 1111  
> +0 ： 0000 0000  
> -1 ： 1111 1110  
> +1 ： 0000 0001
>
> 1 + (-1) = ?
> 0000 0001
> 1111 1110
> 1111 1111 = -0

补码：正数的反码不变，负数的补码等于反码+1
> -0 ： 0000 0000  
> +0 ： 0000 0000  
> -1 ： 1111 1111  
> +1 ： 0000 0001
>
> -0 = 反码 + 1 = 1111 1111 + 1= 1 0000 0000 = 0000 0000 ->1溢出,所以得到的补码为 0000 0000   
> -1 = 反码 + 1 = 1111 1110 + 1= 1111 1111
>
> 1 + (-1) = ?
> 0000 0001  
> 1111 1111  
> 1 0000 0000 = 0   (1溢出所以结果为0，计算正确，0状态正确)

#### 原码求补码

1. 原码
2. 反码(符号位不变，数据位取反)
3. 反码+1，得到补码

例：-23
> 原码： 1001 0111  
> 反码： 1110 1000  
> 补码： 1110 1001

#### 补码求原码

1. 补码
2. 反码(符号位不变，数据位取反)
3. 反码+1，得到原码

例：补码为1110 1001

> 补码：1110 1001  
> 反码：1001 0110  
> 原码：1001 0111 = -23

计算机中存的负数都是补码。  
printf("num=%d\n",num)  -> num是负数，计算机存的是补码，现在%d需要打印的是十进制，十进制打印要的是原码，所以需要补码转成原码。

* 计算机中有符号数存的是补码，正数的补码就是原码

> char char1 = -111;
>> char1是负数，存计算机时，会转成补码存  
> > 原码：1110 1111  
> > 反码：1001 0000  
> > 补码：1001 0001  
> > 所以-111在计算机中存的是补码：1001 0001

> char char2 = 145;
>> char2是正数，存计算机时，会存补码，正数的补码就是原码  
> > 原码：1001 0001  
> > 补码：1001 0001  
> > 所以145在计算机中存的补码是：1001 0001

### 整数

#### 整数常用函数

scanf()：从键盘(标准输入)获取值，传值是变量地址
> int i1,i2   
> scanf("%d %d", &i1, &i2);  
> printf("input value : i1 = %d , i2 = %d \n", i1, i2);

sizeof():用来测数据类型的大小(字节数)，传值可以是变量也可以是类型
> char a;  
> printf("char len : %d\n", sizeof(a));  
> printf("char len : %d\n", sizeof(char));

* 其它函数可以查看

#### 整数打印输出

|     | short | 	int | 	long | long long |
|-----|-------|------|-------|-----------|
| 有符号 | 	%hd  | 	%d  | 	%ld  | %lld      |
| 无符号 | 	%ud  | 	%u  | 	%lu  | %llu      |

> char 打印十六进制的bug，打印时需要强制转换为unsigned char
>
> 究其原因，%x 是 unsigned int 或 int 型输出 ，  
> 所以 printf("%x", a) 在执行时将自动将 a 类型提升（char 将提升至 int；unsigned char 将提升至 unsigned int），  
> 注意到 char 是 signed（有符号的），如果这时 a 是负数 ，在提升的时候前面将会补1 ，即象反例中的 0xf1 => 0xfffffff1；  
> 而unsigned char 在提升的时候只会补0

### 字符型

单个字符用单引号''连接

> 字符'0'的ascii码值：48  
> 字符'1'的ascii码值：49  
> 字符'A'的ascii码值：65  
> 字符'B'的ascii码值：66  
> 字符'a'的ascii码值：97  
> 字符'b'的ascii码值：98

因为字符所对应的最大ascii值是127，所以用char类型就可以存下所有的字符。

%c是打印ascii值对应的字符

```c
int main_char_01() {
    char ch1 = 'a';
    printf("ch1 -> ascii : %d\n", ch1); //output : 97
    printf("ascii 86 -> char : %c\n", 86); //output : V ,%c是打印ascii值对应的字符

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

```

### 浮点型

存小数的数据类型

|        | float | double |
|--------|-------|--------|
| 字节数    | 4     | 8      |
| 精度有效位  | 7位    | 15位    |
| 输出     | %f    | %lf    |
| 输出8位小数 | %.8f  | %.8lf  |
| 科学计数   | %e或%E | %e或%E  |

### 字符串

#### 字符串常量

""双引号引起的内容是字符串  
符字串输出符：%s表示。

字符串常量与字符常量的不同：
> 'a'为字符常量 -> 'a' 一个a字符  
> "a"为字符串常量 -> 'a'和'\0' 一个a字符和一个\0字符

每个字符串的结尾，编译器会自动的添加一个结束标志位\0。

> 数字0 : ascii值是0  
> '0'  : ascii值是48  
> \0   : ascii值是0  
> 0 == \0 # 数字0与\0是一样的

### 打印输出格式

> float : %m.nf # m代表宽度,n代表小数点位数
> int : %md # m代表宽度,没有小数点位数

输出的原始内容宽度 < m ,输出原始内容补足为m宽度,不足部分使用空格填补  
输出的原始内容宽度 >= m ,输出原始内容

|      | 格式     | 输出        |
|------|--------|-----------|
| m.n  | %m.nf  | 使用空格补全m位  |
| -m.n | %-m.nf | 左对齐,空格补右侧 |
| 0m.n | %0m.f  | 使用0补全m位   |

### 类型限定符

| 限定符      | 说明                   |
|----------|----------------------|
| extern   | 声明(告诉编译器有这个变量，不开辟空间) | 
| const    | 修饰变量内容不可改变           | 
| volatile | 防止编译器优化              |
| register | 建议将变量定义在寄存器中         |

### 数组

把若干个相同数据类型的变量存放在一起连续的内存空间

* 数组名和变理名定义方法一样
* 符号与[]结合代表这个是一个数组
* 数组中的元素的个数由[]里面的数值决定

例：  
int ia1[10]  # 一个长度为10的int数组  
char ca1[20] # 一个长度为20的字符数组  
char cpa1[30] # 一个长度为30的字符指针数组

初始化  
int num[10] = {1,2,3,4,5,6,7,8,9,10}

数组字节总大小  
sizeof(num)

组数的元素个数
int n = sizeof(num)/sizeof(num[0])

#### 数组在内存如何存储

* 启动一个程序，系统会给这个程序分配一块内存空间
* 内存的最小单位是一个字节
* 内存中的第一个字节都会有编号，这个编号就是内存地址
* <strong>数据在内存中的地址，就是这个数据内存中的起始地址</strong>

> int a[5]    
> a[0]  -> 第0个元素    
> &a[0] -> 第0个元素的地址    
> 数组名a -> 代表数组，也代表第0个元素的地址，a == &a[0]   
> 所以数组名是一个常量，是一个地址  
> &a 整个数组的地址 -> &a == a ==&a[0] 数值上相等
>
> 但是含义上不同  
> &a[0]+1 元素的地址加1,跨过一个元素 => a[0]元素结束地址+1  
> a+1 同上，元素的地址加1,跨过一个元素 => a[0]元素结束地址+1  
> &a+1 整个数组的地址加1，跨过整个数组 => a[4]元素结束地址+1

```c
void main_array_name01() {
    int a[5];
    printf("&a[0] address : %u\n", &a[0]);
    printf("a address : %u\n", a);
    printf("&a address : %u\n", &a);

    printf("-------------add 1--------------\n");

    printf("&a[0]+1 address : %u\n", &a[0] + 1); //跨过一个元素的地址
    printf("a+1 address : %u\n", a + 1); //跨过一个元素的地址
    printf("&a+1 address : %u\n", &a + 1); //跨过整个数组的地址

    /**
     * 执行结果
     * &a[0] address : 322959232
     * a address : 322959232
     * &a address : 322959232
     * -------------add 1--------------
     * &a[0]+1 address : 322959236
     * a+1 address : 322959236
     * &a+1 address : 322959252
     *
     */
}
```

#### 字符数组

普通字符数组：char a[5] = {'h', 'e', 'l', 'l', 'o'};  
字符串：char a[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

| 字符数组定义                                            | %s输出                   | %c输出     |
|---------------------------------------------------|------------------------|----------|
| char a[7] = {'h', 'e', 'l', 'l', 'o', '1','\0'｝   | hello1                 | hello1   |
| char a[8] = {'h', 'e', 'l', 'l', 'o', '2','\0',a｝ | hello2                 | hello2 a |
| char a[] = a[7] = "hello3"  ->字符组数size为6          | hello3                 | hello3   |
| char a[] = {'h', 'e', 'l', 'l', 'o', '5'｝         | hello3<这里出现未知字符直到\0为止> | hello5   |

```c
void main_array_init03(){
    char s5[6] = {'h', 'e', 'l', 'l', 'o', '5'};
    printf("s5 str : %s\n", s5);  
    
    /**
     * 输出结果每次都不一样：
     * 取决于\0的位置，字符串到\0位置截至
     * 
     * s5 str : hello5砾it
     * s5 str : hello5瘘艁
     * 
     */
}
```

* 字符数组中含有\0字符的，它也是字符串。
* %s输出时，显示的字符串是是截至到\0字符之前

char a[10]="" ->这个字符数组中10个字符都是\0    
char a[10]="hello" ->这个字符数组中前面5个字符分别是：hello，后面5个字符都是\0。

##### 字符数组标准输入

1. scanf("%s",a)

* scanf("%s",a)，这里的a前面不需要加&，因为字符数组a本身代表的就是数组a的地址。
* scanf %s格式读取，遇到\n结束；遇到空格结束。
* 缺点：1.遇到空格会提前结束，2.如果存放读取字符的空间不足，继续向后存放，会造成内存污染。

```c
void main_array_stdin01() {
    char a[128] = "";

    /**
     * 1.%要求传的参数是存放读取字符串的地址
     * 2.scanf(%s)遇到\n结束并且遇到空格也结束
     * 3.键盘输入 hello world,a字符串得到的是：hello
     * 4.如果存放读取字符的空间不足，继续向后存放，会造成内存污染
     */
    scanf("%s", a);
    printf("a = %s\n", a);
}
```

2. gets()库函数  
   从键盘读取字符串。

* ()里面的参数要的是存放读取字符串的地址
* gets遇到\n结束，但是遇到空格不结束
* 也会造成内存污染

```c
void main_array_stdin02() {
    char a[128] = "";
    /**
     * 1.()里面的参数要的是存放读取字符串的地址
     * 2.gets遇到\n结束，但是遇到空格不结束
     * 3.键盘输入 hello world,a字符串得到的是：hello world
     * 4.也会造成内存污染
     */
    gets(a);
    printf("a = %s\n", a);
}
```

3.fgets()库函数  
从键盘读取一个字符串  
fgets(read_buffer,read_max_count,stdin)
> read_buffer : 读取后存放到的字符数组  
> read_max_count：读取最大的字节数  
> stdin：读取源，这里是标准输入(键盘)

fgets相对于scanf和gets
> 优点：不会造成内存污染  
> 缺点：遇到回车键\n会结束，但会读取回车键\n (scanf和gets遇到回车键\n会结束，但不会读取回车键)

```c
void main_array_stdin03() {
    char buf[10] = "";
    /**
     * 1.参数1：buf读取后存放的字符数组，参数2：sizeof(buf)最大读取的字节数，参数3：stdin键盘标准输入
     * 2.键盘输入 hello world,buf字符串得到的是：hello wor（9个可见字符：hello wor，1个不可见字符：\0，正好10个字符）
     * 3.不会造成内存污染
     * 4.如果buf空间足，最后键盘输入的回车键\n也会被读取
     */
    fgets(buf, sizeof(buf), stdin);
    /**
     * 解决fgets读取回车键\n问题
     * strlen获取有效字符长度
     * 最后一个字符设置为\0,来解决读取的回车键\n问题 
     */
    int len = strlen(buf);
    buf[len - 1] = '\0';
    /**
     *
     */
    printf("buf = %s\n", buf);
}
```

解决fgets读取回车键\n问题
> 调用strlen获取有效字符长度 -> len  
> buf[len-1]='\0',buf最后一个字符设置为\0,来解决读取的回车键\n问题

##### 字符数组输出

> prinf("%s\n",buf);
> puts(buf) //参数buf：数组首元素地址。执行后有换行  
> fputs(buf,stdout) //参数buf：数组首元素地址，参数stdout：标准输出(屏幕)  

