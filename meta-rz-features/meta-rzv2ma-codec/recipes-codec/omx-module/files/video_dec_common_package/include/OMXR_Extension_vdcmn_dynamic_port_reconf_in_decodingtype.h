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
 * \file OMXR_Extension_vdcmn_dynamic_port_reconf_in_decodingtype.h
 */

#ifndef OMXR_EXTENSION_VDCMN_DYNAMIC_PORT_RECONF_IN_DECODINGTYPE_H
#define OMXR_EXTENSION_VDCMN_DYNAMIC_PORT_RECONF_IN_DECODINGTYPE_H

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
    OMXR_MC_IndexParamVideoDynamicPortReconfInDecoding = (OMXR_MC_IndexVendorBaseVideoDecoder + 0x0083)  /* OMX.RENESAS.INDEX.PARAM.VIDEO.DYNAMIC.PORTRECONF.INDECODING */
};


/***************************************************************************/
/*    Type  Definitions                                                    */
/***************************************************************************/
/**
 * Extended Dynamic Port Reconf In Decoding Type.
 * - If the IL client has set the bEnable of "Dynamic Port Reconf in Decoding" index to TRUE, 
 *   Media Component notifies the PortSettingChanged Event in accordance with the change of the output port information, 
 *   and wait for the re-configuration of the port.
 * - Please the IL client processes a sequence of "Dynamic Port Reconfiguration" prescribed in OpenMAX IL standard.
 * - The output port information after the change will apply after PortDisable.
 * - The target output port information is nFrameWidth, nFrameHeight, nStride, nSliceHeight.
 *   nStride and nSliceHeight must not set it to 0 with this mode.
 */
typedef struct tagOMXR_MC_VIDEO_PARAM_DYNAMIC_PORT_RECONF_IN_DECODINGTYPE {
    OMX_U32                       nSize;            /**< Size of the structure */
    OMX_VERSIONTYPE               nVersion;         /**< OMX specification version info */
    OMX_U32                       nPortIndex;       /**< Target port index */
    OMX_BOOL                      bEnable;          /**< Enable dynamic port re-configuration in decoding : default:OMX_FALSE */
} OMXR_MC_VIDEO_PARAM_DYNAMIC_PORT_RECONF_IN_DECODINGTYPE;


/***************************************************************************/
/* End of module                                                           */
/***************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMXR_EXTENSION_VDCMN_DYNAMIC_PORT_RECONF_IN_DECODINGTYPE_H */
