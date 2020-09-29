obj-m :=inline-assembly.o                        #要生成的模块名
read_userspace-objs:= read_userspace_file.o     #生成这个模块名所需要的目标文件

#KDIR := /lib/modules/`uname -r`/build
PWD:=$(shell pwd)
KDIR := $(PWD)/../../../linux-2.6.11.12
CFLAGS += -I/usr/src/linux-headers-2.6.17-10
PWD := $(shell pwd)

default:
	make -C $(KDIR) M=$(PWD) modules -I/usr/src/linux-headers-2.6.17-10
	cp *.ko ../
clean:
	rm -rf *.o *.cmd *.ko *.mod.c .tmp_versions Module.symvers modules.order
	rm -rf ../inline-assembly.ko

