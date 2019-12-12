obj-m:=export1.o

KERVER=$(shell uname -r)
KERDIR=/usr/src/linux-headers-$(KERVER)
CURDIR=$(shell pwd)

default:
	make -C $(KERDIR) M=$(CURDIR) modules
clean:
	make -C $(KERDIR) M=$(CURDIR) clean
