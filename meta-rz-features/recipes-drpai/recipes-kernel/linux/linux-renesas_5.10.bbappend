#
# Copyright (C) 2022 RenesasElectronics, Co, Ltd.
#
DESCRIPTION = "DRP-AI Support Package with kernel for RZ/V2MA Evaluation Board Kit "

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/:"

SRC_URI_append += "\
    file://0007-enable-u-dma-buf-function.patch \
    file://0008-enable-drpai-drv.patch \
    file://0009-enable-drp-drv.patch \
"
