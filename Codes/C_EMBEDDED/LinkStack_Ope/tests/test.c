#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


int main(){
    uint8_t a=-1;
    printf("format -1 in uint8_t is %hhu\n",a);
    printf("format -1 in int8_t is %hhd\n",(int8_t)a);
}