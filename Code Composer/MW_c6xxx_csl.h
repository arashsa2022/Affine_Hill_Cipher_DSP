/*
 * File: MW_c6xxx_csl.h
 *
 * Real-Time Workshop code generated for Simulink model stills_R_Wsdfdsgfsdhfghggfh.
 *
 * Model version                        : 1.23
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed Aug 10 05:32:20 2016
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed Aug 10 05:32:21 2016
 */

#ifndef RTW_HEADER_MW_c6xxx_csl_h_
#define RTW_HEADER_MW_c6xxx_csl_h_
#include "rtwtypes.h"
#include <c6x.h>
#include <std.h>
#include <csl.h>
#include <csl_timer.h>
#include <csl_irq.h>
#include <csl_cache.h>

extern void cslInitialize(void);
extern void disable_interrupts();
extern void enable_interrupts();
extern void targetInitialize(void);
extern void targetTerminate(void);
extern void configureTimers(void);
extern void setupCache(void);

#endif                                 /* RTW_HEADER_MW_c6xxx_csl_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
