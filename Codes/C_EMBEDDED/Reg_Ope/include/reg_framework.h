#ifndef REG_FRAMEWORK_H
#define REG_FRAMEWORK_H

#include <stdint.h>

// 定义声明一个全局数组(用来模拟寄存器)，注意在头文件中不能初始化，需要在对应的.c文件中初始化，也就是reg_framework.c
#define REG_MEM_SIZE 16
extern volatile uint8_t reg_mem[REG_MEM_SIZE];

// 设置模拟寄存器的偏移量
#define GPIO_8BIT_OFFSET 0x03U
#define GPIO_REG_8BIT (reg_mem[GPIO_8BIT_OFFSET])

// 标准嵌入式位操作宏
#define BIT_SET(reg,bit)    ((reg) |= (1U << (bit)))
#define BIT_CLR(reg,bit)    ((reg) &= ~(1U << (bit)))


// 函数声明
void RegWrite8(volatile uint8_t *reg,uint8_t val);
uint8_t RegRead8(volatile uint8_t *reg);

void Reg_BitSet8(volatile uint8_t *reg,uint8_t bit);
void Reg_BitClr8(volatile uint8_t *reg,uint8_t bit);

#endif





// 在PC中，地址0x40001000U不可以访问（无权限，触发操作系统内存保护，造成段错误），为非法地址，在MUC中可以访问，在PC中模拟单片机的寄存器需要使用用全局数组模拟寄存器内存空间
/* #define GPIO_BASE_ADDR      0x40001000U
#define GPIO_8BIT_OFFSET    0x03U
// 分开定义：指针用于函数传参，解引用用于直接读写
#define GPIO_REG_8BIT_PTR   ((volatile uint8_t *)(GPIO_BASE_ADDR + GPIO_8BIT_OFFSET))
#define GPIO_REG_8BIT       (*GPIO_REG_8BIT_PTR) */
