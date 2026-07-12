/**
 * @file    register_framework.c
 * @brief   简易MCU寄存器读写框架 功能实现文件
 * @details 完整实现 8/16/32位寄存器专属读写、位操作、掩码配置、寄存器复位功能
 *          分位宽独立接口，无类型强制转换BUG，完全贴合嵌入式真实寄存器操作逻辑
 *          接口标准化、注释统一规范，可直接商用移植
 * @author  框架模拟工程
 * @date    2026
 */
#include "register_framework.h"

/*****************************************************************************
 * 8位寄存器专属操作接口
 *****************************************************************************/
/**
 * @brief  Reg_Write8
 * @brief  8位寄存器整体写入数据
 * @param  reg: 目标8位寄存器地址指针
 * @param  val: 待写入的8位数据
 * @retval 无
 * @note   适用于MCU状态寄存器、短配置寄存器
 */
void Reg_Write8(volatile uint8_t *reg, uint8_t val)
{
    *reg = val;
}

/**
 * @brief  Reg_Read8
 * @brief  8位寄存器整体读取数据
 * @param  reg: 目标8位寄存器地址指针
 * @retval 寄存器当前8位数值
 * @note   实时读取硬件最新状态，无编译器缓存
 */
uint8_t Reg_Read8(volatile uint8_t *reg)
{
    return *reg;
}

/**
 * @brief  Reg_BitSet8
 * @brief  8位寄存器指定位置1
 * @param  reg: 目标8位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 * @note   仅置位目标bit，不影响其他位，适配8位窄寄存器
 */
void Reg_BitSet8(volatile uint8_t *reg, uint8_t bit)
{
    BIT_SET(*reg, bit);
}

/**
 * @brief  Reg_BitClr8
 * @brief  8位寄存器指定位清零
 * @param  reg: 目标8位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 * @note   仅清零目标bit，保留其余位配置
 */
void Reg_BitClr8(volatile uint8_t *reg, uint8_t bit)
{
    BIT_CLR(*reg, bit);
}

/**
 * @brief  Reg_BitToggle8
 * @brief  8位寄存器指定位电平翻转
 * @param  reg: 目标8位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 * @note   0变1、1变0，适用于状态切换场景
 */
void Reg_BitToggle8(volatile uint8_t *reg, uint8_t bit)
{
    BIT_TOGGLE(*reg, bit);
}

/**
 * @brief  Reg_BitGet8
 * @brief  读取8位寄存器指定位电平状态
 * @param  reg: 目标8位寄存器地址指针
 * @param  bit: 目标读取位号(0起始)
 * @retval 0: 低电平  1: 高电平
 */
uint8_t Reg_BitGet8(volatile uint8_t *reg, uint8_t bit)
{
    return BIT_GET(*reg, bit);
}

/*****************************************************************************
 * 16位寄存器专属操作接口
 *****************************************************************************/
/**
 * @brief  Reg_Write16
 * @brief  16位寄存器整体写入数据
 * @param  reg: 目标16位寄存器地址指针
 * @param  val: 待写入的16位数据
 * @retval 无
 * @note   适用于MCU分频值、中短配置参数寄存器
 */
void Reg_Write16(volatile uint16_t *reg, uint16_t val)
{
    *reg = val;
}

/**
 * @brief  Reg_Read16
 * @brief  16位寄存器整体读取数据
 * @param  reg: 目标16位寄存器地址指针
 * @retval 寄存器当前16位数值
 * @note   实时读取硬件最新状态
 */
uint16_t Reg_Read16(volatile uint16_t *reg)
{
    return *reg;
}

/**
 * @brief  Reg_BitSet16
 * @brief  16位寄存器指定位置1
 * @param  reg: 目标16位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 * @note   专属16位寄存器位操作，无类型转换隐患
 */
void Reg_BitSet16(volatile uint16_t *reg, uint8_t bit)
{
    BIT_SET(*reg, bit);
}

/**
 * @brief  Reg_BitClr16
 * @brief  16位寄存器指定位清零
 * @param  reg: 目标16位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 */
void Reg_BitClr16(volatile uint16_t *reg, uint8_t bit)
{
    BIT_CLR(*reg, bit);
}

