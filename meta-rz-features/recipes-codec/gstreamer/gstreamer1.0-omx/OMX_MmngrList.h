/*
 * Copyright(C) 2023 Renesas Electronics Corporation. All Rights Reserved.
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation.
 * No part of this program may be reproduced or disclosed to
 * others, in any form, without the prior written permission
 * of Renesas Electronics Corporation.
 */
/**
 * OMX MMNGR List header
 * 
 * Header file for using MMNGR list 
 *
 * \file OMX_MmngrList.h
 * 
 */

#ifndef OMX_MMNGRLIST_H
#define OMX_MMNGRLIST_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Each OMX header must include all required header files to allow the
 *  header to compile without errors.  The includes below are required
 *  for this header file to compile successfully 
 */
#include <OMX_Core.h>

typedef struct {
    OMX_PTR pvBaseVirtAddr;
    OMX_U32 u32BaseHardIpAddr;
    OMX_PTR list_next;
    OMX_PTR list_prev;
} OMX_WORKBUFFER_ADDR_INFO;

typedef struct {
    OMX_PTR list_head;
    OMX_PTR list_end;
} OMX_WORKBUFFER_LIST_INFO;

OMX_API OMX_U32 OmxrConvertWorkBufferVirtToHard(
    OMX_PTR pvBaseVirtAddr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMX_MMNGRLIST_H */
