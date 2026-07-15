#include "reg_framework.h"
#include <stdlib.h>
#include <stdio.h>

volatile uint8_t reg_mem[REG_MEM_SIZE] = {0}; //.h文件声明数组,对应的.c文件初始化数组。

void wrireValToReg_loop()
{
    uint8_t val;
    for (size_t i = 1; i < REG_MEM_SIZE+1; i++)
    {
        
        printf("please input two hexadecimal numbers which is %zu/6 in 8bit register:\n", i);
        if (scanf("%hhx", &val)==1)
        {
            RegWrite8(&reg_mem[GPIO_8BIT_OFFSET+i],val);
            printf("you have successfully input two hexadecimal numbers!\n");
        }
        else
        {
            printf("please inputs two correct hexadecimal numbers!\n");
            break;
        }
        
    }
    return;
}

void readValFromRag_loop(){
    uint8_t val;
    for (size_t i = 1; i < REG_MEM_SIZE+1; i++)
    {
        val=RegRead8(&reg_mem[GPIO_8BIT_OFFSET+i]);
        printf("the No. %zu value in 8bit register is %hhx\n",i,val);
    }
    return;
}



void RegWrite8(volatile uint8_t *reg, uint8_t val)
{
    *reg = val;
}

uint8_t RegRead8(volatile uint8_t *reg)
{
    return *reg;
}

void Reg_BitSet8(volatile uint8_t *reg, uint8_t bit)
{
    BIT_SET(*reg, bit);
}

void Reg_BitClr8(volatile uint8_t *reg, uint8_t bit)
{
    BIT_CLR(*reg, bit);
}

void set_bit1(){
    unsigned int a,b;
    printf("please input a offset which address you want to set(1-6):\n");
    scanf("%u",&a);
    printf("please input a bit number that address you want to set(1-8):\n");
    scanf("%u",&b);
    Reg_BitSet8(&reg_mem[a-1],b-1);
    printf("reg_mem[%d] is %hhx\n",a-1,reg_mem[a-1]);
    return;
}