#ifndef RCC_H
#define RCC_H
#include <stdint.h>

typedef enum
{
    RCC_OK = 0,
    RCC_TIMEOUT,
    RCC_NULLPTR,
    RCC_INVALID_ARGUMENT,
    RCC_BUSY,
    RCC_NOT_READY,
    RCC_error_count
}RCC_errCode_t;


typedef enum
{
    RCC_HSI = 0,
    RCC_HSE,
    RCC_PLL,
    RCC_CLK_COUNT
}RCC_clk_t;

typedef enum
{
    RCC_DISABLE = 0,
    RCC_ENABLE,
    RCC_STATE_COUNT
}RCC_on_off_state_t;

RCC_errCode_t RCC_controlClk(RCC_clk_t Clk, RCC_on_off_state_t State);
RCC_errCode_t RCC_SelectSysClk(RCC_clk_t Clk);
#endif  /*RCC_H*/