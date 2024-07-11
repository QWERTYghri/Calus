#
# Makefile:
#
# Makefile to build the calus program
#

include conf.mk

.PHONY: all clean
all: $(CALUS)

$(CALUS): ./src/Private/*.c ./src/Public/*.h ./src/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIB) $(OFLAG) -o $@ $^

clean:
	-rm *.out *.o $(CALUS)
