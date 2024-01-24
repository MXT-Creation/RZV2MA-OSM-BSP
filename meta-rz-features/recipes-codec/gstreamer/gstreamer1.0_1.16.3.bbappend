FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append = " \
	file://0001-fix-return-more-data-error-in-pull_range.patch \
	file://0002-fix-NULL-the-lists-of-contexts-in-dispose.patch \
"