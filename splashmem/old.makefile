# makefile
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -g2 -fPIC  # -DDEBUG
LDFLAGS= -ldl -lSDL3
EXE=splashmem

all: players $(OBJS)
	@echo $(SRCS) 
	gcc  $(OBJS) $(LDFLAGS) -o $(EXE)

players:
	cd players && $(MAKE) -f old.Makefile

clean_pl:
	cd players && $(MAKE) -f old.Makefile clean

clean_all: clean_pl clean 
	@echo "Done"

clean: 
	rm -f core
	rm -f *.a
	rm -f *.so
	rm -f $(OBJS)
	rm -f $(EXE)
