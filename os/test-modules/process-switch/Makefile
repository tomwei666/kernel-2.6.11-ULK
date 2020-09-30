obj-m :=process-switch.o                        #要生成的模块名

#KDIR := /lib/modules/`uname -r`/build
PWD:=$(shell pwd)
KDIR := /home/tom/work/kernel-2.6.11-ULK/linux-2.6.11.12/
CFLAGS += -I/usr/src/linux-headers-2.6.17-10 -g
PWD := $(shell pwd)

default:
	make -C $(KDIR) M=$(PWD) modules -I/usr/src/linux-headers-2.6.17-10
	cp *.ko ../out/
clean:
	rm -rf *.o *.cmd *.ko *.mod.c .tmp_versions Module.symvers modules.order
	rm -fr ../out/process-switch.ko
