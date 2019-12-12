obj-m:=print_out.o

KERVER=$(shell uname -r)
KERDIR=/usr/src/linux-headers-$(KERVER)
CURDIR=$(shell pwd)

all:
	make -C $(KERDIR) M=$(CURDIR) modules
clean:
	make -C $(KERDIR) M=$(CURDIR) clean
