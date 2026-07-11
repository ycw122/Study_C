#include <stdio.h>
#include <stdlib.h>

/*
注意：关于函数在函数指针里的用法：
    当函数当作实参传递给函数指针时，函数名后不需要加(),因为函数名就是函数的入口地址，需要传入的就是函数的入口地址；
    当调用函数时，函数名后需要加上(),如果函数定义时()内有参数还需要加上参数，否则调用失败u。
*/

/*
// 函数指针的另外一种用法，可以先定义函数指针，再带入函数
int (*p)(void)；
void populate_arrary(int *arrary, size_t arrary_size,p){}
*/

void populate_arrary(int *arrary, size_t arrary_size, int (*p)(void))
{
    // size_t是一个无符号整数的C类型， 它一般是sizeof操作符返回的结果类型。
    for (size_t i = 0; i < arrary_size; i++)
    {
        // 注意这里调用函数指针p时，需要加上功能(),p()是正确形式，p为错误调用形式
        arrary[i] = p();
    }
}

int getRanValue(void)
{
    return rand();
}

int main()
{
    int a[10];
    // 将函数 getRanValue当作实参传给函数指针时，不需要在函数名后加(),只需传入函数名，代表函数的入口地址。
    populate_arrary(a, 10, getRanValue);
    for (size_t i = 0; i < 10; i++)
    {
        printf("arrary[%zu] = %d\n", i, a[i]);
    }

    return 0;
}