# 文件

文本文件：存储时，是将字符的ascii值存在磁盘中，取的时候将数值(ascii)翻译成对应的字符。    
二进制文件：存的是二进制，取的是二进制。

## 文件流指针

当打开一个文件时，系统会返回一个结构体，这个结构本有对此文件操作的所有信息。

调用fopen时，系统返回这个结构体地址
> FILE *P = fopen("<文件路径>");  
> fputc('a',P); //向文件中写入一个字符

## 打开文件

FILE *p = fopen(<文件路径>,<打开方式>);  
成功返回FILE结构体地址,失败返回NULL

打开方式：

| 打开模式   | 含义                                 |
|--------|------------------------------------|
| r或rb   | 以只读方式打开文件(不创建文件)                   |
| w或wb   | 以写方式打开文件(如果文件存在则清空文件，文件不存在创建一个文件)  |
| a或ab   | 以追加方式打开文件，在末尾添加内容(若文件不存在则创建文件)     |
| r+或rb+ | 以可读可写方式打开文件(不创建文件)                 |
| w+或wb+ | 以读写方式打开文件(如果文件存在则清空文件，文件不存在创建一个文件) |
| a+或ab+ | 以可读可追加方式打开文件，在末尾更改文件(若文件不存在则创建文件)  |

b代表二进制文件

## 关闭文件

fclose(FILE *fp)  
功能：关闭文件  
参数：文件流指针

## 设备文件

当启动一个程序时，系统打开3个设备文件    
FILE *stdin = fopen(stdin,"r"); // 键盘 -> stdin(标准输入文件) ->程序  
FILE *stdout = fopen(stdout,"w"); // 程序 -> stdout(标准输出文件) ->终端(屏幕)  
FILE *stderr = fopen(stderr,"w"); // 程序 -> stderr(标准错误文件) ->终端(屏幕)

## 读写文件

```c
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

```

### fprintf 格式内容写入文件

| 函数                                     | 描述                       |
|----------------------------------------|--------------------------|
| printf(char *__format,...)             | 将格式化内容输出到标准输出(屏幕)        |
| sprintf(char * buf,char *__format,...) | 将格式化内容输出到字符串(char buf[]) |
| fprintf(FILE * fp,char *__format,...)  | 将格式化内容输出到文件流(FILE *fp)   |

### fscanf 读取文件中格式数据

以下...需要传的是变量地址

| 函数                                    | 描述          |
|---------------------------------------|-------------|
| scanf(char *__format,...)             | 从终端读取格式化输入  |
| sscanf(char * buf,char *__format,...) | 从字符串读取格式化输入 |
| fscanf(FILE * fp,char *__format,...)  | 从文件流读取格式化输入 |

### fwrite

size_t fwrite(const void *ptr,size_t size,size_t nmemb,FILE *stream)

功能：以数据块的方式给文件写入内容  
参数：  
ptr:准备写入文件数据的地址  
size:写入文件内容的块数据大小    
nmemb:写入文件的块数 （写入文件数据总大小为：size * nmemb）
stream:已经打开的文件指针  
返回值：  
成功：实际成功写入文件数据的块数目，些值和nmemb相等。

### fread

size_t fread(const void *ptr,size_t size,size_t nmemb,FILE *stream)

功能：以数据块的方式从文件读取内容  
参数：  
ptr:存放读取出来数据的地址  
size:读取文件内容的块数据大小    
nmemb:读取文件的块数 （读取文件数据总大小为：size * nmemb）
stream:已经打开的文件指针  
返回值：  
成功：实际成功读取文件数据的块数目，些值比nmemb小，但大于0，说明读取文件的结尾。  
失败：0

```c
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
Person persons[3] = {
{
"fxq", 41
},
{
"benjamin", 12
},
{
"lj7", 28
}
};
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
```

### fseek

int fseek(FILE *stream,long offset,int whence)  
功能：称动文件流(文件光标)的读写位置

参数：  
stream:已经打开的文件指针   
offset:根据whence来移动的位移数(偏移量)
，可以是正数，也可以是负数。正数是右移，负数是左移。如果向左移动的字节数超过文件开头会出错返回，如果向右移的字节数据超过了文件末尾，再次写入时将增大文件尺寸。

whence:取值  
SEEK_SET:从文件开头移动offset个字节  
SEEK_CUR:从当前位置移动offset个字节  
SEEK_END:从文件末尾移动offset个字节

//光标相对于开头向右移动5字节  
fseek(fp,5,SEEK_SET);

//光标移动到开头  
fseek(fp,0,SEEK_SET);

//光标相对于当前位置向右移动5字节  
fseek(fp,5,SEEK_CUR);

//光标相对于末尾向左移动5字节  
fseek(fp,5,SEEK_END);

```c
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

fclose(fp_src);
}
```

### rewind

将光标移动的文件开头，和fseek(fp,0,SEEK_SET);一样

### ftell

返回文件流当前光标的位置距离开头的偏移量

将光标移动至末尾，再调用ftell可以测出文件的字节大小。

### stat

查看文件信息

stat(const char *_Filename,struct stat *_Stat);

_Filename : 文件路径  
Stat : stat结构体的指针

成功：0
失败：-1

```c
#include "sys/stat.h"
/**
 * 获取文件信息stat函数
 */
void main_file_stat01() {
    struct stat buf;
    int ret = stat("main_file_rw_file06.txt", &buf);
    if (ret < 0) {
        printf("file not found\n");
        return;
    }

    printf("file size : %d \n", buf.st_size);
}
```

### remove

删除文件

remove(const char *_Filename)

_Filename : 文件路径

成功：0
失败：-1

### rename

文件重命名

rename(const char *_OldFilename,const char *_NewFilename)

_OldFilename : 老文件名  
_NewFilename : 新文件名

成功：0
失败：-1

## 文件缓冲区

缓冲区，就是内存中的一块临时的空间

将字符写入文件，调用系统调用进入内核 ，需要消耗资源和时间

3种刷新缓冲区方法：

1. 当内容满了，会刷新缓冲区，就会写入文件
2. 调用fflush强制刷新缓冲区
3. 程序正常退出

windows下标准输出stdout文件，没有缓冲区
linux下有，遇到\n才会刷新缓冲区

标准输入不能调用fflush强制刷新
