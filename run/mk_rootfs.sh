#!/bin/bash
sudo rm -rf rootfs
sudo rm -rf tmpfs
sudo rm -rf ramdisk*
sudo mkdir rootfs
sudo cp /home/tom/kernel1/kernel1/busybox-1.10.4/_install/* rootfs/ -raf
sudo mkdir -p rootfs/proc/
sudo mkdir -p rootfs/sys/
sudo mkdir -p rootfs/tmp/
sudo mkdir -p rootfs/root/
sudo mkdir -p rootfs/var/
sudo mkdir -p rootfs/mnt/
sudo cp ext/* rootfs/var/
sudo cp etc rootfs/ -arf
sudo cp test/out/* rootfs/var/
sudo mkdir -p rootfs/lib
#sudo cp -arf /lib/* rootfs/lib/
sudo cp -arf /lib/lib* rootfs/lib/
sudo cp -arf /lib/ld* rootfs/lib/
sudo rm -f rootfs/lib/*.a
sudo strip rootfs/lib/*
sudo mkdir -p rootfs/dev/
sudo mknod rootfs/dev/tty1 c 4 1
sudo mknod rootfs/dev/tty2 c 4 2
sudo mknod rootfs/dev/tty3 c 4 3
sudo mknod rootfs/dev/tty4 c 4 4
sudo mknod rootfs/dev/console c 5 1
sudo mknod rootfs/dev/null c 1 3
sudo mknod rootfs/dev/ram b 1 1
sudo dd if=/dev/zero of=ramdisk bs=1M count=32
sudo mkfs.ext3 -F ramdisk
sudo mkdir -p tmpfs
sudo mount -t ext3 ramdisk ./tmpfs/  -o loop
sudo cp -raf rootfs/*  tmpfs/
sudo umount tmpfs




