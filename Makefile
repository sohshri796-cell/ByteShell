CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
TARGET = ByteShell

SRCS = src/main.c src/commands.c src/shell.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

.PHONY: all clean