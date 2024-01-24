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
 * OMXR Extension header for H.265 
 * 
 * This file contains vendor-defined extension definitions.
 *
 * \file OMXR_Extension_h265.h
 * 
 */

#ifndef OMXR_EXTENSION_H265_H
#define OMXR_EXTENSION_H265_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***************************************************************************/
/*    Include Files                                                        */
/***************************************************************************/
#include "OMXR_Extension_video.h"

/***************************************************************************/
/*    Macro Definitions                                                    */
/***************************************************************************/
#define OMXR_MC_VendorBaseOffsetH265     (0x000001000)		/**< base offset for H.265 (internal use) */

#define OMXR_MC_IndexVendorBaseH265      (OMXR_MC_IndexVendorBaseVideo + OMXR_MC_VendorBaseOffsetH265)  /**< base value of extended OMX_INDEXTYPE for H.265  */
#define OMXR_MC_EventVendorBaseH265      (OMXR_MC_EventVendorBaseVideo + OMXR_MC_VendorBaseOffsetH265)  /**< base value of extended OMX_EVENTTYPE for H.265  */
#define OMXR_MC_ErrorVendorBaseH265      (OMXR_MC_ErrorVendorBaseVideo + OMXR_MC_VendorBaseOffsetH265)  /**< base value of extended OMX_ERRORTYPE for H.265  */

/** 
 * Enumeration of extended #OMX_VIDEO_HEVCPROFILETYPE 
 */
enum {
    OMXR_MC_VIDEO_HEVProfileMultiviewHigh = OMX_VIDEO_HEVCProfileVendorStartUnused,	/**< Multiview profile            */
    OMXR_MC_VIDEO_HEVProfileStereoHigh,												/**< Stereo High profile          */
    OMXR_MC_VIDEO_HEVProfileConstrainedBaseline,									/**< Constrained baseline profile */
    OMXR_MC_VIDEO_HEVProfileUnknown,												/**< unknown profile              */
    OMXR_MC_VIDEO_HEVProfileNone,                                                   /**< no profile                   */
    OMXR_MC_VIDEO_HEVProfileCustomizeStartUnused                                    /**< reserved to customize        */
};

/** 
 * Enumeration of extended #OMX_VIDEO_HEVLEVELTYPE 
 */
enum {
    OMXR_MC_VIDEO_HEVLevelUnknown = OMX_VIDEO_HEVLevelVendorStartUnused,			/**< unknown level         */
    OMXR_MC_VIDEO_HEVLevelNone,                                             		/**< no level              */
    OMXR_MC_VIDEO_HEVLevelCustomizeStartUnused                              		/**< reserved to customize */
};

/***************************************************************************/
/*    Type  Definitions                                                    */
/***************************************************************************/

/***************************************************************************/
/*    Function Prototypes                                                  */
/***************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMXR_EXTENSION_H265_H */
