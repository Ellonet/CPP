msg=Default message

CC = g++
CCFLAGS = -c -Wall -std=c++14
LDFLAGS = -lm

# add your .cpp files here  (no file suffixes)
CLASSES = TimeChecker Complex

# Prepare object and source file list using pattern substitution func.
OBJS = $(patsubst %, %.o,  $(CLASSES))
SRCS = $(patsubst %, %.c, $(CLASSES))

all: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) Matrix.hpp -o timeChecker
	./timeChecker 500

%.o: %.c
	$(CC) $(CCFLAGS) $*.c

Matrix:
	$(CC) $(CCFLAGS) Matrix.hpp

depend:
	makedepend -- $(CCFLAGS) -- $(SRCS)
# DO NOT DELETE

clean:
	rm -f *.o timeChecker Matrix.hpp.gch
push:
	git add -A
	git commit -m "$(msg)"
	git push

tar:
	tar -cvf ex3.tar Matrix.hpp TimeChecker.cpp README Makefile

