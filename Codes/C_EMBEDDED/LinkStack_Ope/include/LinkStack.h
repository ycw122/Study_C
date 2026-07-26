#ifndef LINKSTACK_H
#define LINKSTACK_H
#include <stdint.h>
#include <stdbool.h>


/* 规定头节点存放链栈的长度，链栈的节点value值在0～200之间 */


#define POINT_TO_NULL 255   //指针指向NULL
#define UNPOINT_TO_NULL 254     //指针不指向NULL
#define NEXT_POINT_TO_NULL 253      //指针的next指向NULL
#define NEXT_UNPOINT_TO_NULL 252        //指针的next不指向NULL

typedef struct LNode
{
    uint8_t Val;
    LNode *next;
}*LinkStack,LNode;

extern void clearStdin();
extern uint8_t isEmpty(LinkStack L);
extern void init(LinkStack *L);
extern bool destrory(LinkStack *L);
extern bool push(LinkStack L);
extern bool pop();
extern bool traverse(LinkStack L);


#endif