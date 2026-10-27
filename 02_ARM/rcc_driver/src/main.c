#include "rcc.h"
#include "gpio.h"
#include <stdio.h>

int main(void){
    RCC_errCode_t rcc_error;
    const GPIO_pinCfg_t LED_pin = 
    {
        .port = GPIO_PORTC,
        .pin  = GPIO_PIN13,
        .mode = GPIO_MODE_OUTPUT,
        .outType = GPIO_OUTPUT_PUSH_PULL,
        .speed = GPIO_SPEED_LOW,
        .pupd = GPIO_PUPD_NONE,
        .af = GPIO_AF0,
        .initState = GPIO_PIN_STATE_HIGH
    };
    
    rcc_error = RCC_enuPeriphClkCtrl(RCC_GPIOC, RCC_ENABLE);
    rcc_error = RCC_enuPeriphClkCtrl(RCC_GPIOA, RCC_ENABLE);

    GPIO_enuCfgPinMode(GPIO_PORTA,GPIO_PIN0, GPIO_MODE_INPUT);
    GPIO_enuCfgPUPD(GPIO_PORTA, GPIO_PIN0, GPIO_PUPD_UP);
    GPIO_enuCfgAlternativeFunc(GPIO_PORTA, GPIO_PIN10, GPIO_AF7);
    rcc_error = GPIO_enuPinInit(&LED_pin);
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

