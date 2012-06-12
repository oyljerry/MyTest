CC=gcc
CFLAGS= -Wall -g
CINCFOLER= -I /usr/local/curl/include/ -I /usr/local/log4c/include
CLIBFOLDER= -L /usr/local/curl/lib/ -L /usr/local/log4c/lib/
CLDLIB=-l curl -l log4c

SOURCES=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SOURCES))
    
main:$(OBJS)
	$(CC) $(CFLAGS) $(CLIBFOLDER) $(CLDLIB) -o mytest $(OBJS) 
        
#urlhelper.o: urlhelper.c common.h logger.h
#	$(CC) $(CFLAGS) $(CINCFOLER) -c urlhelper.c -o urlhelper.o

#simple.o: simple.c common.h logger.h
#	$(CC) $(CFLAGS) $(CINCFOLER) -c simple.c -o simple.o

%.o:%.c
	 $(CC) $(CFLAGS) $(CINCFOLER) -c $< -o $@
	
clean:
	rm *.o mytest

    