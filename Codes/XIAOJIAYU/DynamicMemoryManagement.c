#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 内存动态管理 */
int main()
{
   int *p= NULL;
   int num;
   int count = 0;
   do
   {
       printf("请输入一个数字（输入-1退出）：");
       scanf("%d", &num);
       if (num != -1)
       {
           count ++;
           //动态分配内存，每次输入一个数字就增加一个整数的空间
		   p=(int *)realloc(p,count * sizeof(int)); //realloc函数用于重新分配内存，参数p是之前分配的内存地址，count * sizeof(int)是新的内存大小，表示需要分配count个整数的空间。realloc函数会根据新的大小重新分配内存，并返回新的内存地址，如果分配失败则返回NULL。
		   if(p==NULL){	
			   printf("内存分配失败！\n");
			   exit(1);
		   }
		   p[count-1]=num;
       }
   } while (num != -1);
   printf("您输入的数字是：");
   for (int i = 0; i < count; i++)
   {
	   printf("%d ", p[i]);
   }
   free(p);
   return 0;
}