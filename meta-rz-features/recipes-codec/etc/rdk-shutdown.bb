DESCRIPTION = "RDK Shutdown"
LICENSE = "CLOSED"

COMPATIBLE_MACHINE_rzv2ma = "(r9a09g055ma3gbg)"

PV="1.0"
PR="r0"

RDK_OBJ="rdk_shutdown"

# SRC file name
SRC_URI_rzv2ma = " \
	file://${RDK_OBJ} "

S_rzv2ma = "${WORKDIR}"

do_fetch[file-checksums] = ""
do_compile[noexec] = "1"
do_package_qa[noexec] = "1"

do_install() {
    cd ${S}
    # Create destination directory
    install -d ${D}/${bindir}
    install -m 755 ${S}/${RDK_OBJ} ${D}/${bindir}
}

