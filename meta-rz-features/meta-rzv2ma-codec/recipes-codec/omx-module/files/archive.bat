@if "%1"=="" (
   echo "引数にVCDドライバのバージョン番号(ex. 27)を指定して下さい"
   exit /b
)

@set H264D=h264_decoder_package
@set H264E=h264_encoder_package
@set H265D=h265_decoder_package
@set H265E=h265_encoder_package
@set OMXLIB=omx_common_lib_package
@set VDEC=video_dec_common_package
@set VENC=video_enc_common_package

@set outdir=omx_pkg_eval_v0.
@set outdir=%outdir%%1
@md %outdir%
@set outfile=%outdir%.tar.gz
@echo 出力ファイル名 %outfile%

@tar cfj %H264D%.tar.bz2  %H264D%
@tar cfj %H264E%.tar.bz2  %H264E%
@tar cfj %H265D%.tar.bz2  %H265D%
@tar cfj %H265E%.tar.bz2  %H265E%
@tar cfj %OMXLIB%.tar.bz2 %OMXLIB%
@tar cfj %VDEC%.tar.bz2   %VDEC%
@tar cfj %VENC%.tar.bz2   %VENC%

@move %H264D%.tar.bz2  %outdir%
@move %H264E%.tar.bz2  %outdir%
@move %H265D%.tar.bz2  %outdir%
@move %H265E%.tar.bz2  %outdir%
@move %OMXLIB%.tar.bz2 %outdir%
@move %VDEC%.tar.bz2   %outdir%
@move %VENC%.tar.bz2   %outdir%

@tar cfz %outfile% %outdir%

@rd /s /q %outdir%

@echo PV="1.1"> tmp.txt
@echo PR="r0">> tmp.txt
@echo;>> tmp.txt
@echo OMX_PRODUCT_PKG_TAR="omx_pkg_product_v0.%1.tar.gz">> tmp.txt
@echo OMX_EVAL_PKG_TAR="omx_pkg_eval_v0.%1.tar.gz">> tmp.txt
@echo OMX_PRODUCT_PKG="omx_pkg_product_v0.%1">> tmp.txt
@echo OMX_EVAL_PKG="omx_pkg_eval_v0.%1">> tmp.txt
@echo;>> tmp.txt
@echo HAVE_OMX_PRODUCT="${@bb.os.path.isfile("${THISDIR}/files/${OMX_PRODUCT_PKG_TAR}")}">> tmp.txt
@echo OMX_PKG_TAR="${@oe.utils.conditional("HAVE_OMX_PRODUCT", "True", "${OMX_PRODUCT_PKG_TAR}", "${OMX_EVAL_PKG_TAR}", d)}">> tmp.txt
@echo OMX_PKG="${@oe.utils.conditional("HAVE_OMX_PRODUCT", "True", "${OMX_PRODUCT_PKG}", "${OMX_EVAL_PKG}", d)}">> tmp.txt

@nkf -Lu -d tmp.txt > ..\omx-package-rzv2ma.inc
@del tmp.txt
