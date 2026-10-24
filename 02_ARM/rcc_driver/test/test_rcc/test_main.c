#include <string.h>
#include "unity.h"
#include "rcc.h"
#include "rcc_priv.h"

RCC_Reg_t g_fakeRCC;

// it run before every test 
// so we make sure the software mimic the hardware
void setUp(void)
{
    memset(&g_fakeRCC, 0, sizeof(g_fakeRCC));  // all registers are 0
    g_fakeRCC.CR = (1U << 0) | (1U << 1);       // HSION + HSIRDY : SHIP BOOTS ON HSI
    g_fakeRCC.PLLCFGR = 0x24003010U;        // default value from RM
}

void tearDown(void)
{
    // run after every test
    // it is empty because there is nothing need to clean but unity require it
}

void test_controlClk_rejects_invalid_clock(void)
{
    TEST_ASSERT_EQUAL(RCC_INVALID_ARGUMENT, RCC_controlClk((RCC_clk_t) 7 , RCC_ENABLE));
    // TEST ASSERT (EXPECTED , ACTUAL)
    // IF DIFFER UNITY PRINT FAIL
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_controlClk_rejects_invalid_clock);
    return UNITY_END();
}