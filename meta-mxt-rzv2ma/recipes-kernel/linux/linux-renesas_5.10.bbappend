FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append_r9a09g055ma3gbg = " \
   file://fragment-01-mxt.cfg \
   file://fragment-02-usb-ethernet.cfg \
   file://patches/0001-fix-port11-gpio-config.patch \
   file://patches/0066-mscc-ethernet-phy-add-reset-gpio.patch \
   file://patches/0071_sdhi_core_voltage_switch.patch \
"

KERNEL_MODULE_AUTOLOAD += " uvcvideo "

