CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -Iinclude
TARGET = pi_controller_app
SRC = src/main.c src/fsm.c src/serial_router.c src/serial_posix.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
