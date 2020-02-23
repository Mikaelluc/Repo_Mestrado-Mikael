#include "__cf_BulkModulus.h"
#ifndef _RTW_HEADER_BulkModulus_cap_host_h__
#define _RTW_HEADER_BulkModulus_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
BulkModulus_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void BulkModulus_host_InitializeDataMapInfo ( BulkModulus_host_DataMapInfo_T
* dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
