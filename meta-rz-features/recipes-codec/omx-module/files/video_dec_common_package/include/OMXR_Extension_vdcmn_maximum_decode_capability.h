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
 * \file OMXR_Extension_vdcmn_maximum_decode_capability.h
 */

#ifndef OMXR_EXTENSION_VDCMN_MAXIMUM_DECODE_CAPABILITY_H
#define OMXR_EXTENSION_VDCMN_MAXIMUM_DECODE_CAPABILITY_H

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
    OMXR_MC_IndexParamVideoMaximumDecodeCapability = (OMXR_MC_IndexVendorBaseVideoDecoder + 0x0082)   /*  OMX.RENESAS.INDEX.PARAM.VIDEO.MAXIMUM.DECODE.CAPABILITY */
};

/***************************************************************************/
/*    Type  Definitions                                                    */
/***************************************************************************/

#define OMXR_MC_VIDEO_PARAM_MAXIMUM_DECODE_CAPABILITY_MAXIMUM_LEVEL ( 0xFFFFFFFFu )    /**< The value of the maximum level for eMaxLevel */

/**
 * Extended Muximum Decode Capability.
 */
typedef struct tagOMXR_MC_VIDEO_PARAM_MAXIMUM_DECODE_CAPABILITY {
    OMX_U32         nSize;              /**< Size of the structure */
    OMX_VERSIONTYPE nVersion;           /**< OMX specification version info */
    OMX_U32         nPortIndex;         /**< Target port index */
    OMX_U32         nMaxDecodedWidth;   /**< Max width : default:1920(Full HD) / Set range w | 80 <= w <= 1920 ( 4096 if support 4K resolution ) */
    OMX_U32         nMaxDecodedHeight;  /**< Max height: default:1088(Full HD) / Set range h | 80 <= h <= 1920 ( 4096 if support 4K resolution ) */
    OMX_U32         eMaxLevel;          /**< Max level : default:OMXR_MC_VIDEO_PARAM_MAXIMUM_DECODE_CAPABILITY_MAXIMUM_LEVEL */
    OMX_BOOL        bForceEnable;       /**< If specified OMX_TRUE, ensure sufficient memory in order to decode with the given parameters.
                                             Otherwise, there's possibility of the memory shortage if the image size is changed during decoding.

                                              - The maximum value of OMX_VIDEO_PORTDEFINITIONTYPE.nSliceHeight is 1152 if all of the following conditions are satisfied:
                                                - bForceEnable == OMX_TRUE
                                                - OMXR_MC_VIDEO_PARAM_DEINTERLACE_MODETYPE.eDeinterlace == OMXR_MC_VIDEO_DeinterlaceNone,

                                              - The memory arrangement format is described in below if all of the following conditions are satisfied:
                                                - H264D
                                                - bForceEnable == OMX_TRUE
                                                - OMXR_MC_VIDEO_PARAM_DEINTERLACE_MODETYPE.eDeinterlace == OMXR_MC_VIDEO_DeinterlaceNone

                                              The memory arrangement changes according to the OMX_VIDEO_PORTDEFINITIONTYPE.eColorformat, as shown in the figures below:

                                              \image html YUV420_Planar_field.png "OMX_VIDEO_PORTDEFINITIONTYPE.eColorformat==OMX_COLOR_FormatYUV420Planar" 

                                              \image html YUV420_SemiPlanar_field.png "OMX_VIDEO_PORTDEFINITIONTYPE.eColorformat==OMX_COLOR_FormatYUV420SemiPlanar"
                                        */
} OMXR_MC_VIDEO_PARAM_MAXIMUM_DECODE_CAPABILITYTYPE;

/***************************************************************************/
/* End of module                                                           */
/***************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMXR_EXTENSION_VDCMN_MAXIMUM_DECODE_CAPABILITY_H */

