# C、C++的命名规范

## 1.命名规范

本系列的第一篇，命名风格本就是有关艺术审美，没有美与丑的绝对标准，本文难免带有主观选择倾向，但是会尽量保持客观的态度归纳几种主流的命名风格，仅供参考。制定规范是为了方便团队沟通和利于代码维护，虽然并不能符合每个艺术家的胃口。对于独立开发者，花点时间设计自己的编码风格也是有助于提高能力的，至少可以在看到自己代码的时候感觉美美哒~~
。本文参考了<Google C++ 风格指南>，<Qt 编码风格>，当然还有维基百科，以后不累述。

## 1.1常见命名法

蛇形命名法[snake_case]：

```text
like_this，常见于Linux内核，C++标准库，Boost以及Ruby，Rust等语言。
```

驼峰命名法[camelCase]：

```text
likeThis，为了和帕斯卡命名法区分，本文特指小驼峰式命名法，常见于Qt以及Java。
```

帕斯卡命名法[PascalCase]：

```text
LikeThis，又名大驼峰式命名法，常见于Windows API函数以及C#。
```

匈牙利命名法[Hungarian notation]：

```text
dwWidth，系统匈牙利命名法是被黑的最多的，主要认为在有类型检查的语言里发现类型错误编译器比人更可靠；在有IDE的情况下，找到一个变量的类型也不是一件难事；通常我们看到一个陌生的变量的时候，如果不知道它是干什么的，知道它的类型好像也并没有什么用；并且在重构的时候，如果你要改变一个变量的类型，尽管其功能并没有变，你还是要去修改变量名。所以除非是Windows系统开发，不建议使用系统匈牙利命名法。

rwPosition，匈牙利应用命名法不表示变量的类型，而是用前缀表示变量的目的，或者它代表了什么。这种变量命名方法在帮助程序员理解变量的用途上是很有帮助的。但是建议前缀不要使用缩写，除非所用的缩写是普遍共识。  

C是一门朴素的语言，你使用的命名也应该这样。与Modula-2和Pascal程序员不同，C程序员不使用诸如“ThisVariableIsATemporaryCounter”这样“聪明”的名字。C程序员应该叫它“tmp”，这写起来更简单，也不会更难懂。
然而，当面对复杂情况时就有些棘手，给全局变量取一个描述性的名字是必要的。把一个全局函数叫做“foo”是一种目光短浅的行为。全局函数也一样，如果你有一个统计当前用户个数的函数，应当把它命名为“count_active_user()
”或者简单点些的类似名称，不应该命名为“cntusr()”。    

```

## 1.2三种流行的命名法则

目前，业界共有四种命名法则：驼峰命名法、匈牙利命名法、帕斯卡命名法和下划线命名法，其中前三种是较为流行的命名法。

(1)驼峰命令法。正如它的名称所表示的那样，是指混合使用大小写字母来构成变量和函数的名字。例如，下面是分别用骆驼式命名法和下划线法命名的同一个函数：
printEmployeePaychecks()；
print_employee_paychecks()；

第一个函数名使用了驼峰命名法，函数名中的每一个逻辑断点都有一个大写字母来标记。第二个函数名使用了下划线法，函数名中的每一个逻辑断点都有一个下划线来标记。

驼峰命名法近年来越来越流行了，在许多新的函数库和Microsoft
Windows这样的环境中，它使用得当相多。另一方面，下划线法是C出现后开始流行起来的，在许多旧的程序和UNIX这样的环境中，它的使用非常普遍。

(2)匈牙利命名法。广泛应用于象Microsoft Windows这样的环境中。Windows 编程中用到的变量(还包括宏)的命名规则为匈牙利命名法，这种命名技术是由一位能干的
Microsoft 程序员查尔斯-西蒙尼(Charles Simonyi) 提出的。

匈牙利命名法通过在变量名前面加上相应的小写字母的符号标识作为前缀，标识出变量的作用域、类型等。这些符号可以多个同时使用，顺序是先m_(
成员变量)、再指针、再简单数据类型、再其它。这样做的好处在于能增加程序的可读性，便于对程序的理解和维护。

例如：m_lpszStr, 表示指向一个以0字符结尾的字符串的长指针成员变量。
匈牙利命名法关键是：标识符的名字以一个或者多个小写字母开头作为前缀；前缀之后的是首字母大写的一个单词或多个单词组合，该单词要指明变量的用途。

