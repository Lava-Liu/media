obj-m:=charllseek.o

KERVER=$(shell uname -r)
KERDIR=/lib/modules/$(KERVER)/build
CURDIR=$(shell pwd)

default:
	make -C $(KERDIR) M=$(CURDIR) modules
clean:
	make -C $(KERDIR) M=$(CURDIR) clean
