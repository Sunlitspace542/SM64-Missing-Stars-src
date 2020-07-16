#
# Standard N64 Makefile
#

# Name!
PRJNAME = mario64
PARTS = $(PRJNAME).o

# Vars
INC_FLAGS = -I. -I../include
LIB_FLAGS = -L. -T mario64.x
ROOT = ..
N64ROOT = $(ROOT)/root
N64PREFIX = mips64-
N64BIN = ${N64ROOT}/bin

# Flags
NOBUILTIN=-fno-builtin
CFLAGS=-std=gnu99 -nodefaultlibs -march=vr4300 -mtune=vr4300 -mabi=32 ${INC_FLAGS}  $(NOBUILTIN) -o3
ASFLAGS = -march=vr4300 -mabi=32
LINK_FLAGS=${LIB_FLAGS} ${LIBS}

# Programs
CC      = mips64-gcc
LD      = mips64-ld
OBJCOPY = mips64-objcopy
CHEAT   = nemucheat
BINCODE = bin2code

# Awwright
all: $(PRJNAME).bin
	$(BINCODE) $(PRJNAME).bin 80400000 codes.txt # Turn binary into GS code
	cat hook.txt codes.txt | $(CHEAT) "Mario 64" 1 > final.txt # Turn into Nemu cheat

$(PRJNAME).bin: $(PRJNAME).elf
	$(OBJCOPY) $(PRJNAME).elf $(PRJNAME).bin -O binary

$(PRJNAME).elf: $(PARTS)
	$(LD) -o $(PRJNAME).elf	$(PARTS) $(LINK_FLAGS) 
	
clean:
	rm *.o *.elf *~ *.bin final.txt codes.txt -vf
