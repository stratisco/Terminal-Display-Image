CC = gcc
CFLAGS = -Wall -pedantic -MMD -MP

BUILD = .build
OUTPUT = dimg

SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c,$(BUILD)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

$(BUILD):
	mkdir -p $@

$(BUILD)/%.o: src/%.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(BUILD) $(OUTPUT)

.PHONY: all clean