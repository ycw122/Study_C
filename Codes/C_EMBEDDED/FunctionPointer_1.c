#include <stdio.h>



int add(int a, int b){return a+b;}
int subtract(int a, int b){return a-b;}
int multiplication(int a, int b){return a*b;}
int division(int a, int b){return a/b;}

int (*p)(int a, int b);

int main(){
    int m,n;
    char c;
    printf("please input an operator,like + _ * / \n");
    scanf("%c",&c);
     if (c=='+')
    {
        p=add;
        /* code */
    }else if (c=='-')
    {
        p=subtract;
        /* code */
    }else if (c=='*')
    {
        p=multiplication;
        /* code */
    }else if (c=='/')
    {
        p=division;
        /* code */
    }else{
        printf("please input an corrcet operator!\n");
        return 0;
    }
    printf("please input two numbers\n");
    scanf("%d %d",&m,&n);
    if (p==division&&m<=0)
    {
        printf("the first number must be an positive number!\n");
        return 0;
    }
    /* 
    printf("result = %d\n",p(m,n));
    printf("address of add is %p\n",add);
    printf("address of subtract is %p\n",subtract);
    printf("address of multiplation is %p\n",multiplication);
    printf("address of divison is %p\n",division);
    printf("content of pointer p is %p\n",p);
    printf("address of pointer p is %p\n",&p); 
    */ 
    return 0;
    
}