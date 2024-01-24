/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Driver for the Renesas RZ/V2MA DRP unit
 *
 * Copyright (C) 2021 Renesas Electronics Corporation
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _UAPI__DRP_H
#define _UAPI__DRP_H

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif
#include <linux/ioctl.h>
#include <linux/drpai.h>

#define DRP_IO_TYPE               (47)
#define DRP_ASSIGN                _IOW (DRP_IO_TYPE, 0, drp_data_t)
#define DRP_START                 _IOW (DRP_IO_TYPE, 1, drp_data_t)
#define DRP_RESET                 _IO  (DRP_IO_TYPE, 2)
#define DRP_GET_STATUS            _IOR (DRP_IO_TYPE, 3, drp_status_t)
#define DRP_SET_SEQ               _IOW (DRP_IO_TYPE, 20, drp_seq_t)
#define DRP_GET_CODEC_AREA        _IOR (DRP_IO_TYPE, 12, drp_data_t)

#define DRP_STATUS_INIT           DRPAI_STATUS_INIT
#define DRP_STATUS_IDLE           DRPAI_STATUS_IDLE
#define DRP_STATUS_RUN            DRPAI_STATUS_RUN
#define DRP_ERRINFO_SUCCESS       DRPAI_ERRINFO_SUCCESS
#define DRP_ERRINFO_DRP_ERR       DRPAI_ERRINFO_DRP_ERR
#define DRP_ERRINFO_RESET         DRPAI_ERRINFO_RESET
#define DRP_RESERVED_NUM          DRPAI_RESERVED_NUM
#define DRP_SEQ_NUM               (20)
#define DRP_EXE_AI                (0)
#define DRP_EXE_DRP               (2)
#define DRP_DRP_NOLOAD            (0)

#ifdef __cplusplus
extern "C" {
#endif

typedef drpai_data_t drp_data_t;

typedef drpai_status_t drp_status_t;

typedef struct drp_seq
{
    uint32_t        num;
    uint32_t        order[DRP_SEQ_NUM];
    uint32_t        address;
} drp_seq_t;


#ifdef __cplusplus
}
#endif

#endif /* _UAPI__DRP_H */
