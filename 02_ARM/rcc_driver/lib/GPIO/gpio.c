#include "gpio.h"
#include "gpio_priv.h"
#include <stddef.h>




static GPIO_Reg_t *const GPIO_ports[GPIO_PORT_COUNT] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOH};

GPIO_errCode_t GPIO_enuCfgPinMode(GPIO_port_t port, GPIO_pin_t pin, GPIO_mode_t mode){
    GPIO_errCode_t error;
    if((uint32_t) port >= GPIO_PORT_COUNT){
        error = GPIO_INVALID_ARGUMENT;
    }else if( (uint32_t) pin >= GPIO_PIN_COUNT){
        error = GPIO_INVALID_ARGUMENT;
    }else if((uint32_t) mode >= GPIO_MODE_COUNT){
        error = GPIO_INVALID_ARGUMENT;
    }else{  
        uint32_t loc_u32_temp = GPIO_ports[port]->MODER;
        uint32_t loc_u32_pos = (uint32_t) pin * GPIO_2BIT_FIELD_WIDTH;
        loc_u32_temp &= ~(GPIO_MODER_MASK << loc_u32_pos);
        loc_u32_temp |= ((uint32_t)mode << loc_u32_pos);
        GPIO_ports[port]->MODER = loc_u32_temp;
        error = GPIO_OK;
    }

    return error;
}

GPIO_errCode_t GPIO_enuPinWrite(GPIO_port_t port, GPIO_pin_t pin,GPIO_pinState_t state){
    GPIO_errCode_t error;
    if((uint32_t) port >= GPIO_PORT_COUNT){
        error = GPIO_INVALID_ARGUMENT;
    }else if( (uint32_t) pin >= GPIO_PIN_COUNT){
        error = GPIO_INVALID_ARGUMENT;
    }else if((uint32_t) state >= GPIO_PIN_STATE_COUNT){
        error = GPIO_INVALID_ARGUMENT;
    }else{
        if((uint32_t)state == GPIO_PIN_STATE_HIGH){
            // BSRR is write only so reading it will return 0s
            GPIO_ports[port]->BSRR = (1U << (uint32_t)pin);
        }else{
            GPIO_ports[port]->BSRR = (1U << ((uint32_t)pin  + GPIO_BSRR_RESET_OFFSET));
        }
        error = GPIO_OK;
    }
    return error;
}

GPIO_errCode_t GPIO_enuPinRead(GPIO_port_t port, GPIO_pin_t pin, GPIO_pinState_t* state){
    GPIO_errCode_t error;
    if((uint32_t) port >= GPIO_PORT_COUNT){
        error = GPIO_INVALID_ARGUMENT;
    }else if( (uint32_t) pin >= GPIO_PIN_COUNT){
        error = GPIO_INVALID_ARGUMENT;
    }else if(state == NULL){
        error = GPIO_NULLPTR;
    }else{
        *state = (GPIO_pinState_t)((GPIO_ports[port]->IDR >> (uint32_t)pin) & GPIO_IDR_MASK);
        error = GPIO_OK;
    }
    return error;
}



