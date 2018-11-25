OBJECTS=main.o led.o timer.o switch.o uart.o

GCC_DIR = /usr/bin
SUPPORT_FILE_DIRECTORY = /usr/include

DEVICE 	= msp430g2553
CC			= $(GCC_DIR)/msp430-gcc
GDB			= $(GCC_DIR)/msp430-gdb

CFLAGS = -I $(SUPPORT_FILE_DIRECTORY) -mmcu=$(DEVICE) -O2 -g
LFLAGS = -L $(SUPPORT_FILE_DIRECTORY)

all: $(OBJECTS)
		$(CC) $(CFLAGS) $(LFLAGS) $? -o $(DEVICE).out

debug: all
		$(GDB) $(DEVICE).out
