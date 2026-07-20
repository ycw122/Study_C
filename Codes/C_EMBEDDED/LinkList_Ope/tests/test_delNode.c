#include <stdio.h>
#include <stdlib.h>
#include "LinkList_test.h"

int main (){
    printf("start test!\n");
    // 初始化链表
    LinkList L=malloc(sizeof(LNode));
    // 添加节点
    LNode *p=L;
    for (uint8_t i = 0; i < 3; i++)
    {
        p->next=malloc(sizeof(LNode));
        p=p->next;
        p->val=1;
    }
    p=NULL;     //添加节点完成后将工作指针指向NULL
    // 开始删除节点
    delNodeByVal(L);
    destroyLinkList(&L);
    return 0;
}