CC = iccavr
LIB = ilibw
CFLAGS =  -IC:\Users\IEUser\Documents\MCU\3-HC595 -IC:\iccv7avr\include -IC:\iccv7avr\include -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -LC:\iccv7avr\lib -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:16 -beeprom:0.512 -fihx_coff -S2
FILES = main.o 

CLOCK:	$(FILES)
	$(CC) -o CLOCK $(LFLAGS) @CLOCK.lk   -lcatmega
main.o: .\init_devices.h C:\iccv7avr\include\iom16v.h C:\iccv7avr\include\macros.h C:\iccv7avr\include\AVRdef.h .\clock.h .\read_key.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
