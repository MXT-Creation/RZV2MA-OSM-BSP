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
 * \file OMXR_Extension_vdcmn_error_concealmenttype.h
 */

#ifndef OMXR_EXTENSION_VDCMN_ERROR_CONCEALMENTTYPE_H
#define OMXR_EXTENSION_VDCMN_ERROR_CONCEALMENTTYPE_H

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
    OMXR_MC_IndexParamVideoErrorConcealment = (OMXR_MC_IndexVendorBaseVideoDecoder + 0x0080)   /*  OMX.RENESAS.INDEX.PARAM.VIDEO.ERROR.CONCEALMENT */
};

/***************************************************************************/
/*    Type  Definitions                                                    */
/***************************************************************************/
/**
 * Extended Error Concealment Type.
 */
typedef struct tagOMXR_MC_VIDEO_PARAM_ERROR_CONCEALMENTTYPE {
    OMX_U32            nSize;                               /**< Size of the structure */
    OMX_VERSIONTYPE    nVersion;                            /**< OMX specification version info */
    OMX_U32            nPortIndex;                          /**< Target port index */
    OMX_BOOL           bSkipInterframe;                     /**< Skip output until first valid frame has input. :     default:OMX_FALSE */
	OMX_BOOL           bSuppressErrorEventUntilValidFrame;  /**< Don't emit Error Event until first frame has input.: default:OMX_FALSE */
} OMXR_MC_VIDEO_PARAM_ERROR_CONCEALMENTTYPE;


/***************************************************************************/
/* End of module                                                           */
/***************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMXR_EXTENSION_VDCMN_ERROR_CONCEALMENTTYPE_H */

