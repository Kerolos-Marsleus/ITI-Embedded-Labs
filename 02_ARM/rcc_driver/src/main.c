#include "rcc.h"
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

    GPIOC_MODER |= (1U << 26);
    GPIOC_MODER &= ~(1U << 27);

    GPIOA_MODER &= ~(3U << 0);
    GPIOA_PUPDR |= (1U << 0);
    GPIOA_PUPDR &= ~(1U << 1);

    while(1){
        // GPIOC_BSRR = (1U << (13U + 16U));
        // for(volatile uint32_t i = 0U; i < 500000U; i++){}

        // GPIOC_BSRR = (1U << 13U);
        // for(volatile uint32_t i = 0U; i < 500000U; i++){}

        if(GPIOA_IDR & (1)){
            GPIOC_BSRR = (1U << 13U);
        }else{
            GPIOC_BSRR = (1U << (13U + 16U));
        }
    
    }
}