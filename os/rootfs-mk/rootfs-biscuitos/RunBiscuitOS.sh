#!/bin/bash

# Build system.
#
# (C) 2020.09.28 BiscuitOS <buddy.zhang@aliyun.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.

ROOT=/work/BiscuitOS/output/linux-2.6.29-i386
QEMUT=/work/BiscuitOS/output/linux-2.6.29-i386/qemu-system/qemu-system/i386-softmmu/qemu-system-i386
ARCH=x86
BUSYBOX=/work/BiscuitOS/output/linux-2.6.29-i386/busybox/busybox
OUTPUT=/work/BiscuitOS/output/linux-2.6.29-i386
ROOTFS_NAME=ext4
CROSS_COMPILE=arm-linux
FS_TYPE=ext3
FS_TYPE_TOOLS=mkfs.ext3
ROOTFS_SIZE=20
FREEZE_SIZE=4
DL=/work/BiscuitOS/dl
DEBIAN_PACKAGE=
RAM_SIZE=256
LINUX_DIR=${ROOT}/linux/linux/arch
NET_CFG=${ROOT}/package/networking
CMDLINE="root=/dev/ram0 rw rootfstype=${FS_TYPE} console=ttyS0 init=/linuxrc loglevel=8"

do_running()
{
	SUPPORT_DEBUG=N
	SUPPORT_NET=N
	[ ${1}X = "debug"X -o ${2}X = "debug"X ] && ARGS+="-s -S "
	if [ ${1}X = "net"X  -o ${2}X = "net"X ]; then
		ARGS+="-net tap "
		ARGS+="-device virtio-net-device,netdev=bsnet0,"
		ARGS+="mac=E0:FE:D0:3C:2E:EE "
		ARGS+="-netdev tap,id=bsnet0,ifname=bsTap0 "
	fi
	

	sudo ${QEMUT} ${ARGS} \
	-smp 2 \
	-cpu host \
	-enable-kvm \
	-m ${RAM_SIZE}M \
	-kernel ${LINUX_DIR}/${ARCH}/boot/bzImage \
	-initrd ${ROOT}/BiscuitOS.img \
	-nographic \
	-append "${CMDLINE}"
}


do_package()
{
	sudo cp ${BUSYBOX}/_install/*  ${OUTPUT}/rootfs/${ROOTFS_NAME} -raf
	sudo chown root.root ${OUTPUT}/rootfs/${ROOTFS_NAME}/* -R
	dd if=/dev/zero of=${OUTPUT}/rootfs/ramdisk bs=1M count=${ROOTFS_SIZE}
	${FS_TYPE_TOOLS} -F ${OUTPUT}/rootfs/ramdisk
	mkdir -p ${OUTPUT}/rootfs/tmpfs
	sudo mount -t ${FS_TYPE} ${OUTPUT}/rootfs/ramdisk \
	              ${OUTPUT}/rootfs/tmpfs/ -o loop
	sudo cp -raf ${OUTPUT}/rootfs/${ROOTFS_NAME}/*  ${OUTPUT}/rootfs/tmpfs/
	sudo umount ${OUTPUT}/rootfs/tmpfs
	gzip --best -c ${OUTPUT}/rootfs/ramdisk > ${OUTPUT}/rootfs/ramdisk.gz
	mv ${OUTPUT}/rootfs/ramdisk.gz ${OUTPUT}/BiscuitOS.img
	rm -rf ${OUTPUT}/rootfs/tmpfs
	rm -rf ${OUTPUT}/rootfs/ramdisk
}

# Lunching BiscuitOS
case $1 in
	"pack")
		# Package BiscuitOS.img
		do_package
		;;
	"debug")
		# Debugging BiscuitOS
		do_running debug
		;;
	"net")
		# Establish Netwroking
		sudo ${NET_CFG}/bridge.sh
		sudo cp -rf ${NET_CFG}/qemu-ifup /etc
		sudo cp -rf ${NET_CFG}/qemu-ifdown /etc
		;;
	*)
		# Default Running BiscuitOS
		do_running $1 $2
		;;
esac
