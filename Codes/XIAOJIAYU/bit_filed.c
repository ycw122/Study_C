
#include <stdio.h>
#include <stdint.h>

// 定义一个包含位字段的结构体，用于表示一个8位寄存器
struct Register {
    uint8_t bit0 : 5;  // 占用1位，范围0~1
    uint8_t bit1 : 4;  // 占用1位，范围0~1
    uint8_t bit2_4 : 3;// 用3位，范围0~7（2^3-1）
    uint8_t bit5_7 : 3;// 占用3位，范围0~7
};
struct BitField {
    unsigned int switch1 : 1; // 1位
    unsigned int  switch2 : 1; // 1位
    unsigned int  switch3 : 1; // 1位
};

struct AlignBitField {
    unsigned int bit0 : 1;  // 1位
    unsigned int bit1 : 1;  // 1位
};

struct Sensor_Data {
    uint8_t  temp : 5;    // 温度数据：0~31℃（实际传感器温度范围，5位可覆盖，2^5=32）
    uint8_t humi : 4;    // 湿度数据：0~15%（简化场景，4位可覆盖，2^4=16）
    uint8_t  light : 3;   // 光照强度：0~7级（分级表示，3位足够，2^3=8）
    uint8_t  status : 1;  // 传感器状态：0=异常，1=正常（1位即可区分两种状态）

};

int main() {
    struct Register reg;
    struct BitField bf;
    struct AlignBitField abf;
    struct Sensor_Data sd;
   
    // %zu：专门输出size_t类型，sizeof返回值为size_t，用于正确输出内存大小
    printf("结构体Register占用内存大小：%zu 字节\n", sizeof(reg));
    printf("结构体Register占用内存大小：%zu 字节\n", _Alignof(reg));
    printf("结构体Register占用内存大小：%zu 字节\n", _Alignof(bf));
    printf("结构体Register占用内存大小：%zu 字节\n", _Alignof(abf));
    printf("结构体Register占用内存大小：%zu字节\n", sizeof(sd));
    return 0;
}
