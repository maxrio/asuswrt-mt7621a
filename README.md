# AsusWRT Xiaomi
This is version of AsusWRT that works with Xiaomi Mi routers, based on MT7621 CPU.

## Supported devices
- Xiaomi MI R3G v1 - use R3G firmware
- Xiaomi MI R3G v2 and R4A - use R4A firmware
- Xiaomi AC2100, Xiaomi Redmi AC2100 - use R2100 firmware for black (cylinder) variant and use RM2100 firmware for white (6 antennas) variant
- Xiaomi R3P - use R3P firmware
- Mi WiFi 4 - not supported now (testers needed)

## How to install
1. Download image from Releases page or build it from source
2. Flash it to a router from stock firmware or bootloader

## Installation from stock firmware
Installation process is similar to OpenWRT
- NAND flash - image needs to be split into two parts: first 4MB and the rest - first part needs to be written to kernel1 partition, the rest to rootfs0. nvram variable flag_try_sys1_failed needs to be to 1, kernel0 partition should be erased
- NOR flash - image needs to be written to OS1 partition

## Installation from bootloader
- SPI flash - image needs to be written at 0x180000 offset
- NAND flash - image needs to be written at 0x600000 offset

## How to build image from source
按照梅林编译方法。

### 首先搭建编译环境，使用ubuntu16.04  64位系统。先更新一下系统软件
sudo apt-get update
sudo apt-get upgrade

### 安装编译梅林所需要的依赖软件包
sudo apt-get install autoconf automake bash bison bzip2 diffutils file flex m4 \
g++ gawk groff-base libncurses-dev libtool libslang2 make patch perl pkg-config \
shtool subversion tar texinfo zlib1g zlib1g-dev git-core gettext libexpat1-dev \
libssl-dev cvs gperf unzip python libxml-parser-perl gcc-multilib gconf-editor \
libxml2-dev g++-5 g++-multilib gitk libncurses5 mtd-utils libncurses5-dev \
libvorbis-dev g++-5-multilib git autopoint autogen sed lib32z1-dev lib32stdc++6 \
build-essential intltool libelf1:i386 libglib2.0-dev xutils-dev libltdl7-dev libproxy-dev


### 下载完以后将文件链接到指定目录
sudo ln -s ~/asuswrt-merlin/tools/brcm /opt/brcm
sudo ln -s ~/asuswrt-merlin/release/src-rt-6.x.4708/toolchains/hndtools-arm-linux-2.6.36-uclibc-4.5.3 /opt/brcm-arm
sudo mkdir -p /media/ASUSWRT/
sudo ln -s ~/asuswrt-merlin /media/ASUSWRT/asuswrt-merlin
声明环境变量，直接执行，也可添加到.bashrc文件中(添加后需要执行source ~/.bashrc)
export PATH=$PATH:/opt/brcm/hndtools-mipsel-linux/bin:/opt/brcm/hndtools-mipsel-uclibc/bin:/opt/brcm-arm/bin



