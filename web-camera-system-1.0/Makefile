################OPTION###################
CCOMPILE = arm-hisiv300-linux-gcc
#CCOMPILE = gcc
#CPPCOMPILE = g++
COMPILEOPTION = -c -O3 -DPROFILE_G_SUPPORT -DVIDEO_ANALYTICS
INCLUDEDIR = -I./include -I /usr/local/include/ -I$(HOME)/libs/opensource/hi3516a/include  -I$(HOME)/libs/bvlib/hi3516a/include \
             -L$(HOME)/libs/opensource/hi3516a/lib  -I$(HOME)/libs/bvlib/hi3516a/lib 
#-I./ffmepg-2.4.5/x86/include -L./ffmepg-2.4.5/x86/libs
#-I$(HOME)/libs/opensource/x86/include  -I$(HOME)/libs/bvlib/x86/include \
#LINK = g++
LINK = arm-hisiv300-linux-ld
#LINKOPTION = -shared -o libdavplay.so
LINKOPTION = -o web_camera_server
LIBDIRS = 
OBJS = src/dev.o src/print.o src/tcp_server.o src/yuv.o
OBJS += src/main.o
OUTPUT = web_camera_server
SHAREDLIB =  -lpthread 
APPENDLIB = 
PROC_OPTION = DEFINE=_PROC_ MODE=ORACLE LINES=true CODE=CPP
ESQL_OPTION = -g
################OPTION END################
ESQL = esql
PROC = proc
$(OUTPUT):$(OBJS) $(APPENDLIB)
	$(LINK) $(LINKOPTION) $(LIBDIRS)   $(OBJS) $(SHAREDLIB) $(APPENDLIB) 

clean: 
	rm -f $(OBJS)
	rm -f $(OUTPUT)
all: clean $(OUTPUT)
.PRECIOUS:%.cpp %.c %.C
.SUFFIXES:
.SUFFIXES:  .c .o .cpp .ecpp .pc .ec .C .cc .cxx

.cpp.o:
	$(CPPCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR)  $*.cpp
	
.cc.o:
	$(CCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR)  $*.cpp

.cxx.o:
	$(CPPCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR)  $*.cpp

.c.o:
	$(CCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR) $*.c

.C.o:
	$(CPPCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR) $*.C	

.ecpp.C:
	$(ESQL) -e $(ESQL_OPTION) $(INCLUDEDIR) $*.ecpp 
	
.ec.c:
	$(ESQL) -e $(ESQL_OPTION) $(INCLUDEDIR) $*.ec
	
.pc.cpp:
	$(PROC)  CPP_SUFFIX=cpp $(PROC_OPTION)  $*.pc
