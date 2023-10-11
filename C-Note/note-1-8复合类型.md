# 复合类型

## 结构体定义

定义一个结构体类型

```text
# 方式一
struct <结构体类型名称>
{
    //定义成员变量
};
# 定义结构体类型变量
struct <结构体类型名称> <变量>;

例：
struct A{
    int a;
    char b;
    char* c;
} ;
//定义A变量，不初始化
struct A a_type;
//通过结构体变理操作结构体成量，使用点域.操作
a_type.a=10;
a_type.b='a';
a_type.c="hello";
//通过结构休的地址操作结构体成员，使用->
(&a_type)->b = 20;

//定义A变量并初始化
struct A a_type=｛10，'a',"hello"｝;

//定义A变量给部分成员初始化，其他成员内容都为0
struct A a_type=｛.b='c'｝;

# 方式二
//这种方式，定义结构体的同时，定义该结构体类型的变量
struct <结构体类型名称>
{
    //定义成员变量
} <变量>;

例：
struct A{
    int a;
    char b;
    char* c;
} a_type;



# 方式三
//这种结构体不能复用，因为没有结构体类型名称，所以只能定义变量时使用。
struct 
{
    //定义成员变量
} <变量>;


```

## 结构体数组

是一个数组，数组每个元素都是结构体

```c
/**
 * 结构体类型数组
 */
void main_struct_array01() {
struct student students[3] = {
{
"fxq", 41, 1
},
{
"benjamin", 11, 1
}
};
students[2].name = "lj7";
(&students[2])->age = 41;
(&students[2])->sex = 0;

for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
printf("name : %s , age : %d , sex : %d\n", students[i].name, students[i].age, students[i].sex);
}
}
```

## 结构体套结构体

```c
struct company {
    char *company_name;
    char address[64];
};

struct person {
    char *name;
    char age;
    char sex;
};

struct employee {
    struct person personal;
    struct company company;
    int work_year;
};

/**
 * 结构体套结构体
 */
void main_struct_nested01() {
    struct employee employee;
    employee.company.company_name = "apple";
    strcpy(employee.company.address, "shanghai");
    employee.personal.name = "fxq";
    employee.personal.sex = 1;
    employee.personal.age = 41;
    employee.work_year = 20;

    printf("company : %s ,name : %s , work year : %d", employee.company.company_name, employee.personal.name,
           employee.work_year);
}
```

## 结构体赋值

1. 可以通过内存拷贝的方式赋值memcpy
2. 相同类型的变量可能相互赋值

```c
/**
 * 结构体赋值
 */
void main_struct_assignment01() {
struct employee employee;
employee.company.company_name = "apple";
strcpy(employee.company.address, "shanghai");
employee.personal.name = "fxq";
employee.personal.sex = 1;
employee.personal.age = 41;
employee.work_year = 20;

struct employee employee2;
struct employee employee3;
//可以通过内存拷贝的方式赋值
memcpy(&employee2, &employee, sizeof(employee));
printf("[employee2] company : %s ,name : %s , work year : %d\n", employee2.company.company_name,
employee2.personal.name,
employee2.work_year);

employee.company.company_name = "apple2";

//相同类型的变量可能相互赋值
employee3 = employee;
printf("[employee3] company : %s ,name : %s , work year : %d\n", employee3.company.company_name,
employee3.personal.name,
employee3.work_year);
}
```

## 结构体指针

```c
/**
 * 结构体指针
 */
void main_struct_pointer01() {
//struct person *p;//野指针(没有指向任何地址)
/**
 * 这种方式也可以
 */
//struct person pp;
//struct person *p = &pp;

/**
 * 也可以申请堆空间的方式
 */
struct person *p = malloc(sizeof(struct person));
//通过指针(即地址)堆结构体类型赋值使用->
p->name = "fxq_ha";
p->age = 42;
p->sex = 1;
printf("[person] , name : %s , age : %d ,sex : %d\n", p->name, p->age, p->sex);

}
```

## 共用体

多个变量共用一块内存空间，同一时刻，只有一个变量起作用。    
size是成员变量里最大类型的size

