USE_CODEC_DEC ?= "1"
USE_CODEC_ENC ?= "1"
USE_CODEC_DEC_H265 ?= "1"
USE_CODEC_ENC_H265 ?= "1"

require omx-control.inc

DISTRO_FEATURES_append = "${@oe.utils.conditional('USE_CODEC_DEC', '1', 'h264dec_lib', '',d)}"
DISTRO_FEATURES_append_rzv2ma = "${@oe.utils.conditional('USE_CODEC_DEC_H265', '1', 'h265dec_lib', '',d)}"
DISTRO_FEATURES_append = "${@oe.utils.conditional('USE_CODEC_ENC', '1', 'h264enc_lib', '',d)}"
DISTRO_FEATURES_append_rzv2ma = "${@oe.utils.conditional('USE_CODEC_ENC_H265', '1', 'h265enc_lib', '',d)}"

LICENSE_FLAGS_WHITELIST_append=" \
	${@bb.utils.contains("USE_VIDEO_OMX", "1", "commercial_gstreamer1.0-omx", "", d )} \
	${@bb.utils.contains("USE_VIDEO_OMX", "1", "commercial_lib32-libomxil", "", d )} \
	${@bb.utils.contains("USE_VIDEO_OMX", "1", "commercial_libomxil", "", d )} \
"

IMAGE_INSTALL_append=" \
	${@bb.utils.contains("USE_VIDEO_OMX", "1", " kernel-module-uvcs-drv ", "", d)} \
	${@bb.utils.contains("USE_VIDEO_OMX", "1", " omx-user-module ", "",d)} \
	${@bb.utils.contains("USE_VIDEO_OMX", "1", " packagegroup-gstreamer1.0-plugins ", "",d)} \
	${@bb.utils.contains("USE_VIDEO_OMX", "1", " rdk-shutdown ", "",d)} \
	${@bb.utils.contains("USE_VIDEO_OMX", "1", " drpb ", "",d)} \
	${@bb.utils.contains("USE_ORC_0.4.33", "1", " orc-0.4.33 ", "",d)} \
"
