#include <stdio.h>

/* 打印无符号整数的二进制表示 */
void printBinary(unsigned int n, int bitsize) {//定义一个函数 printBinary，接受两个参数：n（要打印的无符号整数）和 bits（位数）。函数无返回值。
    printf("0b");   // 打印二进制前缀 "0b"  
    for(int i = bitsize-1; i >= 0; i--) {  // 从最高位到最低位循环，打印每一位的值
        printf("%d", (n >> i) & 1); // 通过右移操作将 n 的第 i(从低往高数) 位移动到最低位，并使用按位与操作获取该位的值（0 或 1），然后打印出来
    }
    printf("\n");
}

/* 主函数 */
int main(void){
    /* 定义位域结构体 */
    struct BitFieldOpreration
    {
        unsigned int field1:1; // 占用1 bit
        unsigned int field2:1;
        unsigned int field3:2; // 占用2 bits
    };
    struct BitFieldOpreration bitField;
    bitField.field1=0;// 给位域成员赋值
    bitField.field2=1;
    bitField.field3=3;
    printf("field1: %u\n", bitField.field1);
    printf("field2: %u\n", bitField.field2);
    printf("field3: %u\n", bitField.field3);
    printf("field3 in binary: ");
    printBinary(bitField.field3, 3);// 打印 field3 的二进制表示，使用 printBinary 函数，传入 field3 的值和位数（3 位，因为 field3 占用 2 bits）
    printf("Size of BitFieldOpreration: %dbytes\n", sizeof(bitField)); // 打印 BitFieldOpreration 结构体的大小，使用 sizeof 运算符获取 bitField 变量的大小，并打印出来
    return 0;
}
