obj-m:=myled.o

KERVIR=$(shell uname -r)
KERDIR=/lib/modules/$(KERVIR)/build
CURDIR=$(shell pwd)
CROSS_ARCH=ARCH=arm CROSS_CONPILE=arm-linux-

default:
	make -C $(KERDIR) M=$(CURDIR) modules
clean:
	make -C $(KERDIR) M=$(CURDIR) clean
