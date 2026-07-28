#include  <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int8_t buffer[10]={0};
int8_t head=-1,tail=-1;
int8_t flag=0;      //head在数组内走一个循环将flag置为1；tail在数组内走一个循环将flag置为0；用来计算缓冲区长度
bool isEmpty(){
    if (head==tail&&flag==0)
    {
        return true;
    }else{
        return false;
    }
    
}

void input(){
    int8_t val;
    printf("please enter a value that you want to input to the buffer:\n");
    scanf(" %hhd",&val);    //占位符前面加一个空格，防止stdin缓冲区有字符残留。
    buffer[++head]=val;
    if (head==9)
    {
        head=-1;
        flag=1;
    }
    
}

void output()
{
    if (isEmpty == 1)
    {
        printf("buffer is empty,can not output element,input element first!\n");
    }
    else
    {
        printf("output an element ,whose value is %hhd.\n", buffer[++tail]);
        if (tail == 9)
        {
            tail = -1;
            flag = 0;
        }
    }
}


void traverseBuffer(){
    if(isEmpty==1){
         printf("buffer is empty,can not output element,input element first!\n");
    }
    else
    {
        /* code */
    }
    
}