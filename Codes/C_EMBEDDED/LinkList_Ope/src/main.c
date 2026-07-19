#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    LinkList L=NULL;
    initLinkList(&L);
    for (uint8_t i = 0; i < 3; i++)
    {
        addNode(L);
    }
    traverseLinkList(L);
    destroyLinkList(&L);
    return 0;
}
