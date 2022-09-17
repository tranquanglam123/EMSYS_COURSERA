#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#SOme general flags for both platforms
G_FLAGS= \
		-Wall\
		-Werror\
		-O0\
		-g\
		-std=c99
		
TARGET=c1m2
#Conditional check
ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	SOURCES+= 	./interrupts_msp432p401r_gcc.c\
			./startup_msp432p401r_gcc.c\
			./system_msp432p401r.c
	INCLUDES+= 	-I ../include/msp432/ \
			-I ../include/CMSIS/
	
	#COmpilers
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE=arm-none-eabi-size
	LINKER_FILE=../msp432p401r.lds
	CFLAGS = 	$(G_FLAGS)\
			-mcpu=$(CPU)\
			-mthumb\
			-march=$(ARCH)\
			-mfpu=fpv4-sp-d16\
			--specs=$(SPECS)
	#Preprocessing
	CPPFLAGS= -DMSP432 $(INCLUDES)
	#LInker FLags
	LDFLAGS= -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
else
	CC = gcc
	CFLAGS=$(G_FLAGS)
	CPPFLAGS= -DHOST $(INCLUDES)
	SIZE=size
endif
PREP=$(SOURCES:.c=.i)
DEP=$(SOURCES:.c=.d)
ASM=$(SOURCES:.c=.asm)
OBJS=$(SOURCES:.c=.o)
.PHONY: compile-all build clean
build: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
#Generate the preprocessed output of all c-program implementation files (use the –E flag).
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@
#Generate assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -O $@
#Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@
#Generate dependencies files
%.d: %.c
	$(CC) -E -M $< $(CFLAGS) $(CPPFLAGS) -o $@
compile-all: $(OBJS)
clean:
	#Remove all output files created by make
	#@echo or some shit
	rm -f *.o *.asm *.out *.i *.map
 


