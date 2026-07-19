#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdint.h>
#include <stdlib.h>

typedef struct LNode
{
    uint8_t val;
    struct LNode *next;
}*LinkList,LNode;


extern _Bool initLinkList(LinkList L);
extern uint8_t delNodeByVal(LinkList L,uint8_t tarVal);
#endif