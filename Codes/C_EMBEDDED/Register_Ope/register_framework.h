/**
 * @file    register_framework.h
 * @brief   模拟简易MCU寄存器读写框架 头文件
 * @details 提供寄存器地址映射、通用位操作宏、外设寄存器定义、全位宽寄存器操作函数声明
 *          完整兼容 8bit / 16bit / 32bit 寄存器读写、位操作、掩码配置，贴合真实MCU硬件
 * @author  框架模拟工程
 * @date    2026
 */
#ifndef REGISTER_FRAMEWORK_H
#define REGISTER_FRAMEWORK_H

// 引入标准固定位宽整型类型，保证跨编译器、跨平台类型一致
#include <stdint.h>

/*****************************************************************************
 * 通用寄存器位操作宏（嵌入式标准通用写法）
 * 功能：仅操作指定bit，不影响寄存器其余位
 *****************************************************************************/
/**
 * @brief  寄存器指定位置1
 * @param  REG: 寄存器变量/寄存器宏
 * @param  BIT: 目标操作位号(从0开始)
 */
#define BIT_SET(REG, BIT)      ((REG) |=  (1U << (BIT)))

/**
 * @brief  寄存器指定位清零
 * @param  REG: 寄存器变量/寄存器宏
 * @param  BIT: 目标操作位号(从0开始)
 */
#define BIT_CLR(REG, BIT)      ((REG) &= ~(1U << (BIT)))

/**
 * @brief  寄存器指定位翻转
 * @param  REG: 寄存器变量/寄存器宏
 * @param  BIT: 目标操作位号(从0开始)
 */
// toggle:切换
#define BIT_TOGGLE(REG, BIT)   ((REG) ^=  (1U << (BIT)))

/**
 * @brief  读取寄存器指定位状态
 * @param  REG: 寄存器变量/寄存器宏
 * @param  BIT: 目标读取位号(从0开始)
 * @retval 0: 低电平  1: 高电平
 */
#define BIT_GET(REG, BIT)      (((REG) >> (BIT)) & 0x01U)

/**
 * @brief  生成连续bit掩码，用于寄存器区域批量配置
 * @param  START: 掩码起始位
 * @param  LEN:   掩码连续位数
 * @note   示例：REG_MASK(0,4) 生成 0x0000000F（低4位掩码）
 */
#define REG_MASK(START, LEN)   (((1U << (LEN)) - 1U) << (START))

/*****************************************************************************
 * 寄存器里的外设虚拟基地址定义（模拟MCU片上寄存器里的外设总线地址）
 *****************************************************************************/
// 使用数组模拟GPIO外设模块虚拟基地址
#define GPIO_MEM_SIZE_32BIT 16
extern volatile uint32_t gpio_base_addr_32bit[GPIO_MEM_SIZE_32BIT];
#define GPIO_MEM_SIZE_16BIT 16
extern volatile uint16_t gpio_base_addr_16bit[GPIO_MEM_SIZE_16BIT];
#define GPIO_MEM_SIZE_8BIT 16
extern volatile uint8_t gpio_base_addr_8bit[GPIO_MEM_SIZE_8BIT];
// 使用数组模拟UART外设模块虚拟基地址
#define UART_MEM_SIZE_32BIT 16
extern volatile uint32_t uart_base_addr_32bit[UART_MEM_SIZE_32BIT];

/*****************************************************************************
 * GPIO 寄存器偏移地址
 *****************************************************************************/
#define GPIO_CR_OFFSET    0x00U   // GPIO32位控制寄存器偏移地址
#define GPIO_DR_OFFSET    0x04U   // GPIO32位数据寄存器偏移地址
#define GPIO_RST_OFFSET   0x08U   // GPIO32位复位寄存器偏移地址
#define GPIO_8BIT_OFFSET  0x00U   // GPIO 8位模拟寄存器偏移地址
#define GPIO_16BIT_OFFSET 0x00U  // GPIO 16位模拟寄存器偏移地址

