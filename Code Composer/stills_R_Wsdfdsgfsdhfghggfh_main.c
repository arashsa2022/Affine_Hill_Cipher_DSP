/*
 * File: stills_R_Wsdfdsgfsdhfghggfh_main.c
 *
 * Real-Time Workshop code generated for Simulink model stills_R_Wsdfdsgfsdhfghggfh.
 *
 * Model version                        : 1.23
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed Aug 10 05:32:20 2016
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed Aug 10 05:32:21 2016
 */

#include "stills_R_Wsdfdsgfsdhfghggfh_main.h"
#include "stills_R_Wsdfdsgfsdhfghggfh.h"
#include "stills_R_Wsdfdsgfsdhfghggfh_private.h"
#include "stills_R_Wsdfdsgfsdhfghggfhcfg.h"
#include "rtwtypes.h"
#include "MW_c6xxx_csl.h"
#include "c6000_main.h"
#include <stdlib.h>
#include <stdio.h>
#define DSK_CPLD_BASE                  0x60000000
#define DSK_USER_REG                   0

/* Function: exitprocessing ----------------------------------
 *
 * Abstract:
 *      Perform various tasks at program exit.
 */
void exitprocessing()
{
  disable_interrupts();
  SYS_exit(-1);
}

void tBaseRateTSK_fcn(void)
{
  volatile boolean_T noErr;
  TSK_prolog( TSK_self() );
  noErr =
    rtmGetErrorStatus(stills_R_Wsdfdsgfsdhfghggfh_M) == NULL;
  while (noErr ) {
    /* Wait for the next timer interrupt */
    SEM_pend(&rtClockSEM, SYS_FOREVER);
    stills_R_Wsdfdsgfsdhfghggfh_step();
    noErr =
      rtmGetErrorStatus(stills_R_Wsdfdsgfsdhfghggfh_M) == NULL;
  }                                    /* while */

  SEM_post(&stopSEM);
}

void main(void)
{
  setupCache();
  LOG_printf(&LOG_MW1, "**starting the model**");

  /* Drop out of main() and enter DSP/BIOS Kernel */
}

//
// TSK prolog/epilog functions.
//
void TSK_prolog(TSK_Handle hTask)
{

#ifdef ENET_SOCKET_CALLS

  fdOpenSession( hTask );

#endif

}

void TSK_epilog(TSK_Handle hTask)
{

#ifdef ENET_SOCKET_CALLS

  fdCloseSession( hTask );

#endif

}

//
// This task is run at the highest priority. It is used to
// initialize the model and also to monitor stopping conditions.
// OS executes this task immidiately after falling out of main().
//
void initTerminateTSK_fcn(void)
{
  stills_R_Wsdfdsgfsdhfghggfh_initialize(1);
  enable_interrupts();
  configureTimers();

  /* Wait for a stopping condition. */
  SEM_pend(&stopSEM, SYS_FOREVER);

  /* We have acquired the STOP semaphore. Perform model termination. */
  /* Suspend syncronous tasks */
  {
    TSK_epilog( &tBaseRateTSK );
    TSK_setpri( &tBaseRateTSK, -1 );
  }

  LOG_printf(&LOG_MW1, "**stopping the model**");

  /* Disable rt_OneStep() here */

  /* Terminate model */
  stills_R_Wsdfdsgfsdhfghggfh_terminate();
  targetTerminate();
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
