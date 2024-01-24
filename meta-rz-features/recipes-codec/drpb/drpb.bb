#
# This recipe adds a shared library and a header file of DRP-B driver to RZ/V2MA SDK environment.
#

SUMMARY = "DRPB library"
LICENSE = "CLOSED"

COMPATIBLE_MACHINE_rzv2ma = "(r9a09g055ma3gbg)"

# SRC file name
SRC_URI_rzv2ma = " \
	file://libdrp_api.so \
    file://drp_api.h "

S = "${WORKDIR}"

do_install() {
	install -d ${D}/${libdir}
    install -d ${D}/${includedir}
	install -m 755 ${S}/libdrp_api.so ${D}/${libdir}
    install -m 644 ${S}/drp_api.h ${D}/${includedir}
}

FILES_${PN} += " \
    ${libdir}/libdrp_api.so \
    "

FILES_${PN}-dev = " \
    ${includedir}/drp_api.h \
"

# Skip debug split and strip of do_package()
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"