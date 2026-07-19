#include "LinkList.h"
#include <stdio.h>

/**
 * @brief  initLinkList
 * @brief  初始化链表
 * @param  L: 目标链表
 * @retval 是否初始化成功
 * @note   无
 */
_Bool initLinkList(LinkList L){

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
            count ++;
        }
        p = p->next;
    }
    return count;
}
