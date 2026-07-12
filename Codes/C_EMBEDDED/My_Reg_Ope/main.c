#include "reg_framework.h"

int main(void)
{
    uint8_t a;
    printf("请输入一个两位的十六进制数存到8位寄存器中\n");
    
    // 修复1：scanf必须传地址 &a
    scanf("%hhx", &a);  
    
    // 写入8位寄存器（取地址传指针，匹配函数形参）
    RegWrite8(&GPIO_REG_8BIT, a);
    
    // 修复2：读取必须传 寄存器地址指针
    uint8_t val = RegRead8(&GPIO_REG_8BIT);
    printf("寄存器中的数是%02x\n", val);

    return 0;
}
