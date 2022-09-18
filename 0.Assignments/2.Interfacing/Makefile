#Main application file name

MAIN_APP = blink

#Main hex file path in windows format 
MAIN_HEX_PATH =	$(MAIN_APP).hex

# Compiler and other Section 
CC = avr-gcc
OBJCOPY = avr-objcopy.exe
AVRDUDE := avrdude -C "C:\WinAVR-20100110\bin\avrdude.conf"

#Options for avr-gcc
CFLAGS = -g -Os -o

#Linking options for avr-gcc 
LFLAGS = -Os -mmcu=atmega16 -o

#Options for HEX file generation 
HFLAGS = -j .text -j .data -O ihex

#Options for avrdude to burn the hex file
#MMCU model here according to avrdude options
DUDEFLAGS = -c
DUDEFLAGS += avrisp
DUDEFLAGS += -p
DUDEFLAGS += m328p
DUDEFLAGS += -P
DUDEFLAGS += COM3
DUDEFLAGS += -b
DUDEFLAGS += 19200
DUDEFLAGS += -U flash:w:$(MAIN_HEX_PATH):i

# build directories
BIN = bin
OBJ = obj
SRC = src

# Sources files needed for building the application
SRC = $(MAIN_APP).c
# add all the source files in project using wildcard
SRC +=  $(wildcard $(SRC)/*.c )

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c)) 

# The headers files needed for building the application
INCLUDE = -I.

INCLUDE += header/$(wildcard *.h)

# commands Section Burn :
burn: $(MAIN_APP).hex
	$(AVRDUDE) $(DUDEFLAGS)

# commands Section Clean :
clean:
	rm -f *.o *.hex *.elf

# commands Section Build :
build: $(MAIN_APP).elf
	$(OBJCOPY) $(HFLAGS) $(MAIN_APP).elf $(MAIN_APP).hex

# commands Section Build :
$(MAIN_APP).elf: $(MAIN_APP).o
	$(CC) $(LFLAGS) $(MAIN_APP).elf $(SRC) $(INCLUDE)

# ------------------------------------

Build : $(MAIN_APP).elf
	$(OBJCOPY) $(HFLAGS) $< $(MAIN_APP).hex

$(MAIN_APP).elf: $(OBJECTS)
	$(CC) $(SRC) $(INCLUDE) $(LFLAGS) $@

$(OBJECTS):	$(SRC)
	$(CC) $^ $(INCLUDE) $(CFLAGS) $@