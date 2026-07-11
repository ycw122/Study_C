#include <stdio.h>

// 使用共用体的原理
int judgeWithStruct()
{
    union Box
    {
        int a;
        char c;
    } b;
    b.a = 1;
    return b.c;
}

// 使用内存溢出的原理
int judgeWithPointer()
{
    int a = 1;
    // 等同于return (char) a;
    int *p = &a;
    return *(char *)p;
}

int main()
{
    if (judgeWithPointer() == 1)
    {
        printf("store in small endian!\n");
    }
    else
    {
        printf("store in big endian!\n");
    }
    
    return 0;
}