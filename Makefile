# Makefile for PD date and strftime

SRCS= date.c strftime.c
OBJS= date.o strftime.o
DOCS= date.1 strftime.3

date: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

date.o: date.c

strftime.o: strftime.c
