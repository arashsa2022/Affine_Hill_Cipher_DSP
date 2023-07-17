/*
 * File: MW_c6xxx_csl.c
 *
 * Real-Time Workshop code generated for Simulink model stills_R_Wsdfdsgfsdhfghggfh.
 *
 * Model version                        : 1.23
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed Aug 10 05:32:20 2016
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed Aug 10 05:32:21 2016
 */

#include "MW_c6xxx_csl.h"
#include "rtwtypes.h"
#include "stills_R_Wsdfdsgfsdhfghggfh.h"
#include "stills_R_Wsdfdsgfsdhfghggfh_private.h"
#include "stills_R_Wsdfdsgfsdhfghggfhcfg.h"
#include <hwi.h>

void targetInitialize(void)
{
  cslInitialize();
}

void targetTerminate(void)
{
}

TIMER_Handle hTimer1;
void configureTimers(void)
{
  Uint32 timerControl = TIMER_CTL_RMK(
    TIMER_CTL_SPND_DEFAULT,
    TIMER_CTL_INVINP_NO,
    TIMER_CTL_CLKSRC_CPUOVR8,
    TIMER_CTL_CP_PULSE,
    TIMER_CTL_HLD_YES,
    TIMER_CTL_GO_NO,
    TIMER_CTL_PWID_ONE,
    TIMER_CTL_DATOUT_0,
    TIMER_CTL_INVOUT_NO,
    TIMER_CTL_FUNC_GPIO
    );
  TIMER_Config timerCfg;
  Uint32 timerEventId;

  // Initialize control and count fields of
  // the timer configuration object
  timerCfg.ctl = timerControl;
  timerCfg.cnt = 0x0;

  // Configure timer for timer interrupt 15
  hTimer1 = TIMER_open(TIMER_DEV1, TIMER_OPEN_RESET);
  timerCfg.prd = 25000000U;
  TIMER_config(hTimer1, &timerCfg);
  timerEventId = TIMER_getEventId(hTimer1);
  IRQ_map(timerEventId, 15);
  IRQ_enable(timerEventId);
  TIMER_start(hTimer1);
}

void Timer1_ISR(Uint32 Mailbox)
{
  SEM_post( &rtClockSEM );
}

void cslInitialize(void)
{
}

/* Function: enable_interrupts -------------------------------
 *
 * Abstract:
 *      Enable the all DMA and DSP interrupts
 */
void enable_interrupts()
{
}

/* Function: disable_interrupts ------------------------------
 *
 * Abstract:
 *      Disable all DSP interrupts
 */
void disable_interrupts()
{
  IRQ_globalDisable();
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
void setupCache(void)
{
    CACHE_setL2Mode(CACHE_128KCACHE);
    CACHE_enableCaching(CACHE_EMIFA_CE00);
}
