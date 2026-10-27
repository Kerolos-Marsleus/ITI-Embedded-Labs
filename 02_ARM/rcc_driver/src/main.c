#include "rcc.h"
#include "gpio.h"
#include <stdio.h>

#define GPIOC_BASE      0x40020800U
#define GPIOA_BASE      0x40020000U

#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00U))
#define GPIOA_PUPDR     (*(volatile uint32_t *)(GPIOA_BASE + 0x0C))
#define GPIOA_IDR       (*(volatile uint32_t *)(GPIOA_BASE + 0x10))

#define GPIOC_MODER     (*(volatile uint32_t *)(GPIOC_BASE + 0x00U))
#define GPIOC_BSRR      (*(volatile uint32_t *)(GPIOC_BASE + 0x18))
int main(void){
    RCC_errCode_t error;

    error = RCC_enuPeriphClkCtrl(RCC_GPIOC, RCC_ENABLE);
    error = RCC_enuPeriphClkCtrl(RCC_GPIOA, RCC_ENABLE);

    GPIO_enuCfgPinMode(GPIO_PORTC, GPIO_PIN13,GPIO_MODE_OUTPUT);

    GPIO_enuCfgPinMode(GPIO_PORTA,GPIO_PIN0, GPIO_MODE_INPUT);
    GPIOA_PUPDR |= (1U << 0);
    GPIOA_PUPDR &= ~(1U << 1);

    GPIO_enuCfgSpeed(GPIO_PORTC,GPIO_PIN13, GPIO_SPEED_HIGH);
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

