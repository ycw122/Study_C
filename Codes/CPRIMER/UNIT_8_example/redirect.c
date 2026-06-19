#include <stdio.h>


/* 注意：
        1、在终端输入重定向命令时，可执行程序名在前，文件名在后，例如：redirect.exe < input.txt合法，input.txt > redirect.exe非法
        2、本电脑是64位系统，而编译器编译生成的redirect.exe为32位文件，直接在终端重定向会系统报错,
           需要使用命令：gcc redirect.c -o redirect.exe -m64 强制生成64位可执行文件，然后再执行 redirect.exe < input.exe命令
        3、重定向命令的使用：
                redirect.exe < in.txt 重定向输入到文件，将文件的内容输出到终端打印；
                redirect.exe > out.txt 重定向输出到文件，将终端的输入内容写入到文件中；
                redirect.exe < in.txt > out.txt 同时重定向输入和输出，将文件的内容输出到另一个文件中；
                redirect.exe >> out.txt 追加重定向输出到文件，将终端的输入内容追加写入到文件中，而不是覆盖原有内容。
*/
int main(){
    int ch;
    while ((ch=getchar())!=EOF)
    {
        putchar(ch);
    }
        return 0;
}