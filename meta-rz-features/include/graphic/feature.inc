RENESAS_GRAPHIC = "${@os.path.isdir("${LAYERDIR}/recipes-graphics/")}"
USE_RENESAS_GLES ?= "${@oe.utils.conditional("RENESAS_GRAPHIC", "True", '1', '0', d)}"
USE_RENESAS_OPENCL ?= "${@oe.utils.conditional("RENESAS_GRAPHIC", "True", '1', '0', d)}"

MULTI_PROVIDER_WHITELIST_append = " virtual/libegl virtual/egl virtual/libgles1 virtual/libgles2 "

USE_GLES_WAYLAND = "${@'1' if '${USE_RENESAS_GLES}' == '1' and 'wayland' in '${DISTRO_FEATURES}' else '0'}"

# For RZ/V2MA
PREFERRED_PROVIDER_virtual/libgles1_rzv2ma = "${@oe.utils.conditional('USE_RENESAS_GLES', '1', 'mali-library', 'mesa',d)}"
PREFERRED_PROVIDER_virtual/libgles2_rzv2ma = "${@oe.utils.conditional('USE_RENESAS_GLES', '1', 'mali-library', 'mesa',d)}"
PREFERRED_PROVIDER_virtual/egl_rzv2ma = "${@oe.utils.conditional('USE_RENESAS_GLES', '1', 'mali-library', 'mesa',d)}"
PREFERRED_PROVIDER_virtual/libgbm_rzv2ma = "${@oe.utils.conditional('USE_RENESAS_GLES', '1', 'mali-library', 'mesa',d)}"
PREFERRED_PROVIDER_virtual/libopencl_rzv2ma ?= "${@oe.utils.conditional('USE_RENESAS_OPENCL', '1', 'mali-library', '', d)}"
MULTI_PROVIDER_WHITELIST_append_rzv2ma = " virtual/libgbm "

IMAGE_INSTALL_append_rzv2ma = " ${@oe.utils.conditional('USE_RENESAS_OPENCL', '1', ' libopencl ', '', d)} "
BBMASK_append_rzv2ma = " recipes-graphics/PowerVR "
