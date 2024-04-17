RZ/V2MA - Board Support Package
==========

Description
-----------
This repo contains the Board Support Package for the RZV2MA variant by MXT Creation.
The board is based on the [RZ/V2MA Evaluation Board Kit](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/rz-mpus/rzv2ma-evkit-rzv2ma-evaluation-board-kit#overview) reference design from Renesas Electronics Corporation.

Folder structure:
* From Renesas [RTK0EF0045Z0024AZJ-v3.0.4.zip](https://www.renesas.com/us/en/document/swo/rzv-verified-linux-package-v304rtk0ef0045z0024azj-v304zip?r=1628526)
  * extra/
  * meta-gplv2/
  * meta-openembedded/
  * meta-qt5/
  * meta-renesas/
  * meta-virtualization/
  * poky/
* From Renesas:
  * [r11an0650ej0130-rzv2ma-opencv-accelerator-sp.zip](https://www.renesas.com/us/en/document/sws/rzv2ma-opencv-accelerator-support-package-version-130?r=1804066)
    * binaries/OpenCV_Bin.bin
    * meta-rz-features/meta-rz-opencva
  * binaries/Codec.bin - from [r11an0650ej0130-rzv2ma-opencv-accelerator-sp.zip](https://www.renesas.com/us/en/document/sws/rzv2ma-video-codec-package-version-097)
  * meta-rz-features/meta-rz-bootloaders - [RTK0EF0045Z90001ZJ-v1.0.0_rzv_EN.zip](https://www.renesas.com/us/en/document/sws/boot-loader-package-rzv2ma-rtk0ef0045z90001zj-v100rzvenzip?r=1628526)
  * meta-rz-features/meta-rz-drpai - from [r11an0592ej0740-rzv2ma-drpai-sp.zip](https://www.renesas.com/us/en/document/sws/rzv2ma-drp-ai-support-package-version-740?r=1730826)
  * meta-rz-features/meta-rz-opencva - from [r11an0650ej0130-rzv2ma-opencv-accelerator-sp.zip](https://www.renesas.com/us/en/document/sws/rzv2ma-opencv-accelerator-support-package-version-130?r=1804066)
  * meta-rz-features/meta-rzv2ma-codec - from [RTK0EF0131F02000SJ-v0.97.zip](https://www.renesas.com/us/en/document/sws/rzv2ma-video-codec-package-version-097)
* MXT additions
  * build/conf/ - Bitbake layers (bblayers.conf) and local.conf files
  * meta-mxt-rzv2ma/ - Layers containing kernel, BSP changes, as well as a demo application to show the DRP AI functionality

Building instructions
---------------------

Preferably on a Ubuntu 20.04, make sure these packages are installed:
```
apt-get update && apt-get install -y \
	vim tmux screen \
	gawk wget git-core git-lfs diffstat unzip texinfo \
	build-essential chrpath socat cpio python python3 python3-pip python3-pexpect \
	xz-utils debianutils iputils-ping libsdl1.2-dev xterm p7zip-full libyaml-dev \
	libssl-dev locales zstd liblz4-tool gcc-arm-linux-gnueabihf bc bison flex \
	gcc-aarch64-linux-gnu cmake ninja-build sudo lsb-release whiptail
```

Make sure Git LFS is installed (if doing this on another distro).

Then: 
* `git clone https://github.com/MXT-Creation/RZV2MA-SMARC-BSP.git`
* `cd RZV2MA-SMARC-BSP`
* `source poky/oe-init-build-env`
* `bitbake core-image-bsp`

Deploying on an SD-card
-----------------------

* Format an SD-card with 2 partitions:
  * First partition FAT (example `/dev/mmcblk0p1`)
  * Second partition ext4 (example `/dev/mmcblk0p2`)
* On the first partition, copy directly on the first level:
  * binaries/OpenCV_Bin.bin -> (partition-root)/OpenCV_Bin.bin
  * binaries/Codec_Bin.bin -> (partition-root)/Codec_Bin.bin
  * build/tmp/deploy/images/rzv2ma/Image-xxxx.bin -> (partition-root)/Image
  * build/tmp/deploy/images/rzv2ma/r9a09g055ma3gbg-evaluation-board-xxx.dtb -> (partition-root)/r9a09g055ma3gbg.dtb
* On second partition, unzip the `core-image-bsp-smarc-rzv2l-xxxxx.rootfs.tar.gz` directly on the partition
* Properly eject the SD-card
* Insert in the board