(3)帕斯卡(pascal)命名法。与驼峰命名法类似，二者的区别在于：驼峰命名法是首字母小写，而帕斯卡命名法是首字母大写，如：
DisplayInfo();
string UserName;

二者都是采用了帕斯卡命名法。

(4)
三种命名规则的小结：MyData就是一个帕斯卡命名的示例；myData是一个驼峰命名法,它第一个单词的第一个字母小写,后面的单词首字母大写,看起来像一个骆驼；iMyData是一个匈牙利命名法,它的小写的i说明了它的型态，后面的和帕斯卡命名相同，指示了该变量的用途。

## 1.3命名的基本原则

(1)
标识符的命名要清晰、明了，有明确含义，同时使用完整的单词或大家基本可以理解的缩写，避免使人产生误解——尽量采用采用英文单词或全部中文全拼表示，若出现英文单词和中文混合定义时，使用连字符“_
”将英文与中文割开。较短的单词可通过去掉“元音”形成缩写；较长的单词可取单词的头几个字母形成缩写；一些单词有大家公认的缩写。例如：temp->
tmp、flag->flg、statistic->stat、increment->inc、message->msg等缩写能够被大家基本认可。

(2)命名中若使用特殊约定或缩写，则要有注释说明。应该在源文件的开始之处，对文件中所使用的缩写或约定，特别是特殊的缩写，进行必要的注释说明。

(3)
自己特有的命名风格，要自始至终保持一致，不可来回变化。个人的命名风格，在符合所在项目组或产品组的命名规则的前提下，才可使用。(
即命名规则中没有规定到的地方才可有个人命名风格)。

(4)对于变量命名，禁止取单个字符(如i 、j 、k... )，建议除了要有具体含义外，还能表明其变量类型、数据类型等，但i 、j 、k
作局部循环变量是允许的。变量，尤其是局部变量，如果用单个字符表示，很容易敲错(如i写成j)，而编译时又检查不出来，有可能为了这个小小的错误而花费大量的查错时间。

(5)除非必要，不要用数字或较奇怪的字符来定义标识符。

(6)命名规范必须与所使用的系统风格保持一致，并在同一项目中统一。

(7)在同一软件产品内，应规划好接口部分标识符(变量、结构、函数及常量)
的命名，防止编译、链接时产生冲突。对接口部分的标识符应该有更严格限制，防止冲突。如可规定接口部分的变量与常量之前加上“模块”标识等。

(8)用正确的反义词组命名具有互斥意义的变量或相反动作的函数等。

下面是一些在软件中常用的反义词组。
add / remove begin / end create / destroy
insert / delete first / last g et / release
increment / decrement put / get
add / delete lock / unlock open / close
min / max old / new start / stop
next / previous source / target show / hide
send / receive source / destination
cut / paste up / down

示例：
int min_sum;
int max_sum;
int add_user( BYTE *user_name );
int delete_user( BYTE *user_name );

(9)除了编译开关/ 头文件等特殊应用，应避免使用_EXAMPLE_TEST_ 之类以下划线开始和结尾的定义。

## 1.4变量名的命名规则

(1)变量的命名规则要求用“匈牙利法则”。
即开头字母用变量的类型，其余部分用变量的英文意思、英文的缩写、中文全拼或中文全拼的缩写,要求单词的第一个字母应大写。
即： 变量名=变量类型+变量的英文意思(或英文缩写、中文全拼、中文全拼缩写)
对非通用的变量，在定义时加入注释说明，变量定义尽量可能放在函数的开始处。
见下表：
bool 用b开头 bFlg
int 用i开头 iCount
short int 用n开头 nStepCount
long int 用l开头 lSum
char 用c开头 cCount
unsigned char 用by开头
float 用f开头 fAvg
double 用d开头 dDeta
unsigned int(WORD) 用w开头 wCount
unsigned long int(DWORD) 用dw开头 dwBroad
字符串 用s开头 sFileName
用0结尾的字符串 用sz开头 szFileName

(2)指针变量命名的基本原则为：
对一重指针变量的基本原则为：“p”+变量类型前缀+命名，如一个float*
型应该表示为pfStat。对二重指针变量的基本规则为：“pp”+变量类型前缀+命名。对三重指针变量的基本规则为：“ppp”+变量类型前缀+命名。

(3)全局变量用g_开头,如一个全局的长型变量定义为g_lFailCount。即：变量名=g_+变量类型+变量的英文意思(或缩写)
。此规则还可避免局部变量和全局变量同名而引起的问题。

