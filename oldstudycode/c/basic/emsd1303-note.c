
/usr/include/stdio.h

man gcc

-Iinclude

export C_INCLUDE_PATH=./include

预处理： 展开头文件 / 替换宏定义
gcc -Iinclude -E  src/sum.c -o  sum.i

编译：   语法错误检查并编译成汇编代码
gcc -Iinclude -S  src/sum.i -o  sum.s

汇编:    汇编成二进制指令
gcc -c  sum.s  -o   obj/sum.o
gcc -c  src/main.c -o obj/main.o

objdump -d obj/main.o 可以进行反汇编

链接：  把不同模块的代码内存地址链接到一起
gcc obj/sum.o obj/main.o -o bin/main

执行：  ./bin/main
-----------------------------------

gcc  -Wall src/main.c src/sum.c -o bin/sum


静态库:
^^gcc -Iinclude -c src/sum.c -o obj/sum.o
^^ar -rc ./lib/libsum.a obj/sum.o
^^gcc -Iinclude src/main.c lib/libsum.a -o bin/main    :今晚测试直接将.c文件打包成库文件 ，and 测试当第一步将头文件打包进去之后在调用库的时候是否仍然需要讲头文件包含。



^^./bin/main 
优点：
缺点：编译时会把库中的源代码直接插入调用程序中
     造成 代码体积庞大
     
     库每次修改替换后，调用者都要重新编译

共享库：
gcc -Iinclude -fPIC -shared -o ./lib/libsum.so
src/sum.c (obj/sum.o)

gcc -Iinclude src/main.c -L./lib -lsum -o
bin/main

./bin/main

优点：
     在程序运行的时候只装入内存一次，程序要调用
     库中的功能 则会跳到该库的入口执行
     
     库每次更新替换后，不需要重新编译，重新链接即可

     ldd  bin/main (分析该程序依赖的库文件)
     
     1. export LD_LIBRARY_PATH=./lib
     
     2. sudo cp  ./lib/libsum.so  /lib
     
     3. 
        --cd /etc/ld.so.conf.d/
        --vi libc.conf 或 touch  mylib.conf
        --把自己应用程序使用库的绝对路径名添加上去
        --ldconfig 是配置文件生效(当然也可以重启机器实现这个效果)

动态库
       void *dlopen(const char *filename, int flag);

       char *dlerror(void);

       void *dlsym(void *handle, const char *symbol);

       int dlclose(void *handle);

GNU/Linux   GNU工具链
shell
gcc/g++

make   Makefile  自动化编译工具

gdb 调试工具
gcc -g -Iinclude src/main.c  src/sum.c -o bin/sum
gdb bin/sum
.........
    :
     执行shell中的命令：比如：  shell clear
     打断点:       b  main/行号
     查看断点：    info beak
     删除断点：    delete  n(断点编号)   
     开始执行程序： r  (running) 
     查看源程序：   l  (list)
     下一步：     
       下一条指令,跳过函数内部：  n (next) 
        可以进入函数内部执行：    s (step)
     打印变量的值： p (print)
     跳到下一个断点: continue
     跳到某一行：  until  











