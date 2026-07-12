/**
 * @file    main.c
 * @brief   寄存器读写框架 测试主函数
 * @details 全覆盖测试 8/16/32位寄存器专属读写、位操作、掩码配置、外设初始化、寄存器复位
 *          无类型强制转换BUG，全接口适配对应位宽寄存器
 * @author  框架模拟工程
 * @date    2026
 */
#include <stdio.h>
#include "register_framework.h"

/**
 * @brief  main
 * @brief  程序入口，框架全功能测试总流程
 * @retval 0: 正常运行结束
 */
int main(void)
{
    uint32_t reg_val32;  // 存储32位寄存器读取值
    uint16_t reg_val16;  // 存储16位寄存器读取值
    uint8_t  reg_val8;   // 存储8位寄存器读取值
    uint8_t  bit_stat;   // 存储寄存器单个bit状态值

    printf("===== 全位宽MCU寄存器读写框架测试 =====\r\n\r\n");

    // 1. 8位寄存器完整功能测试（读写+位操作）
    printf("1. 8位寄存器完整功能测试\r\n");
    Reg_Write8(&GPIO_REG_8BIT, 0x00);                 // 8位寄存器初始清零
    Reg_BitSet8(&GPIO_REG_8BIT, 0);                   // 置位BIT0
    Reg_BitSet8(&GPIO_REG_8BIT, 2);                   // 置位BIT2
    reg_val8 = Reg_Read8(&GPIO_REG_8BIT);             // 读取8位寄存器数值
    printf("8位寄存器置位BIT0、BIT2，读取值：0x%02X\r\n", reg_val8);
    
    Reg_BitClr8(&GPIO_REG_8BIT, 0);                   // 清零BIT0
    bit_stat = Reg_BitGet8(&GPIO_REG_8BIT, 2);        // 读取BIT2状态
    printf("清零BIT0后，8位寄存器值：0x%02X，BIT2状态：%d\r\n\r\n", Reg_Read8(&GPIO_REG_8BIT), bit_stat);

    // 2. 16位寄存器完整功能测试（读写+位操作）
    printf("2. 16位寄存器完整功能测试\r\n");
    Reg_Write16(&GPIO_REG_16BIT, 0x0000);             // 16位寄存器初始清零
    Reg_BitSet16(&GPIO_REG_16BIT, 4);                // 置位BIT4
    Reg_BitToggle16(&GPIO_REG_16BIT, 4);             // 翻转BIT4（清零）
    Reg_BitSet16(&GPIO_REG_16BIT, 8);                // 置位BIT8
    reg_val16 = Reg_Read16(&GPIO_REG_16BIT);          // 读取16位寄存器数值
    bit_stat = Reg_BitGet16(&GPIO_REG_16BIT, 8);      // 读取BIT8状态
    printf("16位寄存器翻转BIT4、置位BIT8，读取值：0x%04X，BIT8状态：%d\r\n\r\n", reg_val16, bit_stat);

    // 3. 32位基础寄存器整体读写测试
    printf("3. 32位基础寄存器读写测试\r\n");
    Reg_Write32(&GPIO_DR, 0x0000000F);                 // 给GPIO数据寄存器写入0x0F，低4位置1
    reg_val32 = Reg_Read32(&GPIO_DR);                  // 读取GPIO数据寄存器数值
    printf("GPIO_DR寄存器写入0x0000000F，读取值：0x%08X\r\n\r\n", reg_val32);

    // 4. 32位寄存器单bit位操作测试
    printf("4. 32位寄存器位操作测试\r\n");
    Reg_BitClr32(&GPIO_DR, GPIO_PIN_0);               // 清零PIN0对应bit
    printf("清零GPIO_PIN0后，GPIO_DR值：0x%08X\r\n", Reg_Read32(&GPIO_DR));

    Reg_BitClr32(&GPIO_DR, GPIO_PIN_3);               // 预先清零PIN3，制造可变化场景
    Reg_BitSet32(&GPIO_DR, GPIO_PIN_3);               // 置位PIN3对应bit
    printf("置位GPIO_PIN3后，GPIO_DR值：0x%08X\r\n", Reg_Read32(&GPIO_DR));

    bit_stat = Reg_BitGet32(&GPIO_DR, GPIO_PIN_3);    // 读取PIN3位状态
    printf("GPIO_PIN3状态：%d\r\n\r\n", bit_stat);

    // 5. 寄存器掩码区域精准配置测试
    printf("5. 寄存器掩码配置测试\r\n");
    // 仅修改GPIO_CR低4位为0x03，高位保持不变
    Reg_MaskConfig(&GPIO_CR, REG_MASK(0, 4), 0x00000003);
    printf("GPIO_CR低4位配置为3，寄存器值：0x%08X\r\n\r\n", Reg_Read32(&GPIO_CR));

    // 6. UART外设寄存器初始化模拟测试
    printf("6. UART外设寄存器初始化测试\r\n");
    Reg_Write32(&UART_BAUD, 0x0000036B);              // 配置UART波特率9600
    Reg_BitSet32(&UART_CTRL, UART_EN_BIT);             // 使能UART模块
    Reg_BitSet32(&UART_CTRL, UART_TX_EN_BIT);         // 开启UART发送功能
    Reg_BitSet32(&UART_CTRL, UART_RX_EN_BIT);         // 开启UART接收功能
    printf("UART波特率寄存器：0x%08X\r\n", Reg_Read32(&UART_BAUD));
    printf("UART控制寄存器：0x%08X\r\n\r\n", Reg_Read32(&UART_CTRL));

    // 7. 寄存器复位功能测试
    printf("7. 寄存器复位测试\r\n");
    Reg_Reset(&GPIO_DR, 0x00000000);                  // 将GPIO_DR寄存器复位为0
    printf("GPIO_DR复位后的值：0x%08X\r\n", Reg_Read32(&GPIO_DR));

    printf("\r\n===== 全位宽寄存器框架测试执行完成 =====\r\n");

    return 0;
}