(4)静态变量用s_开头,如一个静态的指针变量定义为s_plPerv_Inst。即： 变量名=s_+变量类型+变量的英文意思(或缩写)

(5)对枚举类型(enum)中的变量，要求用枚举变量或其缩写做前缀。并且要求用大写。如：
enum cmEMDAYS
{
EMDAYS_MONDAY;
EMDAYS_TUESDAY;
……
};

(6)对struct、union变量的命名要求定义的类型用大写。并要加上前缀，其内部变量的命名规则与变量命名规则一致。

结构一般用S开头，如：
struct ScmNPoint
{
int nX;//点的X位置
int nY; //点的Y位置
};

联合体一般用U开头，如:
union UcmLPoint
{
LONG lX;
LONG lY;
}

(7)对常量(包括错误的编码)
命名，要求常量名用大写，常量名用英文表达其意思。当需要由多个单词表示时，单词与单词之间必须采用连字符“_”连接。
如：#define CM_FILE_NOT_FOUND CMMAKEHR(0X20B) 其中CM表示类别。

(8)对const 的变量要求在变量的命名规则前加入c_。即：c_+变量命名规则；示例：const char* c_szFileName;

## 1.5函数的命名规范

(1)函数的命名应该尽量用英文(或英文缩写、中文全拼、中文全拼缩写)
表达出函数完成的功能——函数名应准确描述函数的功能。遵循动宾结构的命名法则，函数名中动词在前,并在命名前加入函数的前缀，函数名的长度不得少于8个字母。函数名首字大写，若包含有两个单词的每个单词首字母大写。如果是OOP
方法，可以只有动词(名词是对象本身)。示例：
LONG GetDeviceCount(……);
void print_record( unsigned int rec_ind ) ;
int input_record( void ) ;
unsigned char get_current_color( void ) ;

(2)避免使用无意义或含义不清的动词为函数命名。如使用process、handle等为函数命名，因为这些动词并没有说明要具体做什么。

(3)必须使用函数原型声明。函数原型声明包括：引用外来函数及内部函数，外部引用必须在右侧注明函数来源：
模块名及文件名；内部函数，只要注释其定义文件名——和调用者在同一文件中(简单程序)时不需要注释。
应确保每个函数声明中的参数的名称、类型和定义中的名称、类型一致。

## 1.6函数参数命名规范

(1)参数名称的命名参照变量命名规范。

(2)为了提高程序的运行效率，减少参数占用的堆栈，传递大结构的参数，一律采用指针或引用方式传递。

(3)为了便于其他程序员识别某个指针参数是入口参数还是出口参数，同时便于编译器检查错误，应该在入口参数前加入const标志。  
如：……cmCopyString(const CHAR * c_szSource, CHAR * szDest)

## 1.7文件名(包括动态库、组件、控件、工程文件等)的命名规范

文件名的命名要求表达出文件的内容，要求文件名的长度不得少于5个字母，严禁使用象file1,myfile之类的文件名。

### 1.7.1文件命名

文件名后缀：

```text

# C语言不纠结
file.h & file.c

# C++ Group.1(注意C是大写)
file.h & file.C

# C++ Group.2
file.hh & file.cc

# C++ Group.3
file.hpp & file.cpp

# C++ Group.4
file.hxx & file.cxx

```

> tip.1：c语言没有选择，以下仅讨论c++；
> tip.2：各组合可以混搭，比如常见的file.cpp搭配file.h和Google风格的file.cc搭配file.h；
> tip.3：强迫症可以选择不混搭的各组，这样看起来有对称感；
> tip.4：不要选择第1组大写C的后缀，特别是在Windows这样不区分大小写的操作系统上；
> tip.5：一些后缀名可能不被某些较老的编译器或IDE所默认支持，例如vs2005默认没有扩展.hh后缀；
> tip.6：如果需要跨平台，推荐选择第3组，至少boost是这么选的；

文件名命名：

```text
# Teddy项目UserLog文件为例：

# Group.1
UserLog.c & TedUserLog.c

# Group.2
userlog.c & teduserlog.c

# Group.3
userlog.c & ted_userlog.c

# Group.4
user_log.c & ted_user_log.c

# Group.5
user-log.c & ted-user-log.c
```

> tip.1：如果需要将源码直接发布，可以使用项目名做前缀，防止链接时文件名冲突(
> msvc好像能自动重命名冲突的.obj文件，但是跨平台程序不能依赖这个特性)；
> tip.2：各组文件名风格都没有明显的缺点，但要注意在区分大小写的系统上UserLog.c和userlog.c是两个文件；

