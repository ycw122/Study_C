#include <stdio.h>

int max(int m,int n){
    return m>n?m:n;
}

// 此处注意在函数指针前面加上typedef后，Pointer就不是一个具体的函数指针，而是一个函数指针类型
typedef int (*Pointer)(int x,int y);

int main(){
    int a=4,b=10,c=6;
// 这里定义的p才是一个具体的函数指针    Pointer = max为错误定义。
    Pointer p=max;
    int d=p(a,p(b,c));
    printf("the biggest number is %d\n",d);
    return 0;
}