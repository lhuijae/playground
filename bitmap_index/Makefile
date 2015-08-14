
include ../Makefile.param

OBJPATH = obj

ARFLAGS = rcv
ARFLAGS_SO = -shared -fPIC -o
CFLAGS = -g -Wall -fPIC
CFLAGS += -O2

INC := 

COMPILE = $(CC) $(CFLAGS) $(DFLAGS) -lm

$(OBJPATH)/%.o: ./%.c
	@[ -e $(OBJPATH) ] || mkdir $(OBJPATH)
	($(COMPILE) -o $@ -c $< $(INC))

SRCS = $(wildcard ./*.c) 
OBJS = $(SRCS:%.c=%.o)
OBJS := $(OBJS:./%=obj/%)

TARGETLIB := libtest.a
TARGETLIB_SO := libtest.so

all: $(TARGETLIB)

$(TARGETLIB): $(OBJS)
	@($(AR) $(ARFLAGS) $(TARGETLIB) $(OBJS))
	@($(CC) $(ARFLAGS_SO) $(TARGETLIB_SO) $(OBJS))

clean:
	@(rm -rf $(TARGETLIB) $(TARGETLIB_SO) $(OBJS) $(OBJPATH))

