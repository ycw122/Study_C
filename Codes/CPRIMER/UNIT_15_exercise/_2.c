/* 编写一个程序，通过命令行参数读取两个二进制字符串，对这两
个二进制数使用～运算符、&运算符、|运算符和^运算符，并以二进制
字符串形式打印结果（如果无法使用命令行环境，可以通过交互式让
程序读取字符串） */

# include <stdio.h>

int hstoi(char * str); // Function prototype for htoi, which converts a binary string to an integer
char* itohs(int n);    // Function prototype for itohs, which converts an integer to a binary string

int main(void) {
    printf("Enter first binary string: ");
    char bin1[33]; // Buffer to hold the first binary string (32 bits + null terminator)
    //%32s格式说明符告诉scanf函数最多读取32个字符，以防止缓冲区溢出。因为我们需要存储一个32位的二进制字符串，所以需要一个33个字符的数组来存储输入的字符串（32位二进制数加上一个用于字符串结束的null字符'\0'，系统会自动填充第33个字符为'\0'）。使用scanf函数读取用户输入的二进制字符串，并限制输入长度为32个字符，以防止缓冲区溢出。
    //当我输入'0101'字符串时，四个字符从左往右依次填充在数组的bin1[0]，bin1[1],bin1[2],bin1[3]这四个位置中，然后系统自动将bin1[4]='/0',后面27个位置的内容不变   
     scanf("%32s", bin1); // Read the first binary string from user input

    printf("Enter second binary string: ");
    //申请33个字符的数组来存储输入的二进制字符串，32位二进制数加上一个用于字符串结束的null字符'\0'。使用scanf函数读取用户输入的二进制字符串，并限制输入长度为32个字符，以防止缓冲区溢出。
    char bin2[33]; // Buffer to hold the second binary string (32 bits + null terminator)
    scanf("%32s", bin2); // Read the second binary string from user input   
    int num1 = hstoi(bin1); // Convert the first binary string to an integer
    int num2 = hstoi(bin2); // Convert the second binary string to an integer
    if (num1 == -1 || num2 == -1) { // Check for invalid input
        printf("Invalid binary string input.\n");
        return 1; // Exit with an error code
    }   
    int and_result = num1 & num2; // Perform bitwise AND operation
    int or_result = num1 | num2;  // Perform bitwise OR operation      
    int xor_result = num1 ^ num2; // Perform bitwise XOR operation
    int not_result = ~num1;       // Perform bitwise NOT operation on the first number
    /* 因为 printf 中的 %s 格式说明符用于打印字符串的内容（即从指针指向的内存地址开始读取字符，直到遇到 \0 结束符），
    而不是打印指针变量本身的地址值，%s 会解引用这个指针并打印字符串内容
    如果你想打印指针变量的地址（即内存地址），应该使用 %p 格式说明符，例如：
    printf("Bitwise AND result address: %p\n", (void*)itohs(and_result));
    这样会输出类似 0x7ffd... 的地址值。注意，%p 需要将指针转换为 void* 类型以避免警告。 */
    printf("Bitwise AND result: %s\n", itohs(and_result)); // Convert the AND result to a binary string and print it
    printf("Bitwise OR result: %s\n", itohs(or_result));    // Convert the OR result to a binary string and print it
    printf("Bitwise XOR result: %s\n", itohs(xor_result));  // Convert the XOR result to a binary string and print it
    printf("Bitwise NOT result: %s\n", itohs(not_result));          // Convert the NOT result to a binary string and print it
    return 0; // Exit with success  

}

int hstoi(char * str) {
    int result = 0; // Initialize result to 0
    while (*str) { // Loop through each character in the string until we reach the null terminator
        result <<= 1; // Shift result left by 1 bit to make room for the next bit
        if (*str == '1') { // If the current character is '1'
            result |= 1; // Set the least significant bit of result to 1
        } else if (*str != '0') { // If the current character is not '0' or '1', it's an invalid input
            return -1; // Return -1 to indicate an error
        }
        str++; // Move to the next character in the string
    }
    return result; // Return the final integer result
}

char* itohs(int n) {
    static char buffer[33]; // Buffer to hold the binary string (32 bits + null terminator)
    buffer[32] = '\0'; // Null-terminate the string
    for (int i = 31; i >= 0; i--) { // Loop from the highest bit to the lowest bit
        buffer[i] = (n & 1) ? '1' : '0'; // Set the current bit in the buffer to '1' or '0'
        n >>= 1; // Shift n right by 1 bit to process the next bit
    }
    return buffer; // Return the pointer to the binary string
}
