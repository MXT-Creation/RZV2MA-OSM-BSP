DESCRIPTION = "OMX Media Components RZG2"
LICENSE = "CLOSED"
require include/rzg2-modules-common.inc
require omx-package-rzv2ma.inc

COMPATIBLE_MACHINE_rzv2ma = "(r9a09g055ma3gbg)"

DEPENDS = " \
    kernel-module-mmngr mmngr-user-module \
    vspmif-user-module kernel-module-vspmif \
    kernel-module-vspm \
    drpb \
"

# Task Control. Compile is not performed when not installing OMX Video and Audio Libs.
# Note) dummy-omx-user-module.inc does not exist.
INCLUDE_FILE = '${@oe.utils.conditional("USE_OMX_COMMON", "1", "dummy", "deltask", d )}'
include ${INCLUDE_FILE}-omx-user-module.inc

DEPENDS += '${@oe.utils.conditional("USE_VIDEO_OMX", "1", "kernel-module-uvcs-drv", "", d )}'

inherit autotools

includedir = "${RENESAS_DATADIR}/include"
CFLAGS += " -I${STAGING_DIR_HOST}${RENESAS_DATADIR}/include"
PACKAGE_ARCH = "${MACHINE_ARCH}"

OMX_EVA_PREFIX = '${@oe.utils.conditional("USE_OMX_EVA_PKG", "1", "EVA", "", d )}'

# SRC file name
SRC_URI_rzv2ma = " \
	file://${OMX_PKG_TAR} "

# SRC directory name
OMX_COMMON_SRC_rzv2ma = '${@oe.utils.conditional("USE_OMX_COMMON", "1", "${OMX_EVA_PREFIX}omx_common_lib_package", "", d )}'
OMX_VIDEO_DEC_COMMON_SRC_rzv2ma = '${@oe.utils.conditional("USE_VIDEO_DEC", "1", "${OMX_EVA_PREFIX}video_dec_common_package", "", d )}'
OMX_VIDEO_ENC_COMMON_SRC_rzv2ma = '${@oe.utils.conditional("USE_VIDEO_ENC", "1", "${OMX_EVA_PREFIX}video_enc_common_package", "", d )}'
OMX_H264_DEC_SRC_rzv2ma = '${@oe.utils.conditional("USE_H264D_OMX", "1", "${OMX_EVA_PREFIX}h264_decoder_package", "", d )}'
OMX_H264_ENC_SRC_rzv2ma = '${@oe.utils.conditional("USE_H264E_OMX", "1", "${OMX_EVA_PREFIX}h264_encoder_package", "", d )}'
OMX_H265_DEC_SRC_rzv2ma = '${@oe.utils.conditional("USE_H265D_OMX", "1", "${OMX_EVA_PREFIX}h265_decoder_package", "", d )}'
OMX_H265_ENC_SRC_rzv2ma = '${@oe.utils.conditional("USE_H265E_OMX", "1", "${OMX_EVA_PREFIX}h265_encoder_package", "", d )}'

OMX_VIDEO_SRC_LIST = " \
    ${OMX_COMMON_SRC} \
    ${OMX_VIDEO_DEC_COMMON_SRC} \
    ${OMX_VIDEO_ENC_COMMON_SRC} \
    ${OMX_H264_DEC_SRC} \
    ${OMX_H264_ENC_SRC} \
"

OMX_VIDEO_SRC_LIST_append_rzv2ma = " \
    ${OMX_H265_DEC_SRC} \
    ${OMX_H265_ENC_SRC} \
"

S_rzv2ma = "${WORKDIR}/${OMX_PKG}/"

do_fetch[file-checksums] = ""
do_compile[noexec] = "1"
do_package_qa[noexec] = "1"

# Create ${S} directory
do_unpack_prepend() {
    os.system("install -d ${S}")
}

do_unpack_append_rzv2ma() {
    bb.build.exec_func('do_unpack_omx_module', d)
}
do_unpack_omx_module() {
    cd ${S}
    for omxmc in ${OMX_VIDEO_SRC_LIST}
    do
	tar xf ${S}/${omxmc}.tar.bz2
    done
}

setup_omx_package(){
    tar xf ${WORKDIR}/omx_pkg*.tar.bz2 --strip=2 -C ${WORKDIR}
    tar xf ${WORKDIR}/h264_decoder_package.tar.bz2 -C ${WORKDIR}
    tar xf ${WORKDIR}/h264_encoder_package.tar.bz2 -C ${WORKDIR}
}

setup_omx_package_append_rzv2ma(){
    tar xf ${WORKDIR}/h265_decoder_package.tar.bz2 -C ${WORKDIR}
    tar xf ${WORKDIR}/h265_encoder_package.tar.bz2 -C ${WORKDIR}
}

setup_build_tree() {
    for omxmc in ${OMX_COMMON_SRC} ${OMX_VIDEO_DEC_COMMON_SRC} ${OMX_VIDEO_ENC_COMMON_SRC}
    do
        tar xf ${WORKDIR}/${omxmc}.tar.bz2 -C ${WORKDIR}
        tar xf ${WORKDIR}/${omxmc}.tar.bz2 -C ${S} ${omxmc}/src --strip=2
        tar xf ${WORKDIR}/${omxmc}.tar.bz2 -C ${S} ${omxmc}/include --strip=1
    done
}

B = "${S}"

EXTRA_OECONF = "OMXR_DEFAULT_CONFIG_FILE_NAME=${sysconfdir}/omxr/omxr_config_base.txt"

