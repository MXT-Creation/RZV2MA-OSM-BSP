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
 * OMXR Extension header for H.265 decoder 
 * 
 * This file contains vendor-defined extension definitions.
 *
 * \file OMXR_Extension_h265d.h
 * 
 */

#ifndef OMXR_EXTENSION_H265D_H
#define OMXR_EXTENSION_H265D_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***************************************************************************/
/*    Include Files                                                        */
/***************************************************************************/
#include "OMXR_Extension_vdcmn.h"
#include "OMXR_Extension_h265.h"

/***************************************************************************/
/*    Macro Definitions                                                    */
/***************************************************************************/
#define OMXR_MC_IndexVendorBaseH265Decoder     (OMXR_MC_IndexVendorBaseVideoDecoder + OMXR_MC_VendorBaseOffsetH265)        /**< base value of extended OMX_INDEXTYPE for H.265 decoder  */
#define OMXR_MC_EventVendorBaseH265Decoder     (OMXR_MC_EventVendorBaseVideoDecoder + OMXR_MC_VendorBaseOffsetH265)        /**< base value of extended OMX_EVENTTYPE for H.265 decoder  */
#define OMXR_MC_ErrorVendorBaseH265Decoder     (OMXR_MC_ErrorVendorBaseVideoDecoder + OMXR_MC_VendorBaseOffsetH265)        /**< base value of extended OMX_ERRORTYPE for H.265 decoder  */

#define OMXR_MC_SyntaxIndexBaseH265Decoder     (OMXR_MC_VideoSyntaxIndexBase + OMXR_MC_VendorBaseOffsetH265)

#define OMXR_MC_VIDEO_NOEL_HEV_CONST     (6u)
#define OMXR_MC_VIDEO_NOEL_HEV_NRF_POC   (255u)
#define OMXR_MC_VIDEO_NOEL_HEV_HRD       (32u)

/**
 * extended #OMX_INDEXTYPE for H.265 decoder
 */
enum {
    OMXR_MC_IndexParamVideoHevIgnoreLowDelayHint = (OMXR_MC_IndexVendorBaseH265Decoder + 0x0001)   /**< stream store unit. parameter name:OMX.RENESAS.INDEX.PARAM.VIDEO.IGNORE.LOW.DELAY.HINT */
};

enum {
    OMXR_MC_IndexConfigVideoInfoHevSyntax = (OMXR_MC_SyntaxIndexBaseH265Decoder + 0x0000)
};



/***************************************************************************/
/*    Type  Definitions                                                    */
/***************************************************************************/

/**
* sps syntax information
*/
typedef struct tagOMXR_MC_VIDEO_INFO_HEV_SPS_SYNTAX {
    OMX_U32    struct_size;
    OMXR_MC_VIDEO_SYNTAX_STATUS    status;
    OMX_PTR    reserved;
}OMXR_MC_VIDEO_INFO_HEV_SPS_SYNTAXTYPE;


/***************************************************************************/
/*    Function Prototypes                                                  */
/***************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMXR_EXTENSION_H265D_H */
