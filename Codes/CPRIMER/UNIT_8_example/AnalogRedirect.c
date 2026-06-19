#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数声明
void keyboard_to_file();    // 键盘输入 → 文件输出
void file_to_terminal();    // 文件输入 → 终端输出
void file_to_file();        // 文件输入 → 文件输出
void show_menu();           // 显示选项菜单

int main() {
    int choice;
    while (1) {
        show_menu();
        printf("请输入您的选择（1-4）：");
        // 校验输入是否为整数
        if (scanf("%d", &choice) != 1) {    // 如果输入不是整数，scanf会返回0，判断条件为真
            // 清空输入缓冲区的非法字符
            while (getchar() != '\n');  // 读取并丢弃输入缓冲区中的所有字符，直到遇到换行符为止，确保下一次输入时不会受到之前非法输入的影响
            printf("输入无效，请输入数字 1-4！\n\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n--- 开始模拟：键盘输入 → 文件输出 ---\n");
                keyboard_to_file();
                break;
            case 2:
                printf("\n--- 开始模拟：文件输入 → 终端输出 ---\n");
                file_to_terminal();
                break;
            case 3:
                printf("\n--- 开始模拟：文件输入 → 文件输出 ---\n");
                file_to_file();
                break;
            case 4:
                printf("程序已结束，感谢使用！\n");
                exit(0); // 正常退出程序
            default:
                printf("输入错误，请选择 1-4 之间的选项！\n\n");
        }
        printf("\n----------------------------------------\n\n"); // 分隔线，提升交互体验
    }
    return 0;
}

// 显示选项菜单
void show_menu() {
    printf("====================================\n");
    printf("          重定向模拟程序            \n");
    printf("====================================\n");
    printf("1. 键盘输入 → 文件输出\n");
    printf("2. 文件输入 → 终端输出\n");
    printf("3. 文件输入 → 文件输出\n");
    printf("4. 结束程序\n");
    printf("====================================\n");
}

// 模拟：键盘输入 → 文件输出
void keyboard_to_file() {
    char filename[50];
    FILE *fp_out;
    int ch;

    printf("请输入要写入的文件名：");
    scanf("%s", filename);
    // 清空scanf残留的换行符（避免影响后续getchar）
    getchar();

    // 打开文件（追加模式？可选w/wa，w会清空原有内容，a是追加）
    fp_out = fopen(filename, "w");
    if (fp_out == NULL) {
        perror("文件打开失败"); // 打印具体错误原因
        return;
    }

    printf("请输入内容（输入 Ctrl+Z 并回车结束输入，Windows）/ Ctrl+D（Linux/Mac）：\n");
    // 从键盘（stdin）读取字符，写入文件
    while ((ch = fgetc(stdin)) != EOF) {
        fputc(ch, fp_out);
    }

    fclose(fp_out);
    printf("内容已成功写入文件 [%s]！\n", filename);
}

// 模拟：文件输入 → 终端输出
void file_to_terminal() {
    char filename[50];
    FILE *fp_in;
    int ch;

    printf("请输入要读取的文件名：");
    scanf("%s", filename);

    fp_in = fopen(filename, "r");
    if (fp_in == NULL) {
        perror("文件打开失败");
        return;
    }

    printf("文件内容如下：\n----------------------------------------\n");
    // 从文件读取字符，输出到终端（stdout）
    while ((ch = fgetc(fp_in)) != EOF) {
        fputc(ch, stdout);
    }
    printf("\n----------------------------------------\n");

    fclose(fp_in);
    printf("文件内容已成功输出到终端！\n");
}

// 模拟：文件输入 → 文件输出（复用原代码核心逻辑，增加错误提示）
void file_to_file() {
    char filename_in[50], filename_out[50];
    FILE *fp_in, *fp_out;
    int ch;

    printf("请输入要读取的文件名：");
    scanf("%s", filename_in);
    printf("请输入要写入的文件名：");
    scanf("%s", filename_out);

    // 打开输入文件
    fp_in = fopen(filename_in, "r");
    if (fp_in == NULL) {
        perror("输入文件打开失败");
        return;
    }
    // 打开输出文件
    fp_out = fopen(filename_out, "w");
    if (fp_out == NULL) {
        perror("输出文件打开失败");
        fclose(fp_in); // 避免文件句柄泄漏
        return;
    }

    // 逐字符拷贝
    while ((ch = fgetc(fp_in)) != EOF) {
        fputc(ch, fp_out);
    }

    // 关闭文件
    fclose(fp_in);
    fclose(fp_out);
    printf("文件 [%s] 已成功拷贝到 [%s]！\n", filename_in, filename_out);
}

/* 
getchar(),getc(),fgetc()比较：

函数	    来源	    参数	    类型	    用途
getchar()	只能stdin	无	        函数	键盘 / 重定向读取
getc(fp)	任意流	    FILE*	    宏	    读取文件 / 键盘
fgetc(fp)	任意流	    FILE*	    函数	最安全、推荐读取文件

*/


/* int main(){
    int ch;
    FILE *fp_in, *fp_out; // Declare file pointers for input and output files
    char filename_in[50], filename_out[50]; // Buffers to hold the filenames
    printf("Enter the filename to read: ");
    scanf("%s",filename_in); // Read the filename from user input
    printf("Enter the filename to write: ");
    scanf("%s",filename_out); // Read the filename from user input
    fp_in = fopen(filename_in, "r"); // Open the specified file for reading
    if (fp_in == NULL) // Check if the file was opened successfully  
        return 0;
    fp_out = fopen(filename_out, "w"); // Open the specified file for writing
    if (fp_out == NULL) // Check if the file was opened successfully
        return 0;

    while ((ch=fgetc(fp_in))!=EOF)
    {
        fputc(ch, fp_out); // Write the character to the output file
    }
    fclose(fp_in); // Close the input file
    fclose(fp_out); // Close the output file
    return 0;
    
} */