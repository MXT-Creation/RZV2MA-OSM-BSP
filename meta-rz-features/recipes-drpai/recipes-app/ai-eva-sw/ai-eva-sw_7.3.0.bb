SUMMARY = "RZ/V2MA AI Evaluation Software"
SECTION = "app"
LICENSE = "MIT&Apache&BSD-3-Clause"
LIC_FILES_CHKSUM = " \
    file://licenses/keras-vis/LICENSE.txt;md5=7cdaa006daa053917d69f0d7154dea24 \
    file://licenses/onnx_tutorials/LICENSE.txt;md5=c594e50eac2ce59950729028841eb01c \
    file://licenses/pytorch/LICENSE.txt;md5=dfcca3a12d86473cf25a596ffe56a645 \
    file://licenses/pytorch_vision/LICENSE.txt;md5=2a5939a3a1f3f85f890e8b0488f8d426 \
"

SRC_URI = " \
	file://jpg_img/ \
	file://bmp_img/ \
    file://licenses/ \
	file://resnet50_bmp/ \
	file://resnet50_cam/ \
	file://resnet50_jpg/ \
	file://rzv_ai_eva_sw \
	file://start_app.sh \
	file://config.ini \
"

APP_INSTALL_DIRECTORY ?= "/home/root/RZV_AI_Eva_SW"


S = "${WORKDIR}"

RDEPENDS_${PN} = "jpeg"
DEPENDS = "jpeg"

do_install() {
        install -d ${D}${APP_INSTALL_DIRECTORY}/resnet50_bmp
        install -d ${D}${APP_INSTALL_DIRECTORY}/resnet50_cam
        install -d ${D}${APP_INSTALL_DIRECTORY}/resnet50_jpg
        install -d ${D}${APP_INSTALL_DIRECTORY}/licenses
        install -d ${D}${APP_INSTALL_DIRECTORY}/licenses/keras-vis
        install -d ${D}${APP_INSTALL_DIRECTORY}/licenses/onnx_tutorials
        install -d ${D}${APP_INSTALL_DIRECTORY}/licenses/pytorch
        install -d ${D}${APP_INSTALL_DIRECTORY}/licenses/pytorch_vision
        install -d ${D}${APP_INSTALL_DIRECTORY}/bmp_img
        install -d ${D}${APP_INSTALL_DIRECTORY}/jpg_img
        install -m 0755 ${WORKDIR}/resnet50_bmp/*  ${D}${APP_INSTALL_DIRECTORY}/resnet50_bmp
        install -m 0755 ${WORKDIR}/resnet50_cam/*  ${D}${APP_INSTALL_DIRECTORY}/resnet50_cam
        install -m 0755 ${WORKDIR}/resnet50_jpg/*  ${D}${APP_INSTALL_DIRECTORY}/resnet50_jpg
        install -m 0755 ${WORKDIR}/licenses/keras-vis/*  ${D}${APP_INSTALL_DIRECTORY}/licenses/keras-vis
        install -m 0755 ${WORKDIR}/licenses/onnx_tutorials/*  ${D}${APP_INSTALL_DIRECTORY}/licenses/onnx_tutorials
        install -m 0755 ${WORKDIR}/licenses/pytorch/*  ${D}${APP_INSTALL_DIRECTORY}/licenses/pytorch
        install -m 0755 ${WORKDIR}/licenses/pytorch_vision/*  ${D}${APP_INSTALL_DIRECTORY}/licenses/pytorch_vision
        install -m 0755 ${WORKDIR}/bmp_img/*  ${D}${APP_INSTALL_DIRECTORY}/bmp_img
        install -m 0755 ${WORKDIR}/jpg_img/*  ${D}${APP_INSTALL_DIRECTORY}/jpg_img
        install -m 0755 ${WORKDIR}/rzv_ai_eva_sw  ${D}${APP_INSTALL_DIRECTORY}
        install -m 0755 ${WORKDIR}/start_app.sh  ${D}${APP_INSTALL_DIRECTORY}
        install -m 0755 ${WORKDIR}/config.ini  ${D}${APP_INSTALL_DIRECTORY}
}

FILES_${PN} = " \
	${APP_INSTALL_DIRECTORY}/* \
"