setup development system

	Broadcom SoC models
	===================

		To install the tools:
		    - copy the tools/brcm/ directory to /opt
		    - add /opt/brcm/hndtools-mipsel-linux/bin to your path
		    - add /opt/brcm/hndtools-mipsel-uclibc/bin to your path

	Broadcom HND SoC models
	=======================

		Update your environment variables as following:
		    - LD_LIBRARY_PATH=/opt/toolchains/crosstools-arm-gcc-5.3-linux-4.1-glibc-2.22-binutils-2.25/usr/lib
		    - TOOLCHAIN_BASE=/opt/toolchains
		    - PATH=/opt/toolchains/crosstools-arm-gcc-5.3-linux-4.1-glibc-2.22-binutils-2.25/usr/bin:/opt/toolchains/crosstools-aarch64-gcc-5.3-linux-4.1-glibc-2.22-binutils-2.25/usr/bin:/projects/hnd/tools/linux/hndtools-armeabi-2011.09/bin:$PATH

	### Mediatek/Ralink SoC models
	==========================

		To install the tools:
	    	    - copy the tools/brcm/ directory to /opt
		    - add /opt/brcm/hndtools-mipsel-linux/bin to your path
		    - add /opt/brcm/hndtools-mipsel-uclibc/bin to your path
		    If it is MT7621 or MT7628 chip:
	    	    - extract tools/buildroot-gcc463_32bits.tar.bz2 to /opt
		    - add /opt/buildroot-gcc463/bin to your path
		    otherwise :
	    	    - extract tools/buildroot-gcc342.tar.bz2 to /opt
		    - add /opt/buildroot-gcc342/bin to your path

		For MT7621 Uboot:
	    	    - extract mips-2012.03.tar.bz2 directory to /opt
		    - add /opt/mips-2012.03/bin to your uboot path

	Qualcomm QCA9557/QCA953x/QCA956x MIPS SoC models
	================================

		To install the tools:
		    Mesh Router:
		    - extract tools/openwrt-gcc463.mips.mesh.tar.bz2 directory to /opt
		    - add /opt/openwrt-gcc463.mips.mesh/bin to your path
		    - If you want to build small utilities out of asuswrt box,
		      add STAGING_DIR environment variable as below:

		      export STAGING_DIR=/opt/openwrt-gcc463.mips.mesh

		    Others: (For example, RT-AC55U, 4G-AC55U.)
	    	    - extract tools/openwrt-gcc463.mips.tar.bz2 directory to /opt
		    - add /opt/openwrt-gcc463.mips/bin to your path
		    - If you want to build small utilities out of asuswrt box,
		      add STAGING_DIR environment variable as below:

		      export STAGING_DIR=/opt/openwrt-gcc463.mips

	Qualcomm IPQ806x/IPQ40xx ARM SoC models
	===============================

		For example, BRT-AC828.

		To install the tools:
		    - extract tools/openwrt-gcc463.arm.tar.bz2 directory to /opt
		    - add /opt/openwrt-gcc463.arm/bin to your path
		    - If you want to build small utilities out of asuswrt box,
		      add STAGING_DIR environment variable as below:
	
		      export STAGING_DIR=/opt/openwrt-gcc463.arm

	Note: Broadcom/Ralink(except 4708 series) platform use the same toolchain for user space program, so please set PATH to the same directory as above

   4. build firmware.

	a. rt-n16
		cd release/src-rt
		make rt-n16

	b. rt-n56u
		cd release/src-ra
		make rt-n56u

	c. rt-n65u
		cd release/src-ra-3.0
		make rt-n65u

	d. rt-n14u (/ rt-ac52u / rt-ac51u / rt-n11p / rt-n54u)
		cd release/src-ra-mt7620
		make rt-n14u
		( make rt-ac52u  )
		( make rt-ac51u  )
		( make rt-n11p   )
		( make rt-n54u   )

	e. rt-ac56u (/ rt-ac68u / rt-n18uhp)
		cd release/src-rt-6.x.4708
		make rt-ac56u
		( make rt-ac68u  )
		( make rt-n18uhp )

	f. rt-ac55u (/ rt-ac55uhp )
		cd release/src-qca
		make rt-ac55u
		( make rt-ac55uhp )

	g. brt-ac828 (/ rt-ac88q / rt-ad7200 )
		cd release/src-qca-ipq8064
		make brt-ac828
		( make rt-ad7200 )

	h. rt-ac58u (/ rt-ac82u / map-ac1300 / map-ac2200 / vzw-ac1300 )
		cd release/src-qca-dakota
		make rt-ac58u
		( make rt-ac82u )
		( make map-ac1300 )
		( make map-ac2200 )
		( make vzw-ac1300 )

	i. rt-ac85u (/ rt-ac85u / rt-ac65u / rp-ac87 )
		cd release/src-ra-5010
		make rt-ac85u
		( make rt-ac65u )
		( make rp-ac87 )

	j. rt-ac1200 (/ rt-n11p_b1 / rt-n10p_v3 / rt-ac1200gu / rt-ac51u+ / rt-ac53 )
		cd release/src-ra-4300
		make rt-ac1200
		( make rt-n11p_b1 )
		( make rt-n10p_v3 )
		( make rt-ac1200gu )
		( make rt-ac51u+ )
		( make rt-ac53 )

	k. rp-ac68u (/ rp-ac53 / rp-ac55 )
		cd release/src-rtk-819x
		make rp-ac68u
		( make rp-ac53 )
		( make rp-ac55 )







1. cd release/src-ra-5010
2. make model (currently available models are: rt-mir3g, rt-mir4a, rt-rm2100, rt-r2100)

## Missing features
- No dual-wan support

## Important note
- I do not take responsibility for any damages - you do everything on your own risk
