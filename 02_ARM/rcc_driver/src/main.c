#include "rcc.h"
#include "gpio.h"
#include <stdio.h>

int main(void){
    RCC_errCode_t error;

    error = RCC_enuPeriphClkCtrl(RCC_GPIOC, RCC_ENABLE);
    error = RCC_enuPeriphClkCtrl(RCC_GPIOA, RCC_ENABLE);

    GPIO_enuCfgPinMode(GPIO_PORTC, GPIO_PIN13,GPIO_MODE_OUTPUT);

    GPIO_enuCfgPinMode(GPIO_PORTA,GPIO_PIN0, GPIO_MODE_INPUT);
    GPIO_enuCfgPUPD(GPIO_PORTA, GPIO_PIN0, GPIO_PUPD_UP);
    

    GPIO_enuCfgSpeed(GPIO_PORTC,GPIO_PIN13, GPIO_SPEED_LOW);
    while(1){

        GPIO_pinState_t state;
        GPIO_enuPinRead(GPIO_PORTA,GPIO_PIN0,&state);
        if(state){
            GPIO_enuPinWrite(GPIO_PORTC,GPIO_PIN13, GPIO_PIN_STATE_HIGH);
        }else{
            GPIO_enuPinWrite(GPIO_PORTC,GPIO_PIN13, GPIO_PIN_STATE_LOW);
        }
    
    }
}

