#include <stdio.h>

int main(void)
{
    /* Bitwise Operations RESULTS:
        Result of masking: 0xCD
        Result of bitwise OR: 0xABFF
        Result of bitwise XOR: 0xAB32
        Result of bitwise NOT: 0xFFFF5432(对此结果存在疑问，是因为int类型的位数不同导致的结果差异，在32位系统中，int类型通常是32位的(4个字节)，而十六进制的"ABCD"只占了16位(4*4)，其他16位被填充为0，所以~0xABCD的结果是0xFFFF5432，而在16位系统中，int类型通常是16位的，所以~0xABCD的结果是0x5432)
    */
    int MASK = 0xFF; // Example mask value
    int value = 0xABCD; // Example value to be masked
    int result = value & MASK; // Apply the mask to the value
    int result2 = value | MASK; // Apply the mask using bitwise OR
    int result3 = value ^ MASK; // Apply the mask using bitwise XOR
    int result4 = ~value; // Apply the bitwise NOT to the value

    printf("Result of bitwise AND: 0x%X\n", result); // Print the result in hexadecimal format
    printf("Result of bitwise OR: 0x%X\n", result2);
    printf("Result of bitwise XOR: 0x%X\n", result3);
    printf("Result of bitwise NOT: 0x%X\n", result4);
    return 0;
}