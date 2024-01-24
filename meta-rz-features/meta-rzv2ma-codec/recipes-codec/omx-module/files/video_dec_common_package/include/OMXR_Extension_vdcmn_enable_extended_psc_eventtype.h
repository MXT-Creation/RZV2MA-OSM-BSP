/*
 * Copyright(C) 2015-2018 Renesas Electronics Corporation. All Rights Reserved.
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation.
 * No part of this program may be reproduced or disclosed to
 * others, in any form, without the prior written permission
 * of Renesas Electronics Corporation.
 */
/**
 * OMXR Extension header for video decoder common
 * 
 * This file contains vendor-defined extension definitions.
 *
 * \file OMXR_Extension_vdcmn_enable_extended_psc_eventtype.h
 */

#ifndef OMXR_EXTENSION_VDCMN_ENABLE_EXTENDED_PSC_EVENTTYPE_H
#define OMXR_EXTENSION_VDCMN_ENABLE_EXTENDED_PSC_EVENTTYPE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***************************************************************************/
/*    Include Header Files                                                 */
/***************************************************************************/
#include "OMXR_Extension_vdcmn.h"

/***************************************************************************/
/*    Macro Definitions                                                    */
/***************************************************************************/
/**
 * extended #OMX_INDEXTYPE for Video decoder
 */
enum {
    OMXR_MC_IndexParamVideoEnableExtendedPSCEvent = (OMXR_MC_IndexVendorBaseVideoDecoder + 0x0081)  /* OMX.RENESAS.INDEX.PARAM.VIDEO.ENABLEEXTENDEDPSCEVENT */
};


/***************************************************************************/
/*    Type  Definitions                                                    */
/***************************************************************************/
/**
  * Extended PortSettingChanged Event Type. 
*/
typedef struct tagOMXR_MC_VIDEO_PARAM_ENABLE_EXTENDED_PSC_EVENTTYPE {
    OMX_U32                       nSize;            /**< Size of the structure */
    OMX_VERSIONTYPE               nVersion;         /**< OMX specification version info */
    OMX_U32                       nPortIndex;       /**< Target port index */
    OMX_BOOL                      bEnable;          /**< Enable notification of Extended PSC event : default:OMX_FALSE */
} OMXR_MC_VIDEO_PARAM_ENABLE_EXTENDED_PSC_EVENTTYPE;


/***************************************************************************/
/* End of module                                                           */
/***************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMXR_EXTENSION_VDCMN_ENABLE_EXTENDED_PSC_EVENTTYPE_H */
