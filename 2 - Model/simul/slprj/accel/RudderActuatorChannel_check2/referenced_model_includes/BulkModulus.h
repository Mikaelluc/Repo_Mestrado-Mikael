#include "__cf_BulkModulus.h"
#ifndef RTW_HEADER_BulkModulus_h_
#define RTW_HEADER_BulkModulus_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef BulkModulus_COMMON_INCLUDES_
#define BulkModulus_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "BulkModulus_types.h"
#include "multiword_types.h"
#include "model_reference_types.h"
#include "look2_binlxpw.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
struct gnzm2gxfr5 { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; } ; typedef struct { csza2iybqw rtm ; } ou41r25q2gt ; extern
void how1uutq1d ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , csza2iybqw *
const bjiwymxz3y , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_BulkModulus_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName ,
int_T * retVal ) ; extern mxArray * mr_BulkModulus_GetDWork ( const
ou41r25q2gt * mdlrefDW ) ; extern void mr_BulkModulus_SetDWork ( ou41r25q2gt
* mdlrefDW , const mxArray * ssDW ) ; extern void
mr_BulkModulus_RegisterSimStateChecksum ( SimStruct * S ) ; extern const
rtwCAPI_ModelMappingStaticInfo * BulkModulus_GetCAPIStaticMap ( void ) ;
extern void BulkModulus ( const real_T * c10c1ufhln , const real_T *
emdz4vngcg , const real_T * mzdc2lgcrn , real_T * nfuqgnvwsc ) ;
#endif