do_install_omx_video_prepend_rzv2ma() {
    cd ${S}
    for omxmc in ${OMX_VIDEO_SRC_LIST}
    do
        install -m 755 ${S}/${omxmc}/lib/lib*.so.* ${D}/${libdir}
        install -m 644 ${S}/${omxmc}/include/*.h ${D}/${includedir}
        install -m 644 ${S}/${omxmc}/config/*.txt ${D}/${sysconfdir}/omxr
    done
}

do_install_omx_video() {
    cd ${D}/${libdir}
    if [ "X${USE_OMX_COMMON}" = "X1" ] ; then
        ln -s libomxr_core.so.3.0.0 libomxr_core.so.3
        ln -s libomxr_core.so.3 libomxr_core.so

        ln -s libomxr_mc_cmn.so.3.0.0 libomxr_mc_cmn.so.3
        ln -s libomxr_mc_cmn.so.3 libomxr_mc_cmn.so
    fi

    if [ "X${USE_VIDEO_OMX}" = "X1" ] ; then
        ln -s libomxr_mc_vcmn.so.3.0.0 libomxr_mc_vcmn.so.3
        ln -s libomxr_mc_vcmn.so.3 libomxr_mc_vcmn.so
    fi

    if [ "X${USE_VIDEO_DEC}" = "X1" ] ; then
        ln -s libomxr_mc_vdcmn.so.3.0.0 libomxr_mc_vdcmn.so.3
        ln -s libomxr_mc_vdcmn.so.3 libomxr_mc_vdcmn.so

        ln -s libuvcs_dec.so.3.0.0 libuvcs_dec.so.3
        ln -s libuvcs_dec.so.3 libuvcs_dec.so
    fi

    if [ "X${USE_VIDEO_ENC}" = "X1" ] ; then
        ln -s libomxr_mc_vecmn.so.3.0.0 libomxr_mc_vecmn.so.3
        ln -s libomxr_mc_vecmn.so.3 libomxr_mc_vecmn.so

        ln -s libuvcs_enc.so.3.0.0 libuvcs_enc.so.3
        ln -s libuvcs_enc.so.3 libuvcs_enc.so
    fi

    if [ "X${USE_H264D_OMX}" = "X1" ]; then
        ln -s libomxr_mc_h264d.so.3.0.0 libomxr_mc_h264d.so.3
        ln -s libomxr_mc_h264d.so.3 libomxr_mc_h264d.so

        ln -s libuvcs_avcd.so.3.0.0 libuvcs_avcd.so.3
        ln -s libuvcs_avcd.so.3 libuvcs_avcd.so
    fi

    if [ "X${USE_H264E_OMX}" = "X1" ]; then
        ln -s libomxr_mc_h264e.so.3.0.0 libomxr_mc_h264e.so.3
        ln -s libomxr_mc_h264e.so.3 libomxr_mc_h264e.so

        ln -s libuvcs_avce.so.3.0.0 libuvcs_avce.so.3
        ln -s libuvcs_avce.so.3 libuvcs_avce.so
    fi
}

do_install_omx_video_append_rzv2ma() {
    if [ "X${USE_OMX_COMMON}" = "X1" ] ; then
        ln -s libomxr_uvcs_udf.so.0.0.0 libomxr_uvcs_udf.so
        ln -s libomxr_videoconverter.so.3.0.0 libomxr_videoconverter.so.3
        ln -s libomxr_videoconverter.so.3 libomxr_videoconverter.so
        ln -s libomxr_utility.so.3.0.0 libomxr_utility.so.3
        ln -s libomxr_utility.so.3 libomxr_utility.so
    fi

#    if [ "X${USE_VIDEO_DEC}" = "X1" ] ; then
#        ln -s libomxr_cnvpisu.so.0.0.0 libomxr_cnvpisu.so
#    fi

    if [ "X${USE_H265D_OMX}" = "X1" ]; then
        ln -s libomxr_mc_h265d.so.3.0.0 libomxr_mc_h265d.so.3
        ln -s libomxr_mc_h265d.so.3 libomxr_mc_h265d.so

        ln -s libuvcs_hevd.so.3.0.0 libuvcs_hevd.so.3
        ln -s libuvcs_hevd.so.3 libuvcs_hevd.so
    fi

    if [ "X${USE_H265E_OMX}" = "X1" ]; then
        ln -s libomxr_mc_h265e.so.3.0.0 libomxr_mc_h265e.so.3
        ln -s libomxr_mc_h265e.so.3 libomxr_mc_h265e.so

        ln -s libuvcs_heve.so.3.0.0 libuvcs_heve.so.3
        ln -s libuvcs_heve.so.3 libuvcs_heve.so
    fi
}

do_install_audio_middleware() {
	:
}

do_install_omx_audio() {
	:
}

do_install() {
    # Create destination directory
    install -d ${D}/${libdir}
    install -d ${D}/${includedir}
    if [ "X${USE_OMX_COMMON}" = "X1" ]; then
        install -d ${D}/${sysconfdir}/omxr
    fi

    # Copy omx video library
    do_install_omx_video
}

INSANE_SKIP_${PN} = "dev-so"

FILES_${PN} += " \
    ${libdir}/*.so \
"

FILES_${PN}-dev = " \
    ${includedir} \
    ${libdir}/*.la \
"

RDEPENDS_${PN} += "mmngr-user-module vspmif-user-module drpb "

#To avoid already-stripped errors and not stripped libs from packages
INSANE_SKIP_${PN} += "already-stripped"

# Skip debug split and strip of do_package()
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
