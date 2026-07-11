#include <stdio.h>
/* 在C中所有外设都被当作文件处理，所以键盘输入stdin,和屏幕输出stdout 都是文件流，可以当作函数fgets和fputs的 文件流参数。
        char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
        fgets中，第一个参数char *__restrict __s指向一个字符数组（字符串），用来保存读取的内容，第二个参数int __n表示要读取的内容的大小，
        第三个参数FILE *__restrict __stream是指向被读取的文件流，可以是键盘sdtin，文件等。
        fgets返回一个字符指针char *，指向原本用来保存读取内容的数组，和第一个参数char *__restrict __s指向的内容相同，读取失败 / 读到文件末尾时返回 NULL
        作用是可以作为读取成功 / 失败的判断标记

    */
/* int fputs (const char *__restrict __s, FILE *__restrict __stream)
        第一个参数const char *__restrict __s指向需要被输出的内容，第二个参数FILE *__restrict __stream指向输出的文件流，
        可以是文件或者屏幕stdout,但不会自动在字符串末尾添加换行符
    */
int main()
{
    char str[30];
    printf("please input something in the terminal with your keyboard:\n");
    //    下面这个语句相当于scanf("%s",str);
    if (fgets(str, sizeof(str), stdin))
    {
        printf("next line shows what you have input before:\n");
        // 下面这个语句相当于printf("%s",str);
        fputs(str, stdout);
    }
    else
    {
        printf("failed to input something!\n");
    }

    return 0;
}