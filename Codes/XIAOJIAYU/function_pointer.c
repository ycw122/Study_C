#include <stdio.h>
#include <stdint.h>

typedef void (*CarCallBack) (uint16_t);

void SpeedAlarm(uint16_t speed){
    if (speed>144)
    {
        /* code */
        printf("your car speed is %d km/h,you have out of highiy limited speed(144km/h), please slow down!\n",speed);
    }
    else
    {
        /* code */
        printf("your car speed is %d km/h,your speed is in laws\n",speed);
    }
}

void DriveCar(uint16_t val, CarCallBack cb){
    if (cb!=NULL)
    {
        cb(val);
    }
    
}

int main(){
    DriveCar(145,SpeedAlarm);
    DriveCar(144,SpeedAlarm);
    DriveCar(168,SpeedAlarm);
    DriveCar(93,SpeedAlarm);
    return 0;
}