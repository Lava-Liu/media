obj-m:=myinter.o

CONFIG_DEBUG_KERNEL=y
CONFIG_DEBUG_SLAB=y
CONFIG_DEBUG_SECTION_MISMATCH=y





KERVER=$(shell uname -r)
KERDIR=/lib/modules/$(KERVER)/build
CURDIR=$(shell pwd)

default:
	make -C $(KERDIR) M=$(CURDIR) modules
clean:
	make -C $(KERDIR) M=$(CURDIR) clean
