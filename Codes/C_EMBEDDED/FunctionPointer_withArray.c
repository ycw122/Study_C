#include <stdio.h>
#include<malloc.h>

typedef float (*Calculate)(float a, float b);

float add(float a,float b){
    return a+b;
}

float subtract(float a,float b){
    return a-b;
}

float multiplication(float a,float b){
    return a*b;
}

float division(float a,float b){
    return a/b;
}

int main(){
    float m=4,n=2;
    Calculate cals[4]={add, subtract, multiplication, division};
    for (int i = 0; i < sizeof(cals)/sizeof(cals[0]); i++)
    {
        /* code */
        printf("result of cal[%d] is %f\n",i,cals[i](m,n));
    }    
    
    return 0;
}