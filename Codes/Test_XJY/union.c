#include <stdio.h>
#include<stdint.h>

union Data{
    uint8_t byte;
    uint16_t word;
};

int main(void)
{
    union Data buf;
    buf.word = 0x1234;
    // 共用同一块内存，byte取低字节
    printf("word=0x%04X, byte=0x%02X\n", buf.word, buf.byte);

    buf.byte = 0x99;
    // 修改字节后，16位数据被覆盖
    printf("word=0x%04X, byte=0x%02X\n", buf.word, buf.byte);
    return 0;
}
