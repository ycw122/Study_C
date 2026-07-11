#include <stdio.h>
#include <stdlib.h>

// 结构体定义不变
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// C版本初始化函数：形参是二级指针 LinkList *L
_Bool InitList(LinkList *L)
{
    // *L 等价于 main 里的 LinkList L，必须解引用
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
    {
        return 0; // 内存分配失败
    }
    (*L)->next = NULL; // 头节点next置空
    return 1;
}


int main() {
    LinkList L;          // 定义头指针
    InitList(&L);        // C必须传 &L，取指针变量地址

    LNode *a = List_TailInsert(L);
    LNode *cur = a->next;

    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }

    return 0;
}
