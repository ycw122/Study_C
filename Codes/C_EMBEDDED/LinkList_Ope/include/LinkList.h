#ifndef LINKLIST_TEST_H
#define LINKLIST_TEST_H
#include <stdint.h>
#include <stdbool.h>

/*
后面的一切函数都是在有头节点的基础上进行操作
注意首节点是链表实质上第一个存放数据可用数据的节点
头节点的next指针指向首节点，他们是两个不同的节点
头节点的value用来保存链表的长度
L point at headNode, headNode.next point at firsNode
*/

// struct LNode 占16个字节val占一个字节，指针next占8个字节（64位操作系统的指针一般位32/64位），根据结构体的内存对其原则可知占16字节。
typedef struct LNode
{
    uint8_t val;
    struct LNode *next;
} *LinkList, LNode;

extern void clearStdin();

extern bool initLinkList(LinkList *L);

extern bool destroyLinkList(LinkList *L);

extern bool addNode(LinkList L);

extern bool delNodeByVal(LinkList L);

extern bool delNodeBySerialNum(LinkList L);

extern bool findNodeByVal(LinkList  L);

extern bool findNodeBySerialNum(LinkList L);

extern bool changeNodeByVal(LinkList L);

extern bool changeNodeBySerialNum(LinkList L);

extern bool traverseLinkList(LinkList L);
#endif