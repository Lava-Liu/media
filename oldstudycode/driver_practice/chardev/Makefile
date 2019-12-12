obj-m:=chardev.o

KERVEL=$(shell uname -r )
KERDIR=/lib/modules/$(KERVEL)/build
CURDIR=$(shell pwd)

default:
	make -C $(KERDIR) M=$(CURDIR) modules
clean:
	make -C $(KERDIR) M=$(CURDIR) clean
