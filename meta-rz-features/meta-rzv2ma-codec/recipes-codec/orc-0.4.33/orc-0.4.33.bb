#
# This recipe adds a shared library of ORC-0.4.33 to RZ/V2MA SDK environment.
#

SUMMARY = "Optimised Inner Loop Runtime Compiler"
HOMEPAGE = "http://gstreamer.freedesktop.org/modules/orc.html"
DESCRIPTION = "Optimised Inner Loop Runtime Compiler is a Library and set of tools for compiling and executing SIMD assembly language-like programs that operate on arrays of data."
LICENSE = "BSD-2-Clause & BSD-3-Clause"
LIC_FILES_CHKSUM = "file://COPYING;md5=1400bd9d09e8af56b9ec982b3d85797e"

COMPATIBLE_MACHINE_rzv2ma = "(r9a09g055ma3gbg)"

INCLUDE_FILE = "deltask"

# SRC file name
SRC_URI_rzv2ma = " \
	file://liborc-0.4.so.0.33.0 \
	file://COPYING \
	"

S = "${WORKDIR}"

do_install() {
	install -d ${D}/${libdir}
	install -m 755 ${S}/liborc-0.4.so.0.33.0 ${D}/${libdir}
	ln -s ${S}/liborc-0.4.so.0.33.0 ${S}/liborc-0.4.so.0
}

FILES_${PN} += " \
    ${libdir}/liborc-0.4.so.0.33.0 \
    "

# Skip debug split and strip of do_package()
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
