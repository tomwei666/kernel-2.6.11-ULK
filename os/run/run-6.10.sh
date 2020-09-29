#!/bin/bash
if [ ! -f "/etc/qemu-ifup" ]; then
	sudo cp qemu-ifup /etc
fi

if [ ! -f "/etc/qemu-ifdown" ]; then
	sudo cp qemu-ifdown /etc
fi

#sudo /home/tom/qemu/qemu-stable-0.13/i386-softmmu/qemu  -smp 2  -m 2000M  -kernel /home/tom/work/kernel-2.6.11-ULK/linux-2.6.11.12/arch/i386/boot/bzImage  -nographic -append "root=/dev/ram1 rw rootfstype=ext3 console=ttyS0 init=/linuxrc" -initrd ../rootfs-mk/ramdisk -net nic,macaddr=00:aa:00:60:00:01,model=rtl8139
sudo /home/tom/qemu/qemu-stable-0.13/i386-softmmu/qemu  -smp 2  -m 2000M  -kernel /home/tom/work/kernel-2.6.11-ULK/linux-2.6.11.12/arch/i386/boot/bzImage  -nographic -append "root=/dev/ram1 rw rootfstype=ext3 console=ttyS0 init=/linuxrc" -initrd ../rootfs-mk/ramdisk -net nic,macaddr=00:aa:00:60:00:01,model=rtl8139 -net tap,ifname=tap0
