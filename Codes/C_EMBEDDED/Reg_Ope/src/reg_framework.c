#include "reg_framework.h"

 volatile uint8_t reg_mem[REG_MEM_SIZE]={0};


void RegWrite8(volatile uint8_t *reg,uint8_t val){
    *reg=val;
}

uint8_t RegRead8(volatile uint8_t *reg){
    return *reg;
}

void Reg_BitSet8(volatile uint8_t *reg,uint8_t bit){
    BIT_SET(*reg,bit);
}

void Reg_BitClr8(volatile uint8_t *reg,uint8_t bit){
    BIT_CLR(*reg,bit);
}