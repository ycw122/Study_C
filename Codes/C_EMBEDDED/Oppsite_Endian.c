#include <stdio.h>

int oppesite_endian(int n){
    union Temp
    {
        int i;
        char c[4];        
    }u;
    u.i=n;
    // 这里c[0]保存i的第0～7位的数值，而不是占据0～7位，本身并不带偏移，偏移是把数据给CPU做的一种运算，而不是直接在内存移动数字。
    return(u.c[0]<<24|u.c[1]<<16|u.c[2]<<8|u.c[3]);
    
}

int main(){
    int a,b;
    printf("please a number in decimal:");
    fflush(stdout);
    scanf("%d",&a);
    printf("%d in hexadecimal is 0x%x\n",a,a);
    printf("now enter any key to opposite the number\n");
    getchar();
    b = oppesite_endian(a);
    printf("the transformed number is 0x%x in hexadecimal,%d in decimal\n"  ,b,b);
    return 0;
}


// https://blog.csdn.net/d704791892/article/details/141787687