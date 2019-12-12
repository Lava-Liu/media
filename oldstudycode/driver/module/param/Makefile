obj-m:=param.o

KERVAR=$(shell uname -r)
KERDIR=/lib/modules/$(KERVAR)/build
CURDIR=$(shell pwd)

default:
	make -C $(KERDIR) M=$(CURDIR) modules
clean:
	make -C $(KERDIR) M=$(CURDIR) clean
