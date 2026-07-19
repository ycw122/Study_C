#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdint.h>
#include <stdbool.h>

// struct LNode 占16个字节val占一个字节，指针next占8个字节（64位操作系统的指针一般位32/64位）
typedef struct LNode
{
    uint8_t val;
    struct LNode *next;
} *LinkList, LNode;

/*
后面的一切函数都是在有头节点的基础上进行操作
注意首节点是链表实质上第一个存放数据可用数据的节点
头节点的next指针指向首节点，他们是两个不同的节点
L->headNode, headNode.next->firsNode
*/
extern bool initLinkList(LinkList *L);

extern void destroyLinkList(LinkList *L);

extern void addNode(LinkList L);

extern uint8_t delNodeByVal(LinkList L, uint8_t tarVal);

extern void traverseLinkList(LinkList L);
#endif