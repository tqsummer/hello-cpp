#include <stdio.h>
#include <string.h>
#include <malloc.h>


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

}

struct company {
    char *company_name;
    char address[64];
};


struct employee {
    struct person personal;
    struct company company;
    int work_year;
};


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


/**
 * 结构体定义方式二
 * 这种方式定义结构体变量时，可以不用加struct关键字
 */
typedef struct {
    char *name;
    char age;
    char sex;
} teacher;

/**
 * 结构体定义方式一
 */
struct student {
    char *name;
    char age;
    char sex;
};


/**
 * 结构体类型数组
 */
void main_struct_array01() {
    struct student students[3] = {{"fxq",      41, 1},
                                  {"benjamin", 11, 1}};
    students[2].name = "lj7";
    (&students[2])->age = 41;
    (&students[2])->sex = 0;

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        printf("name : %s , age : %d , sex : %d\n", students[i].name, students[i].age, students[i].sex);
    }
}

/**
 * 结构体定义赋值
 */
void main_struct_def01() {
    struct student student1 = {"fxq", 41, 1};
    //给结构体赋值
    //1.通过结构体变理操作结构体成量，使用点域.操作
    student1.age = 20;
    //2.通过结构休的地址操作结构体成员，使用->
    (&student1)->name = "fxq2";
    printf("%s,%d,%d", student1.name, (&student1)->age, student1.sex);
}


int main() {
    main_struct_typedef01();
}
