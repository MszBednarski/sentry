TARGET = main
BAUD = 115200
AVR  = atmega328p
TYPE = arduino
FREQ = 16000000
PROGRAMMER = /dev/tty.usbmodem2201

CFLAGS  = -DF_CPU=$(FREQ) -mmcu=$(AVR) -Wall -Werror -Wextra -Os
OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

.PHONY: flash clean

all: $(TARGET).hex

%.o: %.c
	avr-gcc -c $< -o $@ $(CFLAGS)

$(TARGET).elf: $(OBJECTS)
	avr-gcc -o $@ $^ $(CFLAGS)

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -j .text -j .data -O ihex $^ $@

flash: $(TARGET).hex
	avrdude -p $(AVR) -c $(TYPE) -P $(PROGRAMMER) -b $(BAUD) -v -U flash:w:$<

clean:
	rm -f $(TARGET).hex $(TARGET).elf $(OBJECTS)