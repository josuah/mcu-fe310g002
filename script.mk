OBJCOPY = llvm-objcopy
OBJDUMP = llvm-objdump
CPP = clang-cpp
CC = clang --target=riscv32-unknown-elf -march=rv32imac -mabi=ilp32
AS = llvm-as --target=riscv32-unknown-elf -march=rv32imac -mabi=ilp32
LD = llvm-link --target=riscv32-unknown-elf -march=rv32imac -mabi=ilp32
AR = llvm-ar
GDB = riscv64-unknown-elf-gdb
SDK_OBJ = ${SDK}/init.o
SDK_CFLAGS = -ffunction-sections -fdata-sections
SDK_LDFLAGS = -Map=firmware.map --gc-sections -T${SDK}/script.ld -nostdlib -static
SDK_CPPFLAGS = -I${SDK}
SDK_ASFLAGS = -I${SDK}

all: firmware.elf firmware.asm

clean:
	rm -f *.[os] ${SDK}/*.[os] *.asm *.elf *.map *.hex *.bin *.uf2

ocd:
	${OPENOCD}

gdb:
	${GDB} -x ${SDK}/script.gdb

flash.avrdude: firmware.hex
	${AVRDUDE} -qu -P ${PORT} -U flash:w:firmware.hex

flash.dfuutil: firmware.bin
	${DFUUTIL} -D firmware.bin

flash.mount: firmware.uf2
	mount /mnt && cp firmware.uf2 /mnt

flash.openocd: firmware.hex
	${OPENOCD} -c 'program firmware.hex verify reset exit'

firmware.elf: ${SDK_OBJ} ${OBJ}
	${LD} ${SDK_LDFLAGS} ${LDFLAGS} -o $@ ${SDK_OBJ} ${OBJ}

.SUFFIXES: .c .s .S .o .elf .bin .asm .hex .uf2

.c.o:
	${CC} ${SDK_CPPFLAGS} ${CPPFLAGS} ${SDK_CFLAGS} ${CFLAGS} -c -o $@ $<

.S.s:
	${CPP} ${SDK_CPPFLAGS} ${CPPFLAGS} -o $@ $<

.s.o:
	${AS} ${SDK_CPPFLAGS} ${CPPFLAGS} ${SDK_ASFLAGS} ${ASFLAGS} -c -o $@ $<

.elf.asm:
	${OBJDUMP} -z -d $< >$@

.elf.hex:
	${OBJCOPY} -j .text -j .data -O ihex $< $@

.elf.bin:
	${OBJCOPY} -j .text -j .data -O binary $< $@

.elf.uf2:
	elf2uf2 $< $@
