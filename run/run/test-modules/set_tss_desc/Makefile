obj-m :=set_tss_desc.o                        #要生成的模块名

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
	rm -fr ../set_tss_desc.ko
