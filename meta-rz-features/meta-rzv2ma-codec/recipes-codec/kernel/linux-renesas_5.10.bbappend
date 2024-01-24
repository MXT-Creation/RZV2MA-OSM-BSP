FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/:"

SRC_URI_append_rzv2ma = " \
    file://patches/rzv2ma_patch/0012-added-mmngr-uvcs-setting-for-rzv2ma.patch \
"

