#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    LinkList L = NULL;
    uint8_t num;
    while (1)
    {
        printf("****************************************\n");
        printf("******Linkist Operatinng Sysetem********\n");
        printf("****************************************\n");
        printf("**Enter number 1-11 to choose Operating:\n");
        printf("**  1--initalize LinkList    ***********\n");
        printf("**  2--destrory LinkList     ***********\n");
        printf("**  3--add LNode             ***********\n");
        printf("**  4--delete LNode by value ***********\n");
        printf("**  5--delete LNode by serial number****\n");
        printf("**  6--find LNode by value   ***********\n");
        printf("**  7--find LNode by serial number   ***\n");
        printf("**  8--change LNode by value   *********\n");
        printf("**  9--change LNode by serial number   *\n");
        printf("**  10--traverse LinkList    ***********\n");
        printf("**  11--stop program         ***********\n");
        printf("****************************************\n");
        printf("enter your choice in here:\n");

        // 修复：%hhu 匹配 uint8_t(unsigned char)
        scanf("%hhu", &num);
        clearStdin(); // 清除回车缓存

        switch (num)
        {
        case 1:
            printf("1 -- Initialize LinkList\n");
            initLinkList(&L);
            break;
        case 2:
            printf("2 -- Destroy LinkList\n");
            destroyLinkList(&L);
            break;
        case 3:
            printf("3 -- Add LNode\n");
            addNode(L);
            break;
        case 4:
            printf("4 -- Delete LNode by value\n");
            delNodeByVal(L);
            break;
        case 5:
            printf("5 -- Delete LNode by serial number\n");
            break;
        case 6:
            printf("6 -- Find LNode by value\n");
            break;
        case 7:
            printf("7 -- Find LNode by serial number\n");
            break;
        case 8:
            printf("8 -- Change LNode by value\n");
            break;
        case 9:
            printf("9 -- Change LNode by serial number\n");
            break;
        case 10:
            printf("10 -- Traverse LinkList\n");
            traverseLinkList(L);
            break;
        case 11:
            printf("Exit program...\n");
            return 0; // 11号才退出程序
        default:
            printf("Error! Please enter number between 1 - 11\n");
            break;
        }
        printf("\n");
    }
}
