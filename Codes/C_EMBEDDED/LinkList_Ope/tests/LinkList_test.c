#include "LinkList_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  清空缓冲区的字符，这里换行符'\n'也被清空，包括如果用户输入结束是 EOF（Ctrl+D / Ctrl+Z），也给清空。
void clearStdin()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * @brief  initLinkList
 * @brief  初始化链表（含头节点）
 * @param  L: 用来接收目标链表头指针的地址，这是一个二级指针
 * @retval 是否初始化成功
 * @note   要在另外一个函数里修改一个指针保存的地址，必须传入这个指针的地址，通过解引用来修改指针保存的地址
 */
bool initLinkList(LinkList *L)
{
    /* 判断链表是否已经被初始化，如果指针指向NULL，说明没有初始化，可进行初始化操作。
    若是已经初始化，需要先执行destroyLinkList操作，free堆内存，不然会造成堆内存溢出 */
    if (*L == NULL)
    {
        // 初始化成功
        if ((*L = malloc(sizeof(LNode))) != NULL)
        {
            (*L)->next = NULL; /* 将头节点的next指向NULL */
            (*L)->val = 0;     // 将头节点的值(链表的长度置为0)
            printf("initalized LinkList pointed to headNode successfully!\n");
            return true;
        }
        else
        {
            printf("failed to initalize LinkList，could not allocate full heap memory!\n"); // allocate:分配
            return false;
        }
    }
    else
    {
        printf("this LinkList had been initalized before,please free the heap memories to destroy LinkList first!\n");
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
bool destroyLinkList(LinkList *L)
{
    if (*L != NULL) // 先判断链表是否存在，即头指针是否指向空
    {
        LNode *p = *L;
        LNode *q = NULL;
        while (p != NULL)
        {
            q = p->next;
            /* 注意free函数只是在堆内存中把指针p中保存的地址标记为空闲(可分配状态)，
            没有清空地址中的数据，也没有把p=NULL，p在栈内存中，free无权操作 */
            free(p);
            p = q;
        }
        *L = NULL;
        printf("destroy LinkList successfully!\n");
        return true;
    }
    else
    {
        printf("this linkList had been destroied before or not been initalized!\n");
        return false;
    }
}

/**
 * @brief  addNode
 * @brief  添加链表节点
 * @param  L: 目标链表头指针
 * @retval none
 * @note   none
 */
bool addNode(LinkList L)
{
    if (L != NULL) // 先判断链表是否已经初始化，也就是头指针是否指向了头节点，未初始化Z则L==NULL
    {
        uint8_t val; // val存放新节点的值
        printf("please input a value which includes two hexadecimal members for new Node:\n");
        scanf("%hhx", &val);
        clearStdin();
        LNode *p = L;           // 创建工作指针p指向头节点
        while (p->next != NULL) // 遍历寻找next为NULL的节点，也就是尾节点
        {
            p = p->next;
        }
        p->next = malloc(sizeof(LNode)); // 创建新的节点链接到链表尾部
        p->next->val = val;
        p->next->next = NULL; // 新节点的next指向NULL
        printf("you have add a new Node successfully whose value is 0x%hhx\n", val);
        L->val += 1; // 将头节点的值(链表的长度加一)
        printf("the LinkList's length is %hhd now.\n",L->val);
        return true;
    }
    else
    {
        printf("LinkList not been initalized, please initalize LinkList first!\n");
        return false;
    }
}

/**
 * @brief  delNodeByVal
 * @brief  删除链表节点
 * @param  L: 目标链表
 * @retval 删除节点的数量
 * @note   查找并删除与目标值相同的节点，返回删除节点的数量
 */
bool delNodeByVal(LinkList L)
{
    if (L == NULL) // 判断是否已经初始化链表
    {
        printf("please initalize LinkList first!\n");
        return false;
    }
    else if (L->next == NULL) // 判断链表是否添加了数据节点
    {
        printf("please add Nodes first!\n");
        return false;
    }
    else // 初始化且添加了数据节点
    {
        uint8_t tarVal, count; // tarVal:目标数，count:目标数的数量
        LNode *p = L;          // 工作指针，用来遍历寻找目标节点
        LNode *q = NULL;       // 用来保存将要被free的节点
        printf("please input a value you want to delete,which includes two hexadecimal numbers:\n");
        scanf("%hhx", &tarVal);
        void clearStdin();
        while (p->next != NULL)
        {
            if (p->next->val == tarVal)
            {
                q = p->next;
                p->next = p->next->next;
                free(q);
                q == NULL; // q用完后及时指向NULL，避免下个函数中定义了相同的q,对q指向的地址误操作
                count++;
                L->val -= 1; // 将头节点的值(链表的长度）减一
            }
            else
            {
                p = p->next;
            }
        }
        printf("you have delete %hhu nodes whose value is 0x%hhx\n", count, tarVal);
        printf("the LinkList's length is %hhd now.\n",L->val);
        return true;
    }
}

bool delNodeBySerialNum(LinkList L)
{
    if (L == NULL) // 判断是否已经初始化链表
    {
        printf("please initalize LinkList first!\n");
        return false;
    }
    else if (L->next == NULL) // 判断链表是否添加了数据节点
    {
        printf("please add Nodes first!\n");
        return false;
    }
    else // 初始化且添加了数据节点
    {
        // 这里不能用无符号的类型来定义seNum,因为当输入负数时，无符号类型会将负数转化为正数，程序无法处理正确数据。
        int serNum;
        uint8_t temp;    // 临时保存节点的value
        LNode *p = L;    // 工作指针，用来遍历寻找目标节点
        LNode *q = NULL; // 用来保存将要被free()释放的节点
        printf("please input a serial number,which position you want to delete:\n");
        scanf("%d", &serNum);
        void clearStdin();
        if (serNum > 0) // 输入的序列号大于零且小于等于链表的长度
        {
            int woker = serNum;            // 工作计数
            while (woker > 1 && p != NULL) // 遍历到目标节点的前一个节点，p!=NULL：把链表遍历完了序列号还没到就结束循环。
            {
                p = p->next;
                woker--;
            }
            if (p != NULL) // 找到了
            {
                q = p->next;
                temp = q->val;
                p->next = p->next->next;
                free(q);
                L->val -= 1; // 将头节点的值(链表的长度）减一
                printf("the No.%d Node whose value is 0x%hhx had been deleted.\n", serNum, temp);
                printf("the LinkList's length is %hhd now.\n",L->val);
                return true;
            }
            else // 没找到
            {
                printf("the serial number you inputed is out of range\n");
                return false;
            }
        }
        else
        { // 输入序列号小于零
            printf("please inupt a positive integer!\n");
            return false;
        }
    }
}

bool findNodeByVal(LinkList L) {
    if (L == NULL) // 判断是否已经初始化链表
    {
        printf("please initalize LinkList first!\n");
        return false;
    }
    else if (L->next == NULL) // 判断链表是否添加了数据节点
    {
        printf("please add Nodes first!\n");
        return false;
    }
    else // 初始化且添加了数据节点
    {
        uint8_t tarVal,count;     // tarVal:目标数  count:找到目标数的数量
        uint8_t serNum=1;   //serNum:记录序号
        LNode *p = L->next;          // 工作指针，用来遍历寻找目标节点,指向首节点
        printf("please input a value you want to find,which includes two hexadecimal numbers:\n");
        scanf("%hhx", &tarVal);
        void clearStdin();
        while (p!= NULL)
        {
            if (p->val == tarVal)
            {
                printf("the NO.%hhu 's value is 0x%hhx.\n",serNum,tarVal);
                count++;
                p = p->next;
                serNum++;
            }
            else
            {
                p = p->next;
                serNum++;
            }
        }
        if (count==0)
        {
            printf("there is no such value which is 0x%hhx in the LinkList.\n",tarVal);
            return false;
        }else{
            printf("found %hhu target values(0x%hhx) in the LinkList.\n",count,tarVal);
            return true;
        }
    }
}

bool findNodeBySerialNum(LinkList L)
{
    if (L == NULL) // 判断是否已经初始化链表
    {
        printf("please initalize LinkList first!\n");
        return false;
    }
    else if (L->next == NULL) // 判断链表是否添加了数据节点
    {
        printf("please add Nodes first!\n");
        return false;
    }
    else // 初始化且添加了数据节点
    {
        // 这里不能用无符号的类型来定义seNum,因为当输入负数时，无符号类型会将负数转化为正数，程序无法处理正确数据。
        int serNum;
        uint8_t temp; // 临时保存节点的value
        LNode *p = L; // 工作指针，用来遍历寻找目标节点
        // LNode *q = NULL; // 用来保存将要被free()释放的节点
        printf("please input a serial number,which position you want to find:\n");
        scanf("%d", &serNum);
        void clearStdin();
        if (serNum > 0) // 输入的序列号大于零
        {
            int woker = serNum;            // 工作计数
            while (woker > 0 && p != NULL) // 遍历到目标节点，p!=NULL：把链表遍历完了序列号还没到就结束循环。
            {
                p = p->next;
                woker--;
            }
            if (p != NULL) // 找到了
            {
                printf("the No.%d Node  value is 0x%hhx.\n", serNum, p->val);
                return true;
            }
            else // 没找到
            {
                printf("the serial number you inputed is out of range\n");
                return false;
            }
        }
        else
        { // 输入序列号小于零
            printf("please inupt a positive integer!\n");
            return false;
        }
    }
}

bool changeNodeByVal(LinkList L) {
    if (L == NULL) // 判断是否已经初始化链表
    {
        printf("please initalize LinkList first!\n");
        return false;
    }
    else if (L->next == NULL) // 判断链表是否添加了数据节点
    {
        printf("please add Nodes first!\n");
        return false;
    }
    else // 初始化且添加了数据节点
    {
        uint8_t tarVal,count,resultVal;     // tarVal:改变前的数  count:找到目标数的数量 resultVal:改变后的数
        uint8_t serNum=1;   //serNum:记录序号
        LNode *p = L->next;          // 工作指针，用来遍历寻找目标节点,指向首节点
        printf("please input a value you want to change,which includes two hexadecimal numbers:\n");
        scanf("%hhx", &tarVal);
        void clearStdin();
        printf("please input a value you want to change to,which includes two hexadecimal numbers:\n");
        scanf("%hhx", &resultVal);
        void clearStdin();
        while (p!= NULL)
        {
            if (p->val == tarVal)
            {
                p->val=resultVal;
                printf("the NO.%hhu 's value is 0x%hhx,it had been changed to 0x%hhx.\n",serNum,tarVal,resultVal);
                count++;
                p = p->next;
                serNum++;
            }
            else
            {
                p = p->next;
                serNum++;
            }
        }
        if (count==0)
        {
            printf("there is no such value which is 0x%hhx in the LinkList.\n",tarVal);
            return false;
        }else{
            printf("changed %hhu target values(0x%hhx) to result values(0x%hhx) in the LinkList.\n",count,tarVal,resultVal);
            return true;
        }
    }
}

bool changeNodeBySerialNum(LinkList L) {}

/**
 * @brief  traverseLinkList
 * @brief  遍历链表节点
 * @param  L: 目标链表
 * @retval 是否遍历成功
 * @note   无
 */
bool traverseLinkList(LinkList L)
{
    if (L == NULL) // 判断是否已经初始化链表
    {
        printf("please initalize LinkList first!\n");
        return false;
    }
    else if (L->next == NULL) // 判断链表是否添加了数据节点
    {
        printf("please add Nodes first!\n");
        return false;
    }
    else // 初始化且添加了数据节点
    {
        uint8_t count = 0;
        LNode *p = L->next; // 跳过头节点，直接指向首节点
        while (p != NULL)
        {
            count++;
            printf("No.%hhu:Node's value is 0x%hhx\n", count, p->val);
            p = p->next;
        }
        printf("traverse done!\n");
        return true;
    }
}
