#include <stdio.h>
#include "endian.h"

int oppesite_endian_struct(int n)
{
    union Temp
    {
        int i;
        char c[4];
    } u;
    u.i = n;
    // 这里c[0]保存i的第0～7位的数值，而不是占据0～7位，本身并不带偏移，偏移是把数据给CPU做的一种运算，而不是直接在内存移动数字。
    return (u.c[0] << 24 | u.c[1] << 16 | u.c[2] << 8 | u.c[3]);
}

int opposite_endian_bitoperate(int n)
{
    // result用来存放反转后的结果，temp用来存放临时变量
    int result = 0, temp;
    int size = sizeof(n);
    // 原理就是循环 通过左移8位将result的尾部字节空出来，位操作取出n中目的字节，循环按照低字节到高字节的顺序插入末尾
    for (size_t i = 0; i < size; i++)
    {
        result <<= 8;
        // 得到每次循环需要的目的字节：先0xff<<(i*8)定位到目的字节，n&(0xff<<(i*8))得到目的字节的值，最后>>(i*8)将目的字节防到末尾，
        temp = (n & (0xff << (i * 8))) >> (i * 8);
        // 将目的字节防到结果末尾
        result |= temp;
    }
    return result;
}

int main()
{
    int a, b;
    printf("please enter a number in decimal:");
    fflush(stdout);
    scanf("%d", &a);
    printf("%d in hexadecimal is 0x%x\n", a, a);
    b = opposite_endian_bitoperate(a);
    printf("the transformed number is 0x%x in hexadecimal,%d in decimal\n", b, b);
    return 0;
}

// https://blog.csdn.net/d704791892/article/details/141787687