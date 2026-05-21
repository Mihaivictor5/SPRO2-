CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
INCLUDES = -I../pi_controller/include
SRC = mock/test_fsm_smoke.c ../pi_controller/src/fsm.c ../pi_controller/src/serial_router.c
TARGET = test_fsm_smoke

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
