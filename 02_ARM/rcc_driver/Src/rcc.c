#include "rcc.h"
#include "rcc_priv.h"


#define TIME_LIMIT  50000U

static const uint32_t RCC_On_bits[RCC_CLK_COUNT] = {0U, 16U, 24U};
RCC_errCode_t RCC_controlClk(RCC_clk_t Clk, RCC_on_off_state_t State){
    // error if invalid input
    if( (uint32_t) Clk >= RCC_CLK_COUNT){
        return RCC_INVALID_ARGUMENT;
    }
    if((uint32_t)  State >= RCC_STATE_COUNT){
        return RCC_INVALID_ARGUMENT;
    }

    // setting up the clock
    if((uint32_t)  State == RCC_DISABLE){
        uint32_t SWS = (RCC->CFGR >> RCC_CFGR_SWS_POS) & RCC_CFGR_SWS_MASK;
        if(SWS ==(uint32_t)  Clk){ return RCC_BUSY; }
    }
    if(State == RCC_ENABLE){
        RCC->CR |= (1U << RCC_On_bits[Clk]);
        //waiting for the clock to be ready
        uint32_t timeout = TIME_LIMIT;
        uint32_t mask = (1U << (RCC_On_bits[Clk] + 1U));
        while(((RCC->CR & mask) == 0) && (timeout > 0U)){
            timeout--;
        }
        if((RCC->CR & mask) == 0){
            return RCC_TIMEOUT;
        }
    }else{
        RCC->CR &= ~(1U << RCC_On_bits[Clk]);
    }


    return RCC_OK;
}

RCC_errCode_t RCC_SelectSysClk(RCC_clk_t Clk){
    if( (uint32_t) Clk >= RCC_CLK_COUNT){
        return RCC_INVALID_ARGUMENT;
    }

    uint32_t mask = (1U << (RCC_On_bits[Clk] + 1U));
    if((RCC->CR & mask) == 0){
        return RCC_NOT_READY;
    }
    uint32_t temp = RCC->CFGR;
    temp &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_pos);
    temp |= ((uint32_t) Clk << RCC_CFGR_SW_pos);
    RCC->CFGR = temp;

    uint32_t timeout = TIME_LIMIT;
    
    while((((RCC->CFGR >> RCC_CFGR_SWS_POS) & RCC_CFGR_SWS_MASK) != (uint32_t) Clk) && (timeout > 0U)){
        timeout--;
    }
    if((((RCC->CFGR >> RCC_CFGR_SWS_POS) & RCC_CFGR_SWS_MASK) != (uint32_t) Clk)){
        return RCC_TIMEOUT;
    }


    return RCC_OK;

}