大小端：  
小端：低位存低地址，高位存高地址。    
大端：低位存高地址，高位存低地址。

共同体类型格式:

```c
union u2 {
    short a;
    char b[2];
};


union u1 {
    char a;
    short b;
    int c;
};

/**
 * 共用体判断大小端
 */
void main_struct_union02() {
    union u2 union_u2;
    union_u2.a = 0x0102;
    if (union_u2.b[0] == 0x02) {
        printf("little");
    } else {
        printf("big");
    }

}

/**
 * 共用体
 */
void main_struct_union01() {
    union u1 obj;
    obj.a = 0x08;
    obj.c = 0x0705abac;
    obj.b = 0x1ebc;

    /**
     * char 打印十六进制的bug，需要强制转换为unsigned char
     *
     * 究其原因，%x 是 unsigned int  或  int  型输出 ，
     * 所以 printf("%x", a) 在执行时将自动将 a 类型提升（char 将提升至 int；unsigned char 将提升至 unsigned int），
     * 注意到 char 是 signed（有符号的），如果这时 a 是负数 ，在提升的时候前面将会补1 ，即象反例中的 0xf1 => 0xfffffff1；
     * 而unsigned char 在提升的时候只会补0
     */
    printf("a : %x , b : %x ,c : %x", (unsigned char) obj.a, obj.b, obj.c);
    
    /**
    * 最终结果：
    * obj.a -> 0xbc
    * obj.b -> 0x1ebc
    * obj.c -> 0x7051ebc
    */

}


```

参考: https://www.processon.com/view/link/65255b97f935100f82af0dec

## 结构体作为函数形参

```c
struct person1 {
    char name[128];
    char age;
    char sex;
};

struct person {
    char *name;
    char age;
    char sex;
};

/**
 * 这里传结构体数组
 * @param k  结构体数组
 * @param size 结构体数组个数
 */
void parameter01_func02(struct person1 *k, int size) {
    /**
     * 这里的k是结构体数组首元素地址
     * 结构体地址访问结构体成员变量用:->
     * 结构体访问结构体成员变量用:.(点域)
     */
    for (int i = 0; i < size; i++) {
        /**
         * 点域方式一
         */
        char buf[32];
        sprintf(buf, "fxq__%d", i);
        strcpy((*(k + i)).name, buf);
        //(*(k + i)).age = 20 + i;
        //(*(k + i)).sex = 1;
        /**
         * 点域方式二
         */
        k[i].age = 20 + i;
        /**
         * ->方式
         */
        k->sex = 1;
    }
}

/**
 * 这里传结构体
 * @param k 结构体
 */
void parameter01_func01(struct person k) {
    k.name = "fxq20";
    k.age = 20;
}

void parameter01_func_call() {
    struct person person = {"fxq10", 41, 1};
    struct person1 persons[3];
    /**
     * 清空分配胡数组内容
     */
    memset(persons, 0, sizeof(persons));

    /**
     * 传值
     * parameter01_func01调用会将person结构体内容复制给结构体局部变量k
     * parameter01_func01内对于结构体的变量，都是操作的局部变量k的值。
     * 不会影响实参person的内容。
     * 所以person的打印内容没有变化。
     */
    parameter01_func01(person);
    printf("[person] , name : %s , age : %d , sex : %d\n", person.name, person.age, person.sex);

    /**
     * 传数组，相当于传数组首元素地址
     */
    parameter01_func02(persons, sizeof(persons) / sizeof(persons[0]));
    for (int i = 0; i < sizeof(persons) / sizeof(persons[0]); i++) {
        printf("[person[%d]] , name : %s , age : %d , sex : %d\n", i, persons[i].name, persons[i].age, persons[i].sex);
    }
}

/**
 * 结构体作为形参
 */
void main_struct_parameter01() {
    parameter01_func_call();
}

```

## const修饰结构体指针变量

