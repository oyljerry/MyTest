CC=gcc
CFLAGS= -I /usr/local/curl/include/ -I /usr/local/log4c/include \
        -L /usr/local/curl/lib/ -L /usr/local/log4c/lib/ -l curl -l log4c
    
main:urlhelper.o simple.o
	$(CC) $(CFLAGS) -o mytest simple.o urlhelper.o 
        
urlhelper.o: urlhelper.c common.h logger.h
	$(CC) $(CFLAGS) -c urlhelper.c -o urlhelper.o

simple.o: simple.c common.h logger.h
	$(CC) $(CFLAGS) -c simple.c -o simple.o 
	
clean:
	rm simple.o urlhelper.o mytest

    