### 1.7.2类型命名

```c
/*
** 基本数据类型的重定义，小写比首字母大写更有利于延长Shift寿命，
** 但也更容易产生命名冲突。
*/
typedef unsigned char byte;
typedef unsigned char byte_t;
typedef unsigned char Byte;
typedef unsigned char Byte_t;

/*
** 类与结构体常见的风格是采用PascalCase，不推荐使用camelCase
** 这种怪异的风格。
*/
class HashTable {
...
}
class hash_table {
...
}
struct FileInfo {
...
}
struct file_info {
...
}

/* C语言常见到的风格还有结构体名称加'_t'后缀 */
struct fileinfo_t {
...
}
struct FileInfo_t {
...
}

/* 枚举命名常见PascalCase风格 */
enum FileFlags {
...
}
enum file_flags {
...
}

```

> tip.1：c语言没有命名空间，为防止命名冲突，常见做法是将项目名或其缩写作为类型名称前缀；
> tip.2：类，结构体，枚举的命名风格尽量保持一致；

### 1.7.3命名空间命名

```c
/* 一般使用项目名称，风格看喜好。 */
namespace my_project {
...
}
namespace MyProject {
...
}
```

> tip.1：确保命名空间不会和常用的库冲突；

### 1.7.4函数和变量命名

```c
/*
** 在函数和变量命名风格上PascalCase，camelCase，
** snake_case三足鼎立，选择凭喜好。
*/
void FunctionName(void) {
...
}
void functionName(void) {
...
}
void function_name(void) {
...
}

long VarName;
long varName;
long var_name;

/*
** tip.1：snake_case在名称比较长时可读性较好；
*/
long variable_names_in_snake_case;
long VariableNamesInPascalCase;
long variableNamesInCamelCase;

/*
** tip.2：PascalCase和camelCase在函数中的区分度较好，
** 在快速扫描代码逻辑的时候不易被其它符号所干扰。
*/
long FabonacciFunction(long rabbitNums)
{
if (rabbitNums < 2) {
return rabbitNums;
}
long resultOne = FabonacciFunction(rabbitNums - 1);
long resultTwo = FabonacciFunction(rabbitNums - 2);
return resultOne + resultTwo;
}

long fabonacci_function(long rabbit_nums)
{
if (rabbit_nums < 2) {
return rabbit_nums;
}
long result_one = fabonacci_function(rabbit_nums - 1);
long result_two = fabonacci_function(rabbit_nums - 2);
return result_one + result_two;
}
```

> tip.3：如果类需要兼容标准库迭代器或是要支持range for，begin()和end()函数会破坏PascalCase风格的一致性；

### 1.7.5类成员变量和全局变量命名

```c
/*
** 类成员变量和全局变量的命名风格和局部变量的命名风格
** 并没有更多的区别。唯一的问题是，是否要加前缀或后缀
** 以方便和局部变量区分开来。
*/
class UserInfo {
...
private:
std::string user_name_; /* Google style */
std::string m_userName; /* Hungarian notation */
/* 不推荐前缀'_'的风格，可能会和标准库命名冲突 */
};

/* 全局变量要少用，推荐加前缀用于区分 */
extern "C" long g_commonCount;
```

> tip.1：在有IDE提示时，前缀"m_"的类成员变量能够很快被找到，如果不喜欢这种风格，"this->"同样也很便利；

### 1.7.6常量和枚举值命名

```c
/*
** 常量和枚举值的命名风格建议和局部变量的命名风格区分开，
** 常见的有全字母大写加'_'的风格，PascalCase风格，以及
** Google加'k'前缀的风格。
*/
static const int DAYS_IN_WEEK = 7;
static const int kDaysInWeek = 7;

enum FileOpenMode {
ReadOnly, WriteOnly, ReadWrite
};

enum FileOpenMode {
READ_ONLY, WRITE_ONLY, READ_WRITE
};
```

> tip.1：如果可以使用c++11特性，推荐enum class，否则可以在有歧义的枚举值中重复枚举类型的名字；

### 1.7.6宏命名

```text
/* 宏命名推荐使用全字母大写加'_'分隔的风格 */
#define OS_UNIX
#define OS_LINUX
#define OS_WINNT

/* 除非你想用条件编译将某些功能变为可选项 */
#ifdef USE_TCMALLOC
#define my_malloc tcmalloc
#else
#define my_malloc malloc
#endif
```

> tip.1：能用常量替代宏的地方尽量使用常量吧； 




