/*   Do *not* directly modify this file.  It was    */
/*   generated by the Configuration Tool; any  */
/*   changes risk being overwritten.                */

/* INPUT stills_R_Wsdfdsgfsdhfghggfh.cdb */

/*  Include Header Files  */
#include <std.h>
#include <hst.h>
#include <swi.h>
#include <tsk.h>
#include <log.h>
#include <sem.h>
#include <sts.h>

#ifdef __cplusplus
extern "C" {
#endif

extern far HST_Obj RTA_fromHost;
extern far HST_Obj RTA_toHost;
extern far SWI_Obj KNL_swi;
extern far TSK_Obj TSK_idle;
extern far TSK_Obj initTerminateTSK;
extern far TSK_Obj tBaseRateTSK;
extern far LOG_Obj LOG_system;
extern far LOG_Obj LOG_MW1;
extern far SEM_Obj rtClockSEM;
extern far SEM_Obj stopSEM;
extern far STS_Obj IDL_busyObj;


#ifdef __cplusplus
}
#endif /* extern "C" */
