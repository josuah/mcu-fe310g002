LDFLAGS = -Wl,-Map=firmware.map
CFLAGS = -Os -g -Wall -Wextra #-std=c99 -pedantic
CPPFLAGS = -DGD32VF103C_START -I. -IInclude

OBJ = main.o
ZMCU = ../..
include ${ZMCU}/lib/libzmcu.gd32vf103.mk

all: firmware.elf firmware.asm

ocd:
	${OPENOCD}

gdb:
	${GDB} -x script.gdb
