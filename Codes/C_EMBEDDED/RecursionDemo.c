#include <stdio.h>

int multiRec(int a)
{
    if (a > 0)
    {
        return a * multiRec(a - 1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    printf("4的前N项积是%d\n", multiRec(4));
    return 0;
}