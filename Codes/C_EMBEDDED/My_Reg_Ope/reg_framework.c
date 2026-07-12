#include "reg_framework.h"

void RegWrite8(uint8_t *reg,uint8_t val){
    *reg=val;
}

uint8_t RegRead8(uint8_t *reg){
    return *reg;
}

void Reg_BitSet8(uint8_t *reg,uint8_t bit){
    BIT_SET(*reg,bit);
}

void Reg_BitClr8(uint8_t *reg,uint8_t bit){
    BIT_CLR(*reg,bit);
}