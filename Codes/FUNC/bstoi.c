#include <stdio.h>
int btoi(char * pbin);
int main() {
    char * pbin="1010";//此处的pbin是一个字符指针，指向一个字符串的首地址，应该使用char*类型来声明，而不是char类型，因为我们需要传入一个字符串的地址，而不是一个单独的字符。正确的声明应该是char *pbin="1010";，这样pbin就可以指向字符串"1010"的首地址，并且可以通过指针操作来访问字符串中的每个字符。
    int value = btoi(pbin);//此处的pbin是一个字符指针
    printf("The decimal value of %s is %d\n", pbin, value);
    return 0;
}

int btoi(char * pbin){ //此处的*pbin是一个字符指针，指向一个字符串的首地址，函数的参数类型应该是char*，而不是char，因为我们需要传入一个字符串的地址，而不是一个单独的字符。而不是char pbin，因为char pbin是一个字符变量，无法存储字符串的地址，也无法通过指针操作来访问字符串中的每个字符。
        int result=0;
        while( *pbin !='\0'){ //*pbin 是一个字符，pbin是一个指针(地址)，指向一个字符串的首地址所以此处不能直接用pbin来判断是否到达字符串末尾，而应该用*pbin来判断当前字符是否为'\0'，即字符串的结束标志。
            result<<=1;
            if( *pbin=='1')	result |=1;
            else if ( *pbin =='0')	result |=0;
            else return -1;
            pbin++;//此处使用pbin++来移动指针，指向下一个字符，而不能使用*pbin++，因为*pbin++会先解引用当前指针的值，然后再将指针移动到下一个位置，这样会导致在判断条件时使用了错误的字符值。正确的做法是先判断当前字符的值，然后再移动指针。
        }
        return result;
}

/*
//精简版
int bstoi(const char *str) {
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
*/

/*注意指针的使用：char * pbin="1010"与 int btoi(char * pbin)的char *类型一致,是对指针pbin 的声明
和定义，char * pbin="1010"是对指针pbin的定义和初始化，int sbtoi(char * pbin)是对函数参数pbin的声明，表示该函数接受一个char*类型的参数，即一个指向字符的指针。这两者都是正确的用法，符合C17语言标准。
而*pbin=='1'和*pbin=='0'是对指针pbin所指向的字符进行比较，判断当前字符是否为'1'或'0'，这是正确的用法，因为*pbin表示指针pbin所指向的字符值。
*/
