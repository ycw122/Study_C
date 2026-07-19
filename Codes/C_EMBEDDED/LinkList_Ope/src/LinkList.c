#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief  initLinkList
 * @brief  初始化链表（含头节点）
 * @param  L: 用来接收目标链表头指针的地址，这是一个二级指针
 * @retval 是否初始化成功
 * @note   要在另外一个函数里修改一个指针保存的地址，必须传入这个指针的地址，通过解引用来修改指针保存的地址
 */
bool initLinkList(LinkList *L)
{
    if ((*L = malloc(sizeof(LNode))) != NULL)
    {
        /* 将头节点的next指向NULL*/
        LinkList p=*L;
        p->next=NULL;
        printf("initalize LinkList with headNode successfully!\n");
        return true;
    }
    else
    {
        printf("failed to initalize LinkList with headNode!\n");
        return false;
    }
}

/**
 * @brief  destroyLinkList
 * @brief  销毁链表
 * @param  L: 用来接收目标链表头指针的地址，这是一个二级指针
 * @retval none
 * @note   要在另外一个函数里修改一个指针保存的地址，必须传入这个指针的地址，通过解引用来修改指针保存的地址
 */
void destroyLinkList(LinkList *L)
{
    LNode *p = *L;
    LNode *q = NULL;
    while (p != NULL)
    {
        /* code */
        q = p->next;
        /* 注意free函数只是在堆内存中把指针p中保存的地址标记为空闲(可分配状态)，
        没有清空地址中的数据，也没有把p=NULL，p在栈内存中，free无权操作 */
        free(p);
        p = q;
    }
    *L = NULL;
    printf("destroy LinkList successfully!\n");
    return;
}


/**
 * @brief  addNode
 * @brief  添加链表节点
 * @param  L: 目标链表头指针
 * @retval none
 * @note   none
 */
void addNode(LinkList L){
    // val存放新节点的值
    uint8_t val;
    printf("please input a value which includes two hexadecimal members for new Node:\n");
    scanf("%hhx",&val);
    // 创建工作指针p指向头节点
    LNode *p=L;
    // 遍历寻找next为NULL的节点
    while (p->next!=NULL)
    {
        p=p->next;
    }
    // 创建新的节点链接到链表尾部
    p->next=malloc(sizeof(LNode));

    p->next->val=val;   
    // 新节点的next指向NULL
    p->next->next=NULL;
    printf("you have add a new Node successfully whose value is 0x%hhx\n",val);
}

/**
 * @brief  delNodeByVal
 * @brief  删除链表节点
 * @param  L: 目标链表
 * @param  tarVal: 目标值
 * @retval 删除节点的数量
 * @note   查找并删除与目标值相同的节点，返回删除节点的数量
 */
uint8_t delNodeByVal(LinkList L, uint8_t tarVal)
{
    LinkList p = L;
    uint8_t count;
    while (p != NULL && p->next != NULL)
    {
        if (p->next->val == tarVal)
        {
            /* code */
            p->next = p->next->next;
            count++;
        }
        p = p->next;
    }
    return count;
}


void traverseLinkList(LinkList L){
    uint8_t count=0;
    // 跳过头节点，直接指向首节点
    LNode *p=L->next;
    while (p!=NULL)
    {
        count ++;
        printf("No.%u:Node's value is %hhx\n",count,p->val);
        p=p->next;
    }
    printf("traverse done!\n");
}