/**
 * @brief  Reg_BitToggle16
 * @brief  16位寄存器指定位电平翻转
 * @param  reg: 目标16位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 */
void Reg_BitToggle16(volatile uint16_t *reg, uint8_t bit)
{
    BIT_TOGGLE(*reg, bit);
}

/**
 * @brief  Reg_BitGet16
 * @brief  读取16位寄存器指定位电平状态
 * @param  reg: 目标16位寄存器地址指针
 * @param  bit: 目标读取位号(0起始)
 * @retval 0: 低电平  1: 高电平
 */
uint8_t Reg_BitGet16(volatile uint16_t *reg, uint8_t bit)
{
    return BIT_GET(*reg, bit);
}

/*****************************************************************************
 * 32位寄存器专属操作接口
 *****************************************************************************/
/**
 * @brief  Reg_Write32
 * @brief  32位寄存器整体写入数据
 * @param  reg: 目标寄存器地址指针
 * @param  val: 待写入的32位数据
 * @retval 无
 * @note   直接覆盖寄存器全部数值，适合整寄存器初始化配置
 */
void Reg_Write32(volatile uint32_t *reg, uint32_t val)
{
    *reg = val;
}

/**
 * @brief  Reg_Read32
 * @brief  32位寄存器整体读取数据
 * @param  reg: 目标寄存器地址指针
 * @retval 寄存器当前32位数值
 * @note   实时读取硬件寄存器最新状态，无编译器缓存
 */
uint32_t Reg_Read32(volatile uint32_t *reg)
{
    return *reg;
}

/**
 * @brief  Reg_BitSet32
 * @brief  32位寄存器指定位置1
 * @param  reg: 目标32位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 * @note   仅置位目标bit，不影响其他位，安全增量配置
 */
void Reg_BitSet32(volatile uint32_t *reg, uint8_t bit)
{
    BIT_SET(*reg, bit);
}

/**
 * @brief  Reg_BitClr32
 * @brief  32位寄存器指定位清零
 * @param  reg: 目标32位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 * @note   仅清零目标bit，保留其余位配置
 */
void Reg_BitClr32(volatile uint32_t *reg, uint8_t bit)
{
    BIT_CLR(*reg, bit);
}

/**
 * @brief  Reg_BitToggle32
 * @brief  32位寄存器指定位电平翻转
 * @param  reg: 目标32位寄存器地址指针
 * @param  bit: 目标操作位号(0起始)
 * @retval 无
 * @note   0变1、1变0，适用于状态切换场景
 */
void Reg_BitToggle32(volatile uint32_t *reg, uint8_t bit)
{
    BIT_TOGGLE(*reg, bit);
}

/**
 * @brief  Reg_BitGet32
 * @brief  读取32位寄存器指定位电平状态
 * @param  reg: 目标32位寄存器地址指针
 * @param  bit: 目标读取位号(0起始)
 * @retval 0: 低电平  1: 高电平
 */
uint8_t Reg_BitGet32(volatile uint32_t *reg, uint8_t bit)
{
    return BIT_GET(*reg, bit);
}

/*****************************************************************************
 * 高级寄存器配置与复位通用接口（兼容全位宽）
 *****************************************************************************/
/**
 * @brief  Reg_MaskConfig
 * @brief  寄存器掩码精准配置
 * @param  reg: 目标32位寄存器地址指针
 * @param  mask: 待配置区域掩码
 * @param  val: 待写入区域数值
 * @retval 无
 * @note   只修改掩码对应bit，保留其他位，避免全局覆盖，嵌入式标配写法
 */
void Reg_MaskConfig(volatile uint32_t *reg, uint32_t mask, uint32_t val)
{
    *reg = (*reg & ~mask) | (val & mask);
}

/**
 * @brief  Reg_Reset
 * @brief  寄存器复位至指定默认值
 * @param  reg: 目标32位寄存器地址指针
 * @param  rst_val: 寄存器复位默认值
 * @retval 无
 * @note   模拟MCU上电复位、外设复位功能
 */
void Reg_Reset(volatile uint32_t *reg, uint32_t rst_val)
{
    *reg = rst_val;
}