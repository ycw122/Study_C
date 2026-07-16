#include <stdio.h>
#include "reg_framework.h"

int main(void)
{
    /* uint8_t a;
    printf("请输入一个两位的十六进制数存到8位寄存器中\n");
    
    // 修复1：scanf必须传地址 &a,%hhx:八位的十六进制占位符，也就是可以输入两位十六进制数。%hx:十六位的十六进制，也就是可以输入四位的十六进制数
    scanf("%hhx", &a);  
    
    // 写入8位寄存器（取地址传指针，匹配函数形参）
    RegWrite8(&GPIO_REG_8BIT, a);
    
    // 修复2：读取必须传 寄存器地址指针
    uint8_t val = RegRead8(&GPIO_REG_8BIT);
    printf("寄存器中的数是%02x\n", val); */

    wrireValToReg_loop();
    readValFromRag_loop();
    set_bit1();
    set_bit0();
    return 0;
}
