#include <stdio.h>
#include "sys/stat.h"

/**
 * 获取文件信息stat函数
 */
void main_file_stat01() {
    struct stat buf;
    int ret = stat("main_file_rw_file061.txt", &buf);
    if (ret < 0) {
        printf("file not found\n");
        return;
    }

    printf("file size : %d \n", buf.st_size);
    rename()
}

/**
 * fseek 文件光标移动
 */
void main_file_rw_file06() {
    FILE *fp_src = fopen("main_file_rw_file06.txt", "w");
    fputs("hello world hehe haha hoho!", fp_src);
    /**
     * 光标移动到距头5个字节处（o后）
     */
    fseek(fp_src, 5, SEEK_SET);
    /**
     * 写入字节'-',o后面空格变为-,当前光标在-后
     */
    fputc('-', fp_src);
    /**
     * 移动光标到文件头
     */
    fseek(fp_src, 0, SEEK_SET);
    /**
     * 光标移动到当前位置11个字节后,因为当前光标位置是头部，所以移动11个字节后是（d后）
     */
    fseek(fp_src, 11, SEEK_CUR);
    /**
     * 写入字节'-',d后面空格变为-,当前光标在-后
     */
    fputc('-', fp_src);
    /**
     * 光标移动到当前位置4个字节后,（e后）
     */
    fseek(fp_src, 4, SEEK_CUR);
    /**
     * 写入字节'-',e后面空格变为-,当前光标在-后
     */
    fputc('-', fp_src);
    /**
     * 光标移动从末尾位置往左移6个字节（a后）
     */
    fseek(fp_src, -6, SEEK_END);
    /**
     * 写入字节'-',a后面空格变为-,当前光标在-后
     */
    fputc('-', fp_src);
    /**
     * 移动光标到文件末尾
     */
    fseek(fp_src, 0, SEEK_END);
    /**
     * 当前位置向左移动1个字节（o后）
     */
    fseek(fp_src, -1, SEEK_CUR);
    /**
    * 写入字节'?',o后面!变为?,当前光标在?后（末尾）
    */
    fputc('?', fp_src);


    int offset = ftell(fp_src);
    printf("file offset : %d", offset);

    fclose(fp_src);
}

/**
 * 公用结构体可以放在.h文件中定义
 */
typedef struct person {
    char name[16];
    int age;
} Person;

/**
 * fread 文件中读取块
 */
void main_file_rw_file05() {
    FILE *fp_src = fopen("main_file_rw_file04.txt", "r");
    if (fp_src == NULL) {
        perror("open error");
    }

    Person persons[3];

    for (int i = 0; i < 3; i++) {
        int count = fread(&persons[i], sizeof(Person), 1, fp_src);
        printf("count : %d\n", count);
        printf("persons[%d] : name = %s , age : %d\n", i, persons[i].name, persons[i].age);

    }

    fclose(fp_src);
}

/**
 * fwrite 块写入文件
 */
void main_file_rw_file04() {
    Person persons[3] = {{"fxq",      41},
                         {"benjamin", 12},
                         {"lj7",      28}};
    FILE *fp_src = fopen("main_file_rw_file04.txt", "w");
    /**
     * 每块大小一个字节，写入sizeof(person)=60块
     */
    int count = fwrite(persons, 1, sizeof(persons), fp_src);
    /**
     * 每块大小sizeof(person)=60个字节，写入1块
     */
    //int count = fwrite(persons,sizeof(persons) , 1, fp_src);
    /**
     * 每块大小结构体大小20个字节，写入sizeof(person)/sizeof(person[0])=3块
     */
    //int count = fwrite(persons, sizeof(persons[0]), sizeof(persons) / sizeof(persons[0]), fp_src);
    printf("write count : %d", count);
    fclose(fp_src);
}

/**
 * 读取文件写入终端
 */
void main_file_rw_file03() {
    /**
     * 如果源文件是二进制文件，模式改为rb
     */
    FILE *fp_src = fopen(
            "D:\\Workspace\\StudyWorkspace\\CppProjects\\hello-cpp\\cmake-build-debug\\module_basic\\cmake_install.cmake",
            "r");
    /**
    * 如果文件不存在，输出错误信息
    */
    if (fp_src == NULL) {
        perror("open error");
        return;
    }

    char c;
    while (1) {
        c = fgetc(fp_src);
        if (feof(fp_src)) {
            break;
        }
        fputc(c, stdout);
    }

    fclose(fp_src);

}

/**
 * 文件copy
 */
void main_file_rw_file02() {
    /**
     * 如果源文件是二进制文件，模式改为rb
     */
    FILE *fp_src = fopen("a.txt", "r");

    /**
     * 如果文件不存在，输出错误信息
     */
    if (fp_src == NULL) {
        perror("");
    }

    /**
     * 如果源文件是二进制文件，写文件的模式改为wb
     */
    FILE *fp_dest = fopen("cp_a.txt", "w");

    char c;
    while (1) {
        c = fgetc(fp_src);
        /**
         * 判断是否文件末尾
         */
        if (feof(fp_src)) {
            break;
        }
        /**
         * 将字符写入目标文件
         */
        fputc(c, fp_dest);

    }

    fclose(fp_src);
    fclose(fp_dest);
}

/**
 * 读写文件
 * fputc，fgetc
 */
void main_file_rw_file01() {
    /**
     * 已写方式打开文件（文件内空会被清空）
     */
    FILE *fp = fopen("./a.txt", "w");
    if (fp == NULL) {
        perror("open");
        return;
    }
    /**
     * 将一个字符a写入文件中
     */

    char buf[] = "hello";
    int i = 0;
    while (buf[i] != 0) {
        fputc(buf[i++], fp);
    }

    /**
     * 使用完后，关闭文件
     */
    fclose(fp);

    /**
     * 以只读方式打开文件
     */
    FILE *fp_r = fopen("./a.txt", "r");
    char c;
    /**
     * 文本文件可以通过fgetc(*FILE fp)的返回值EOF(-1)来判断文件是否已结束
     * 如果非文本文件的话,文件中读取到-1值，通过以上判断就会结束
     * 所以需要再加上feof(*FILE fp)来判断。
     *
     * feof(*FILE fp)返回值
     * 非0值：已经到文件结尾
     * 0：没有到文件结尾
     *
     * 注：feof()调用前需要调用一次文件流读取，否则直接调用会一直会返回0(没有到文件结尾);
     *
     */
    while ((c = fgetc(fp_r)) != EOF && !feof(fp_r)) {
        printf("c : %c\n", c);
    }

    fclose(fp_r);
}

int main() {
    main_file_stat01();
    return 0;
}