/*****************************************************************************
 * UART 寄存器偏移地址
 *****************************************************************************/
#define UART_BAUD_OFFSET  0x00U    // UART32位波特率配置寄存器偏移地址
#define UART_CTRL_OFFSET 0x04U   // UART32位功能控制寄存器偏移地址

/*****************************************************************************
 * 寄存器地址映射（核心：模拟MCU内存映射寄存器）
 * volatile：禁止编译器优化，强制每次读写访问真实内存硬件地址
 * 原理：32位虚拟地址 + 类型限定，仅改变访问字节数，不改变地址本身，无内存溢出风险
 *****************************************************************************/
// 32位寄存器定义
#define GPIO_CR       gpio_base_addr_32bit[GPIO_CR_OFFSET]
#define GPIO_DR       gpio_base_addr_32bit[GPIO_DR_OFFSET]
#define GPIO_RST      gpio_base_addr_32bit[GPIO_RST_OFFSET]
#define UART_BAUD     uart_base_addr_32bit[UART_BAUD_OFFSET]
#define UART_CTRL     uart_base_addr_32bit[UART_CTRL_OFFSET]

// 8位/16位拓展寄存器定义（模拟MCU窄位宽寄存器）
#define GPIO_REG_8BIT   gpio_base_addr_8bit[GPIO_8BIT_OFFSET]
#define GPIO_REG_16BIT  gpio_base_addr_16bit[GPIO_16BIT_OFFSET]

/*****************************************************************************
 * GPIO 引脚位号定义
 *****************************************************************************/
#define GPIO_PIN_0      0U
#define GPIO_PIN_1      1U
#define GPIO_PIN_2      2U
#define GPIO_PIN_3      3U

/*****************************************************************************
 * UART 控制寄存器位定义
 *****************************************************************************/
#define UART_EN_BIT     0U    // UART模块总使能位
#define UART_TX_EN_BIT  1U    // UART发送功能使能位
#define UART_RX_EN_BIT  2U    // UART接收功能使能位

/*****************************************************************************
 * 通用寄存器操作函数声明（全位宽完美适配）
 * 支持：8位 / 16位 / 32位 所有寄存器读写、位操作、复位、掩码配置
 *****************************************************************************/
// 8位寄存器基础操作
void Reg_Write8(volatile uint8_t *reg, uint8_t val);
uint8_t Reg_Read8(volatile uint8_t *reg);
void Reg_BitSet8(volatile uint8_t *reg, uint8_t bit);
void Reg_BitClr8(volatile uint8_t *reg, uint8_t bit);
void Reg_BitToggle8(volatile uint8_t *reg, uint8_t bit);
uint8_t Reg_BitGet8(volatile uint8_t *reg, uint8_t bit);

// 16位寄存器基础操作
void Reg_Write16(volatile uint16_t *reg, uint16_t val);
uint16_t Reg_Read16(volatile uint16_t *reg);
void Reg_BitSet16(volatile uint16_t *reg, uint8_t bit);
void Reg_BitClr16(volatile uint16_t *reg, uint8_t bit);
void Reg_BitToggle16(volatile uint16_t *reg, uint8_t bit);
uint8_t Reg_BitGet16(volatile uint16_t *reg, uint8_t bit);

// 32位寄存器基础操作
void Reg_Write32(volatile uint32_t *reg, uint32_t val);
uint32_t Reg_Read32(volatile uint32_t *reg);
void Reg_BitSet32(volatile uint32_t *reg, uint8_t bit);
void Reg_BitClr32(volatile uint32_t *reg, uint8_t bit);
void Reg_BitToggle32(volatile uint32_t *reg, uint8_t bit);
uint8_t Reg_BitGet32(volatile uint32_t *reg, uint8_t bit);

// 高级通用配置函数（适配所有位宽寄存器）
void Reg_MaskConfig(volatile uint32_t *reg, uint32_t mask, uint32_t val);
void Reg_Reset(volatile uint32_t *reg, uint32_t rst_val);

#endif // REGISTER_FRAMEWORK_H