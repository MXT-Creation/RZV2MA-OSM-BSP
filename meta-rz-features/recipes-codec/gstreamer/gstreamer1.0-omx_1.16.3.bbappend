FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/:"

SRC_URI_remove = "https://gstreamer.freedesktop.org/src/gst-omx/gst-omx-${PV}.tar.xz \
    git://anongit.freedesktop.org/gstreamer/common;destsuffix=git/common;name=common \
"

SRC_URI_append = " \
    git://github.com/renesas-rcar/gst-omx.git;branch=RCAR-GEN3e/1.16.3;name=base \
    git://anongit.freedesktop.org/git/gstreamer/common;destsuffix=git/common;name=common \
"

SRC_URI_append_rzv2ma = " \
    file://OMX_MmngrList.h \
    file://0001-update-openmax-headers.patch \
    file://0002-backport-hevc-encoder-implementation.patch \
    file://0003-add-definition-for-rzv2m.patch \
    file://0004-add-utility-function.patch \
    file://0005-rzv2m-avc-hevc-encoder-support.patch \
    file://0006-rzv2m-avc-hevc-decoder-support.patch \
    file://0007-add-gstomx.conf.patch \
    file://0008-avoid-build-error-with-OMXR_Extension_h265d.h-for-rz.patch \
    file://0009-remove-gst_omx_rzv2m_copy_data-function.patch \
    file://0010-change-split-framedata-rule-for-rzv2m.patch \
    file://0011-change-profile-tier-setting-for-rzv2m.patch \
    file://0012-change-default-value-for-rzv2m.patch \
    file://0013-rzv2m-encoder-support-I420-input.patch \
    file://0014-remove-aud-modification.patch \
    file://0015-change-split-inputdata-rule-and-num-fillthisbuffer.patch \
    file://0016-corrected-incorrect-memory-access-errors.patch \
    file://0017-handle-croppeddata-for-rzv2m.patch \
    file://0018-support-changing-port_def-setting-for-rzv2m.patch \
    file://0019-corrected-port_def-setting-error-for-rzv2m.patch \
    file://0020-change-split-framedata-rule-and-nFlags-for-rzv2m.patch \
    file://0021-split-progressive-interlace-FillThisBuffer.patch \
    file://0022-change-output-buffer-num-algorithm.patch \
    file://0023-use-drp-for-rzv2m.patch \
"

require include/rzg2-path-common.inc

DEPENDS += "omx-user-module mmngrbuf-user-module drpb"

SRCREV_base = "6db86e9434815d27de853b4c8235d098da5500a2"
SRCREV_common = "52adcdb89a9eb527df38c569539d95c1c7aeda6e"


LIC_FILES_CHKSUM = " \
    file://COPYING;md5=4fbd65380cdd255951079008b364516c \
    file://omx/gstomx.h;beginline=1;endline=22;md5=4b2e62aace379166f9181a8571a14882 \
"

S = "${WORKDIR}/git"

GSTREAMER_1_0_OMX_TARGET = "rcar"
GSTREAMER_1_0_OMX_CORE_NAME = "${libdir}/libomxr_core.so"
EXTRA_OEMESON_append = " -Dheader_path=${STAGING_DIR_TARGET}/usr/local/include"

do_configure_prepend() {
    cd ${S}
    ./autogen.sh --noconfigure
    install -d ${S}/omx/openmax/
    install -d ${D}/${includedir}
    install -m 644 ${WORKDIR}/OMX_MmngrList.h ${S}/omx/openmax/OMX_MmngrList.h
    install -m 644 ${WORKDIR}/OMX_MmngrList.h ${D}/${includedir}
    cd ${B}
}

FILES_${PN}-dev += " \
    ${includedir}/OMX_MmngrList.h \
"

RDEPENDS_${PN}_append = " omx-user-module drpb "
RDEPENDS_${PN}_remove = "libomxil"
