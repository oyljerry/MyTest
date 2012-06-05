	CC=gcc
	CFLAGS=-Wall -g -O -I /usr/local/curl/include/ -L /usr/local/curl/lib/ -l curl
	TARGET=./simple
    
    all : simple.o urlhelper.o
    	$(CC) simple.o urlhelper.o -o mycurl 
    
    simple.o : simple.c common.h
    	$(CC) -c $<
    
    urlhelper.o : urlhelper.c common.h
    	$(CC) -c $<

    