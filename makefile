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

clean:
	rm -f $(OBJS) $(OUTPUT)

fresh:
	make clean
	make