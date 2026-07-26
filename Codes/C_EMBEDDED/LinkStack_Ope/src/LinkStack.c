#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkStack.h"

void clearStdin(){
    int ch;
    while ((ch=getchar())!='\n'&&ch!=EOF);
}


/**
 * @brief  isEmpty
 * @brief  判断链栈是否为空
 * @param  L:接收头节点的地址
 * @retval POINT_TO_NULL：未初始化
 * @retval NEXT_POINT_TO_NULL：链栈为空
 * @retval NEXT_UNPOINT_TO_NULL：链栈不为空
 * @note   无
 * */
uint8_t isEmpty(LinkStack L)
{
    // 第一步：校验栈是否初始化
    if (L==NULL)
    {
        printf("LinkStack not been initalized,please initalize it first!\n");
        return POINT_TO_NULL;  // 未初始化
    }

    // NEXT_POINT_TO_NULL：链栈空 NEXT_UNPOINT_TO_NULL：链栈非空
    return (L->next == NULL?NEXT_POINT_TO_NULL:NEXT_UNPOINT_TO_NULL);
}


/**
 * @brief  init
 * @brief  初始化链栈
 * @param  L:接受头指针的地址，是一个二级指针
 * @retval 无
 * @note   无
 * */
void init(LinkStack *L){
    switch (isEmpty(*L))
    {
    case POINT_TO_NULL:         //未初始化
        *L=malloc(sizeof(LNode));
        break;
    case NEXT_UNPOINT_TO_NULL:  //链表不为空
        while ((*L)->next!=NULL)
        {
            delNextNode(*L);
        }
        break;
    default:    //已经初始化且链表为空
        break;
    }
    (*L)->Val=0;    //链栈长度置零
    printf("you have initalized the linkstack successfullu,and the length of linkstack is %hhu.\n",(*L)->Val);
}


/**
 * @brief  delNextNode
 * @brief  删除下一个节点
 * @param  N:接收当前节点的地址
 * @retval POINT_TO_NULL：未初始化
 * @retval NEXT_POINT_TO_NULL：下一个节点为空
 * @retval uint8_t(0～200)：被删除节点的值
 * @note   无
 * */
uint8_t delNextNode(LinkStack L){
    LNode *p=L,*q=NULL;
    if (p==NULL)
    {
        return POINT_TO_NULL;   //传入的指针未初始化   
    }else if (p->next==NULL)
    {
        return NEXT_POINT_TO_NULL;  //下一个节点为空
    }else
    {
        q=p->next;
        p->next=p->next->next;
        free(q);
        (L->Val)--; //链表长度减1
        printf("you have delete the LNode whose valuse is %hhx,and the length of linkstack is %hhu.\n",q->Val,L->Val);
        return q->Val;  //虽然此时free()了q，只是在堆内存标记q指向的地址为可分配状态，指针q仍然指向原地址，且地址内保存的值也没变。
    }
}

bool destrory(LinkStack *L){
    LNode *q=NULL;  //临时保存节点的指针
    LNode *p=*L;    //工作指针
    switch (isEmpty(*L))
    {
    case POINT_TO_NULL: //未初始化
        *L=NULL;
        break;
    case NEXT_POINT_TO_NULL:    //初始化但无数据节点
        q=*L;   //删除头节点
        *L=NULL;
        free(q);
        break;
    case NEXT_UNPOINT_TO_NULL:  //初始化了且有数据节点
        while (p->next!=NULL)
        {
            delNextNode(p);
        }
        q=*L;   //删除头节点
        *L=NULL;
        free(q);
        break;
    default:
        printf("failed to destrory the linkstack.\n");
        return false;;
    }
    printf("you have destroied linkstack successfully!\n");
    return true;
}

bool push(LinkStack L){
    //头插法
    
}
bool pop(){}
bool traverse(LinkStack L){}
