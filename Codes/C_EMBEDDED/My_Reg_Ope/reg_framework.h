#ifndef REG_FRAMEWORK_H
#define REG_FRAMEWORK_H

#include <stdint.h>

// 标准嵌入式位操作宏
#define BIT_SET(reg,bit)    ((reg) |= (1U << (bit)))
#define BIT_CLR(reg,bit)    ((reg) &amp;= ~(1U << (bit)))

#define GPIO_BASE_ADDR      0x40001000U
#define GPIO_8BIT_OFFSET    0x03U

// 分开定义：指针用于函数传参，解引用用于直接读写
#define GPIO_REG_8BIT_PTR   ((volatile uint8_t *)(GPIO_BASE_ADDR + GPIO_8BIT_OFFSET))
#define GPIO_REG_8BIT       (*GPIO_REG_8BIT_PTR)

// 函数声明
void RegWrite8(volatile uint8_t *reg,uint8_t val);
uint8_t RegRead8(volatile uint8_t *reg);

void Reg_BitSet8(volatile uint8_t *reg,uint8_t bit);
void Reg_BitClr8(volatile uint8_t *reg,uint8_t bit);

#endif
