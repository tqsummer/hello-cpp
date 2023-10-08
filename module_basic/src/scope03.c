#include <stdio.h>

extern int __scope_v;

extern int __scope_func();

extern int __scope_func2();

int scope03_num = 10;


void scope03_func2() {
    /**
     * 以上声明的__scope_v变量，是在scope04.c中定义的全局变量。
     * 1.scope04.c中定义的__scope_v静态变量不能对外暴露，只能在定义的当前文件(scope04.c本文件)中使用。
     * 2.所以这个打印的是scope04.c中__scope_v变量的值：7
     */
    printf("call scope03.c scope03_func2 : __scope_v : %d\n", __scope_v);

    /**
     * 以上声明的__scope_func()函数，是在scope04.c中定义的全局函数。
     * 1.scope04.c中定义的__scope_func()静态函数不能对外暴露，只能在定义的当前文件(scope04.c本文件)中调用。
     * 2.scope04.c中定义了__scope_v的全局变量，又在__scope_func()函数中定义了同名局部变量__scope_v。根据就近原则，优先使用作用域内的局部变量。
     * 3.所以这个__scope_func()返回的是局部变量__scope_v的值：17
     */
    printf("call scope03.c scope03_func2 : __scope_func() : %d\n", __scope_func());

    /**
     * 以上声明的__scope_func2()函数，是在scope05.c中定义的全局函数。
     * 1.scope05.c中定义了__scope_v的静态全局变量
     * 2.scope05.c中定义了__scope_func()的静态函数，函数返回静态全局变量__scope_v
     * 3.__scope_func2()函数，调用当前文件的__scope_func()的静态函数，并将这个静态函数作为当前函数的返回值。
     * 所以这个__scope_func2()函数返回的是当前文件__scope_func()的静态函数的返回值，也就是当前scope05.c中定义了__scope_v的静态全局变量值：27
     */
    printf("call scope03.c scope03_func2 : __scope_func2() : %d\n", __scope_func2());
}

void scope03_func() {
    /**
     * 同名变量
     * 值为10的全局变量scope03_num的这个变量作用于全局。
     * 值为30的局部变量scope03_num的这个变量作用于整个函数。
     * 值为40的局部变量scope03_num的这个变量作用于函数内局部的｛｝。
     *
     * 就近原则，优先使用的是局部同名变量。
     *
     */


    /**
     * 因为此时还没有同名的局部变量定义
     * 所以以下printf打印的是值为10的全局变量scope03_num
     */
    printf("call scope03.c scope03_func ,global, scope03_num : %d\n", scope03_num);
    int scope03_num = 30;
    {
        int scope03_num = 40;
        /**
         * 就近原则，优先使用的是局部同名变量。
         * 最近的是值为40的变量scope03_num
         * 所以printf打印的是值为40的局部变量scope03_num，
         */
        printf("call scope03.c scope03_func ,{...}, scope03_num : %d\n", scope03_num);
    }
    /**
     * 值为30的变量scope03_num和值为40的变量scope03_num同为局部变量
     * 但值为40的变量scope03_num不在作用域内
     * printf打印的是值为30的局部变量scope03_num，
     *
     */
    printf("call scope03.c scope03_func ,func{...}, scope03_num : %d\n", scope03_num);

    scope03_func2();
}



