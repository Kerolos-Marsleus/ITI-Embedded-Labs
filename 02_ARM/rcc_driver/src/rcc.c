#include <stddef.h>
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

RCC_errCode_t RCC_GetSystemClk(RCC_clk_t *Ptr_Clk){
    if(Ptr_Clk == NULL){
        return RCC_NULLPTR;
    }
    *Ptr_Clk = ((RCC->CFGR >> RCC_CFGR_SWS_POS) & RCC_CFGR_SWS_MASK);
    return RCC_OK;
}

RCC_errCode_t RCC_GetClkStatus(RCC_clk_t Clk, RCC_clkStatus_t *ptr_Status){
    if( (uint32_t) Clk >= RCC_CLK_COUNT){
        return RCC_INVALID_ARGUMENT;
    }
    if(ptr_Status == NULL){
        return RCC_NULLPTR;
    }
    *ptr_Status = ((RCC->CR) >> (RCC_On_bits[Clk]+1)) & 1U;
    return RCC_OK;
}

RCC_errCode_t RCC_CtrlPeriphClk(RCC_periph_t Periph, RCC_on_off_state_t State){
    if((uint32_t)  State >= RCC_STATE_COUNT){
    return RCC_INVALID_ARGUMENT;
    }
    volatile uint32_t *reg = NULL;
    uint32_t bus = ((uint32_t) Periph >> 5U);
    switch (bus)
    {
    case RCC_BUS_AHB1:
        reg = &RCC->AHB1ENR;
        break;
    case RCC_BUS_AHB2:
        reg = &RCC->AHB2ENR;
        break;
    case RCC_BUS_APB1:
        reg = &RCC->APB1ENR;
        break;
    case RCC_BUS_APB2:
        reg = &RCC->APB2ENR;
        break;
    
    default:
        return RCC_INVALID_ARGUMENT;
        break;
    }
    uint32_t pos = Periph & 31U;
    switch (State)
    {
    case RCC_ENABLE:
        *reg |= (1U << pos);
        break;
    case RCC_DISABLE:
        *reg &= ~(1U << pos);
        break;
    
    }
    return RCC_OK;
}


RCC_errCode_t RCC_GetResetCause(RCC_resetCause_t *Ptr_Cause){
    if(Ptr_Cause == NULL){
        return RCC_NULLPTR;
    }
    *Ptr_Cause = ((RCC->CSR) >> RCC_CSR_RSTF_POS);
    return RCC_OK;
}

RCC_errCode_t RCC_ClearResetFlags(void){
    RCC->CSR |= (1U << RCC_CSR_RMVF_POS);
    return RCC_OK;
}


RCC_errCode_t RCC_SetAHBPrescaler(RCC_ahbDiv_t Div){
    if(((uint32_t) Div != RCC_AHB_DIV1) && (((uint32_t) Div  < RCC_AHB_DIV2) || ((uint32_t) Div > RCC_AHB_DIV512))){
        return RCC_INVALID_ARGUMENT;
    }
    uint32_t temp = RCC->CFGR;
    temp &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_POS);
    temp |= ((uint32_t) Div << RCC_CFGR_HPRE_POS);
    RCC->CFGR = temp;
    return RCC_OK;
}

RCC_errCode_t RCC_SetAPBPrescaler(RCC_bus_t Bus, RCC_apbDiv_t Div){
    if(((uint32_t) Div != RCC_APB_DIV1) && (((uint32_t) Div  < RCC_APB_DIV2) || ((uint32_t) Div > RCC_APB_DIV16))){
        return RCC_INVALID_ARGUMENT;
    }
    if(Bus < RCC_BUS_APB1 || Bus > RCC_BUS_APB2){
        return RCC_INVALID_ARGUMENT;
    }
    uint32_t pos;
    switch (Bus)
    {
    case RCC_BUS_APB1:
        pos = RCC_CFGR_PPRE1_POS;
        break;
    case RCC_BUS_APB2:
        pos = RCC_CFGR_PPRE2_POS;
        break;
    default:
        break;
    }
    uint32_t temp = RCC->CFGR;
    temp &= ~(RCC_CFGR_PPRE_MASK << pos);
    temp |= ((uint32_t) Div << pos);
    RCC->CFGR = temp;
    return RCC_OK;
}

RCC_errCode_t RCC_ConfigPLL(const RCC_pllCfg_t *Ptr_CFG){
    if(Ptr_CFG == NULL){
        return RCC_NULLPTR;
    }
    if(Ptr_CFG->Q > 15 || Ptr_CFG->Q <= 1){
        return RCC_INVALID_ARGUMENT;
    }
    if(Ptr_CFG->P >= RCC_PLLP_Count){
        return RCC_INVALID_ARGUMENT;
    }
    if(Ptr_CFG->N >= 433 || Ptr_CFG->N <= 1){
        return RCC_INVALID_ARGUMENT;
    }
    if(Ptr_CFG->M > 63 || Ptr_CFG->M <= 1){
        return RCC_INVALID_ARGUMENT;
    }
    if(Ptr_CFG->src > RCC_HSE){
        return RCC_INVALID_ARGUMENT;
    }

    return RCC_OK;
}

