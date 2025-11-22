CC = gcc
CFLAGS = -Wall -pedantic
OUTPUT = dimg

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o ./$(OUTPUT) $(OBJS) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean-all:
	rm -f $(OBJS) $(OUTPUT)

clean:
	rm -f $(OBJS)

fresh:
	make clean-all
	make