#include <stdio.h>
#include <stdlib.h>

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiplication(float a, float b) { return a * b; }
float division(float a, float b) { return a / b; }

float (*p)(float a, float b);

int main()
{
    float m, n;
    char c;
    while (1)
    {
        printf("please input an operator,like + _ * /,  E or e for Exiting the program!\n");
        // 输入字符后按下的回车键相当于一个换行符存在于输入缓冲区，会影响下一次的输入，使用getchar()将换行符读出，避免影响程序
        scanf("%c", &c);
        getchar();
        /* if (c=='+')
        {
            p=add;
        }else if (c=='-')
        {
            p=subtract;
        }else if (c=='*')
        {
            p=multiplication;
        }else if (c=='/')
        {
            p=division;
        }else if (c=='E'||c=='e')
        {
            return 0;
        }else{
            printf("please input an corrcet operator!\n");
            continue;
        } */
        switch (c)
        {
        case '+':
            p = add;
            break;
        case '-':
            p = subtract;
            break;
        case '*':
            p = multiplication;
            break;
        case '/':
            p = division;
            break;
        case 'E':
            return 0;
            // break;
        case 'e':
            return 0;
            // break;
        default:
            printf("please input an corrcet operator!\n");
            continue;
        }
        printf("please input two numbers\n");
        // 输入字符后按下的回车键相当于一个换行符存在于输入缓冲区，会影响下一次的输入，使用getchar()将换行符读出，避免影响程序
        scanf("%f %f", &m, &n);
        getchar();
        if (p == division && n == 0)
        {
            printf("the first second must be zero!\n");
            continue;
        }
        printf("result = %f\n", p(m, n));
    }
    /*
    printf("address of add is %p\n",add);
    printf("address of subtract is %p\n",subtract);
    printf("address of multiplation is %p\n",multiplication);
    printf("address of divison is %p\n",division);
    printf("content of pointer p is %p\n",p);
    printf("address of pointer p is %p\n",&p);
    */
    return 0;
}