```c
/**
 * const修饰的结构体指针变量
 */
void main_struct_const_pointer01() {
struct person pp1;
struct person pp2;

/**
 * 这里定义的指针，不能通过*p修改指向地址的内容
 */
const struct person *p1 = &pp1;
//(*p1).name = "hi"; //这里编译报错，不能修改p1指向地址的内容
//p1->name = "hi2";//这里编译报错，不能修改p1指向地址的内容


/**
 * 这里定义的指针,不可以通过p修改地址
 */
struct person *const p2 = &pp1;
//p2 = &pp2  //这里编译报错，不能修改p2的地址
p2->name = "hello fxq";
}
```

## 枚举

枚举：将变量的值一一列举出来，变量的值只限于列举出来的值的范围内。

```text
枚举类型定义： 

enum <枚举名>
｛
    枚举值表
｝;
```

* 在枚举值表中应列出所有可用值，称为枚举元素。
* 枚举值是常量，不能在程序中用赋值语句再对它赋值。
* 枚举本身由系统定义类一个表示序号的数值从0开始顺序定义0，1，2，...

```c
enum BOOL {
    false, true
};

/**
 * typedef <struct|union|enum 类型名> <类型别名>
 * 使用:<类型别名> <变量名>
 */
typedef enum BOOL bool;

/**
 * 创建类bool类型枚举
 * 使用typedef 给枚举类型取别名
 */
void main_struct_enum02() {
    bool aBool = false;
    bool bBool = true;

    printf("aBool : %d , bBool : %d", aBool, bBool);

}

enum enum2 {
    /**
     * 给枚举值赋值，后续的值从该枚举+1
     * 以下枚举值为：D:0,F:2,G:3,H:3,J:4
     */
    D, F = 2, G, H = 3, J
};

enum enum1 {
    /**
     * 枚举值默认值从0开始，+1
     * 以下枚举值为：A:0,B:1,C:2
     */
    A, B, C
};

/**
 * 枚举
 */
void main_struct_enum01() {
    enum enum1 a = A;

    printf("A: %d , B: %d , C: %d\n", A, B, C);
    printf("D: %d , F: %d , G: %d , H: %d , J: %d\n", D, F, G, H, J);
}
```

## typedef定义别名

typedef是用来给类型取别名

typedef <原类型名> <新类型>;

使用:<新类型> <变量名>;

例：typeof int size_t ->这个是将int取了一个别名size_t，其实size_t类型就是int类型。

* 定义宏有些时候跟typeof是一样的效果，但是处理方式不一样。宏是在预处理时将宏进行替换。
* 尽量少用宏，会出现一些问题，见以下代码示例。
  #define <宏名> <类型|数值|表达式>

```c
#define CHAR char
#define CHAR_P char *
#define DEF_MAX 3+4
typedef char CHAR32;
typedef char *CHAR32_P;

/**
 * typedef
 */
void main_struct_typedef01() {
    /**
     * 定义的宏，在预处理的时候会将CHAR替换为char。
     */
    CHAR def_char = 'a';
    /**
     * typedef不会在预处理进行处理
     */
    CHAR32 typedef_char = 'b';
    printf("def_char : %c , typedef_char : %c\n", def_char, typedef_char);

    /**
     * 定义的宏，在预处理的时候会将CHAR_P替换
     * char *def_p1,def_p2 ->  char *def_p1 , char def_p2
     * 所以def_p1是char *类型，sizeof在64位编译器下是8个字节
     * def_p2是char类型，sizeof是1个字节
     */
    CHAR_P def_p1, def_p2;
    /**
     * typedef定义的别名类型是一个整体，typedef_p1, typedef_p2都是char * 类型
     */
    CHAR32_P typedef_p1, typedef_p2;

    printf("def_p1 size : %d , def_p2 size : %d\n", sizeof(def_p1), sizeof(def_p2));
    printf("typedef_p1 size : %d , typedef_p2 size : %d\n", sizeof(typedef_p1), sizeof(typedef_p2));

    /**
     * 定义的宏，在预处理的时候会将DEF_MAX替换
     * int def_result = 5 * DEF_MAX; -> int def_result = 5 * 3 + 4;
     * 所以def_result的结果：19
     * 
     */
    int def_result = 5 * DEF_MAX;
    printf("def_result : %d \n", def_result);
    
}
```

