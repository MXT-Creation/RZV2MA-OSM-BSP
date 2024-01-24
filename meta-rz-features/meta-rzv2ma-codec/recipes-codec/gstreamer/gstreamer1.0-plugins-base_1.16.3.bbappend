FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " \
	file://0001-change-stridesize-in-someformats-for-rzv2m.patch \
"