# Makefile for PD date and strftime

SRCS= date.c strftime.c
OBJS= date.o strftime.o
DOCS= date.1 strftime.3

# Uncomment the define of HAVE_TZNAME if your system has the tzname[] array.
# Uncomment the define of TM_IN_SYS_TIME if struct tm is in <sys/time.h>.
# Uncomment the define of TM_ZONE if your struct tm has the tm_zone field.
CFLAGS= -O #-DHAVE_TZNAME #-DTM_IN_SYS_TIME #-DHAVE_TM_ZONE

date: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

date.o: date.c

strftime.o: strftime.c
