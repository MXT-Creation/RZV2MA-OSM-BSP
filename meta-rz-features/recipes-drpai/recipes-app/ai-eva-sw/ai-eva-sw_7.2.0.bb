SUMMARY = "RZ/V2MA AI Evaluation Software"
SECTION = "app"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
	file://jpg_img/ \
	file://bmp_img/ \
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
	     install -d ${D}${APP_INSTALL_DIRECTORY}/bmp_img
	     install -d ${D}${APP_INSTALL_DIRECTORY}/jpg_img
	     install -d ${D}/usr/bin
	     install -m 0755 ${WORKDIR}/resnet50_bmp/*  ${D}${APP_INSTALL_DIRECTORY}/resnet50_bmp
	     install -m 0755 ${WORKDIR}/resnet50_cam/*  ${D}${APP_INSTALL_DIRECTORY}/resnet50_cam
	     install -m 0755 ${WORKDIR}/resnet50_jpg/*  ${D}${APP_INSTALL_DIRECTORY}/resnet50_jpg
	     install -m 0755 ${WORKDIR}/bmp_img/*  ${D}${APP_INSTALL_DIRECTORY}/bmp_img
	     install -m 0755 ${WORKDIR}/jpg_img/*  ${D}${APP_INSTALL_DIRECTORY}/jpg_img
	     install -m 0755 ${WORKDIR}/rzv_ai_eva_sw  ${D}${APP_INSTALL_DIRECTORY}
	     install -m 0755 ${WORKDIR}/start_app.sh  ${D}${APP_INSTALL_DIRECTORY}
	     install -m 0755 ${WORKDIR}/config.ini  ${D}${APP_INSTALL_DIRECTORY}
}

FILES_${PN} = " \
	${APP_INSTALL_DIRECTORY}/* \
	/usr/bin \
"
