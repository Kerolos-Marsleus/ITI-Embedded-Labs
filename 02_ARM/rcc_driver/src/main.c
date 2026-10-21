#include "rcc.h"
#include <stdio.h>
int main(void){
    RCC_errCode_t error;
    char* error_str[RCC_error_count] = {
    "RCC_OK" ,
    "RCC_TIMEOUT",
    "RCC_NULLPTR",
    "RCC_INVALID_ARGUMENT",
    "RCC_BUSY",
    "RCC_NOT_READY",
};
    error = RCC_controlClk(RCC_HSE,RCC_ENABLE);
    printf("%s \n",error_str[error]);
    error = RCC_SelectSysClk(RCC_HSE);
    printf("%s \n",error_str[error]);
    error = RCC_controlClk(RCC_HSI, RCC_DISABLE);
    printf("%s \n",error_str[error]);
    error = RCC_controlClk(RCC_PLL, RCC_ENABLE);
    printf("%s \n",error_str[error]);
    error = RCC_controlClk(RCC_HSE, RCC_DISABLE);
    printf("%s \n",error_str[error]);

    RCC_clk_t Clk;
    error = RCC_GetSystemClk(&Clk);
    printf("%s \n",error_str[error]);

    RCC_clkStatus_t status;
    error = RCC_GetClkStatus(Clk,&status);
    
    RCC_periph_t periph = RCC_GPIOA;
    RCC_on_off_state_t state = RCC_ENABLE;
    error = RCC_CtrlPeriphClk(periph,state);
    printf("%s \n",error_str[error]);


    while(1){

    }
}