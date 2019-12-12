obj-m:=myled.o

KERDIR=/opt/EmbedSky/linux-2.6.30.4/
CURDIR=$(shell pwd)
CROSS_ARCH=ARCH=arm CROSS_CONPILE=arm-linux-

default:
	make $(CROSS_ARCH) -C $(KERDIR) SUBDIRS=$(CURDIR) modules
clean:
	make $(CROSS_ARCH) -C $(KERDIR) SUBDIRS=$(CURDIR) clean
