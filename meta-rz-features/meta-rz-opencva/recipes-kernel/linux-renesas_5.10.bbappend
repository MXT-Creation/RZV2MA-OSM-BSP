#
# Copyright (C) 2022 RenesasElectronics, Co, Ltd.
#
DESCRIPTION = "RZ/V2MA OpenCVA Package"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/:"

SRC_URI_append += "\
	file://0002-modified-devicetree-for-opencva-drv.patch \
"
