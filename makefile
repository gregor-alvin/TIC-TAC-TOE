CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = game
SRCS = main.c eval.c helpers.c search.c
OBJS = $(SRCS:.c=.o)
DEPS = header.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean