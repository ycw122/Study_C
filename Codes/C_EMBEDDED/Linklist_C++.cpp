#include <iostream>
#include <cstdlib>
using namespace std;
 
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;  //声明一个节点可以使用 LNode *node; LinkList L;
 
//这里的&是c++中的引用，使InitList函数直接可以操作main函数中的L，相当于在C  中使用了二级指针
bool InitList(LinkList &L)
{
    L = (LNode *) malloc(sizeof(LNode));    //分配内存
    if(L == NULL){
        return false;   //内存申请失败
    }
    L->next = nullptr;  //头节点后暂时没有节点
    return true;    //初始化成功
}

int main() {
    LinkList L; //声明一个链表
    InitList(L);    //初始化一个链表
 

    return 0;
}
