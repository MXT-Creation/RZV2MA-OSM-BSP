DESCRIPTION = "A minimal xen image"

INITRD_IMAGE = "core-image-minimal-initramfs"

IMAGE_INSTALL += " \
    packagegroup-core-boot \
    packagegroup-core-ssh-openssh \
    ${@bb.utils.contains('MACHINE_FEATURES', 'acpi', 'kernel-module-xen-acpi-processor', '', d)} \
    kernel-module-xen-blkback \
    kernel-module-xen-gntalloc \
    kernel-module-xen-gntdev \
    kernel-module-xen-netback \
    ${@bb.utils.contains('MACHINE_FEATURES', 'pci', "${XEN_PCIBACK_MODULE}", '', d)} \
    kernel-module-xen-wdt \
    xen-tools \
    qemu \
    "

# The hypervisor may not be within the dom0 filesystem image but at least
# ensure that it is deployable:
do_build[depends] += "xen:do_deploy"

# Networking for HVM-mode guests (x86/64 only) requires the tun kernel module
IMAGE_INSTALL_append_x86    = "kernel-module-tun"
IMAGE_INSTALL_append_x86-64 = "kernel-module-tun"

# Linux kernel option CONFIG_XEN_PCIDEV_BACKEND depends on X86
XEN_PCIBACK_MODULE = ""
XEN_PCIBACK_MODULE_x86    = "kernel-module-xen-pciback"
XEN_PCIBACK_MODULE_x86-64 = "kernel-module-xen-pciback"

LICENSE = "MIT"

inherit core-image

do_check_xen_state() {
    if [ "${@bb.utils.contains('DISTRO_FEATURES', 'xen', ' yes', 'no', d)}" = "no" ]; then
        die "DISTRO_FEATURES does not contain 'xen'"
    fi
}

addtask check_xen_state before do_rootfs

syslinux_iso_populate_append() {
	install -m 0444 ${STAGING_DATADIR}/syslinux/libcom32.c32 ${ISODIR}${ISOLINUXDIR}
	install -m 0444 ${STAGING_DATADIR}/syslinux/mboot.c32 ${ISODIR}${ISOLINUXDIR}
}

syslinux_hddimg_populate_append() {
	install -m 0444 ${STAGING_DATADIR}/syslinux/libcom32.c32 ${HDDDIR}${SYSLINUXDIR}
	install -m 0444 ${STAGING_DATADIR}/syslinux/mboot.c32 ${HDDDIR}${SYSLINUXDIR}
}

grubefi_populate_append() {
	install -m 0644 ${DEPLOY_DIR_IMAGE}/xen-${MACHINE}.gz ${DEST}${EFIDIR}/xen.gz
}

syslinux_populate_append() {
	install -m 0644 ${DEPLOY_DIR_IMAGE}/xen-${MACHINE}.gz ${DEST}/xen.gz
}

SYSLINUX_XEN_ARGS ?= "loglvl=all guest_loglvl=all console=com1,vga com1=115200,8n1"
SYSLINUX_KERNEL_ARGS ?= "ramdisk_size=32768 root=/dev/ram0 rw console=hvc0 earlyprintk=xen console=tty0 panic=10 LABEL=boot debugshell=5"

build_syslinux_cfg () {
	echo "ALLOWOPTIONS 1" > ${SYSLINUX_CFG}
	echo "DEFAULT boot" >> ${SYSLINUX_CFG}
	echo "TIMEOUT 10" >> ${SYSLINUX_CFG}
	echo "PROMPT 1" >> ${SYSLINUX_CFG}
	echo "LABEL boot" >> ${SYSLINUX_CFG}
	echo "  KERNEL mboot.c32" >> ${SYSLINUX_CFG}
	echo "  APPEND /xen.gz ${SYSLINUX_XEN_ARGS} --- /vmlinuz ${SYSLINUX_KERNEL_ARGS} --- /initrd" >> ${SYSLINUX_CFG}
}

# Enable runqemu. eg: runqemu xen-image-minimal nographic slirp
WKS_FILE_x86-64 = "directdisk-xen.wks"
QB_MEM = "-m 400"
QB_DEFAULT_KERNEL = ""
QB_DEFAULT_FSTYPE = "wic"
QB_FSINFO = "wic:kernel-in-fs"
# qemux86-64 machine does not include 'wic' in IMAGE_FSTYPES, which is needed
# to boot this image, so add it here:
IMAGE_FSTYPES_qemux86-64 += "wic"
# Networking: the qemuboot.bbclass default virtio network device works ok
# and so does the emulated e1000 -- choose according to the network device
# drivers that are present in your dom0 Linux kernel. To switch to e1000:
# QB_NETWORK_DEVICE = "-device e1000,netdev=net0,mac=@MAC@"
