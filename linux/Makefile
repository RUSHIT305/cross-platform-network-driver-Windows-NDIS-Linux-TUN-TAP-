CC=gcc
CFLAGS=-O2 -Wall
TARGET=tun-user

all: $(TARGET)

$(TARGET): tun-user.c
	$(CC) $(CFLAGS) -o $(TARGET) tun-user.c

clean:
	rm -f $(TARGET)
