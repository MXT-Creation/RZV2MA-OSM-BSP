#
# Copyright (C) 2022 RenesasElectronics, Co, Ltd.
#
DESCRIPTION = "DRP-AI Support Package with kernel for RZ/V2MA Evaluation Board Kit "

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/:"

SRC_URI_append += "\
    file://0008-enable-drpai-drv.patch \
    file://0010-modified-devicetree-for-drpai-drp.patch \
    file://1000-WA-available-v4l2-memory-userptr.patch \
"
