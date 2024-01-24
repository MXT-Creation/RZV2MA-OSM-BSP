PV="1.1"
PR="r0"

OMX_PRODUCT_PKG_TAR="omx_pkg_product_v0.118.tar.gz"
OMX_EVAL_PKG_TAR="omx_pkg_eval_v0.118.tar.gz"
OMX_PRODUCT_PKG="omx_pkg_product_v0.118"
OMX_EVAL_PKG="omx_pkg_eval_v0.118"

HAVE_OMX_PRODUCT="${@bb.os.path.isfile("${THISDIR}/files/${OMX_PRODUCT_PKG_TAR}")}"
OMX_PKG_TAR="${@oe.utils.conditional("HAVE_OMX_PRODUCT", "True", "${OMX_PRODUCT_PKG_TAR}", "${OMX_EVAL_PKG_TAR}", d)}"
OMX_PKG="${@oe.utils.conditional("HAVE_OMX_PRODUCT", "True", "${OMX_PRODUCT_PKG}", "${OMX_EVAL_PKG}", d)}"
