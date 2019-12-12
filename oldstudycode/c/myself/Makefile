#use for build a share lib

bin/test1_1:lib/libtest1.so
	gcc -Llib -ltest1 -o bin/test1_1

lib/libtest1.so: src/test1.c
	gcc -fPIC -shared -o lib/libtest1.so src/test1.c



