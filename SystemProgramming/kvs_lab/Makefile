SRCS = static_main.c
LIBSRCS = open.c close.c put.c get.c 
TARG = kvs_static

CC = gcc
OPTS = -Wall -O
LIBS = -L. -lkvs

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a


all: 

static: $(TARG)

$(TARG) : $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) 

$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG)
