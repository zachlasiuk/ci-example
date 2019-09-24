# Armv8-M Security Extensions Example Makefile
#
# Copyright (c) 2017 Arm Limited (or its affiliates). All rights reserved.
# Use, modification and redistribution of this file is subject to your possession of a
# valid End User License Agreement for the Arm Product of which these examples are part of 
# and your compliance with all applicable terms and conditions of such licence agreement.
#
# This makefile is intended for use with GNU make
# This example is intended to be built with Arm Compiler 6

TARGET=IOTKit_ARMv8MBL

CC=armclang
AS=armasm
LD=armlink
AR=armar
FE=fromelf

# Select build rules based on Windows or Unix
ifdef WINDIR
WINPATH=$(subst /,\,$(1))
DONE=@if exist $(call WINPATH,$(1)) echo Build completed.
RM=if exist $(call WINPATH,$(1)) del /q $(call WINPATH,$(1))
MD=if not exist $(call WINPATH,$(1)) mkdir $(call WINPATH,$(1))
SHELL=$(WINDIR)\system32\cmd.exe
else
ifdef windir
WINPATH=$(subst /,\,$(1))
DONE=@if exist $(call WINPATH,$(1)) echo Build completed.
RM=if exist $(call WINPATH,$(1)) del /q $(call WINPATH,$(1))
MD=if not exist $(call WINPATH,$(1)) mkdir $(call WINPATH,$(1))
SHELL=$(windir)\system32\cmd.exe
else
DONE=@if [ -f $(1) ]; then echo Build completed.; fi
RM=rm -f $(1)
MD=@if [ ! -d $(1) ]; then mkdir $(1); fi
endif
endif

.PHONY: all tests build_test build_prod clean 

CFLAGS = -xc -std=c11 --target=arm-arm-none-eabi -march=armv8m.base -c -funsigned-char -fshort-enums -fshort-wchar -g -O1 -Weverything -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command -Wno-documentation
INCLUDES  = -I ./src -I ./unity -I ./Common -I ./RTE  -I ./RTE/Device/IOTKit_ARMv8MBL  -D_RTE_ -DIOTKit_ARMv8MBL
LFLAGS = --strict --info=summarysizes --map --xref --callgraph --symbols --info=unused --info=veneers

all: tests build_test build_prod

tests:
	ruby unity/generate_test_runner.rb tests/test_mycode.c tests/runners/test_mycode_runner.c --main_name="mainTest"

build_test:
	$(call MD,./Objects)
	$(AS) --cpu=8-m.base -g --pd="_RTE_ SETA 1" --pd="IOTKit_ARMv8MBL SETA 1" ./RTE/Device/IOTKit_ARMv8MBL/startup_IOTKit_ARMv8MBL.s -o ./Objects/startup_IOTKit_ARMv8MBL.o
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/unity.o ./unity/unity.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/mycode.o ./src/mycode.c
	$(CC) $(CFLAGS) $(INCLUDES) -DUNIT_TEST -mcmse -o ./Objects/main.o ./src/main.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/stdout_USART.o ./Common/stdout_USART.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/system_IOTKit_ARMv8MBL.o ./RTE/Device/IOTKit_ARMv8MBL/system_IOTKit_ARMv8MBL.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/retarget_io.o ./Common/retarget_io.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/test_mycode.o ./tests/test_mycode.c	
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/test_mycode_runner.o ./tests/runners/test_mycode_runner.c		
	$(LD) --cpu=8-m.base ./Objects/unity.o ./Objects/mycode.o ./Objects/main.o ./Objects/stdout_USART.o ./Objects/retarget_io.o ./Objects/startup_IOTKit_ARMv8MBL.o ./Objects/system_IOTKit_ARMv8MBL.o ./Objects/test_mycode.o ./Objects/test_mycode_runner.o --scatter IOTKit_ARMv8MBL.scat --import-cmse-lib-out=./Objects/IOTKit_ARMv8MBL_s_CMSE_Lib.o $(LFLAGS) --list=IOTKit_ARMv8MBL.map -o $(TARGET)_test.axf --entry=Reset_Handler

build_prod:
	$(call MD,./Objects)
	$(AS) --cpu=8-m.base -g --pd="_RTE_ SETA 1" --pd="IOTKit_ARMv8MBL SETA 1" ./RTE/Device/IOTKit_ARMv8MBL/startup_IOTKit_ARMv8MBL.s -o ./Objects/startup_IOTKit_ARMv8MBL.o
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/mycode.o ./src/mycode.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/main.o ./src/main.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/stdout_USART.o ./Common/stdout_USART.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/system_IOTKit_ARMv8MBL.o ./RTE/Device/IOTKit_ARMv8MBL/system_IOTKit_ARMv8MBL.c
	$(CC) $(CFLAGS) $(INCLUDES) -mcmse -o ./Objects/retarget_io.o ./Common/retarget_io.c
	$(LD) --cpu=8-m.base ./Objects/mycode.o ./Objects/main.o ./Objects/stdout_USART.o ./Objects/retarget_io.o ./Objects/startup_IOTKit_ARMv8MBL.o ./Objects/system_IOTKit_ARMv8MBL.o --scatter IOTKit_ARMv8MBL.scat --import-cmse-lib-out=./Objects/IOTKit_ARMv8MBL_s_CMSE_Lib.o $(LFLAGS) --list=IOTKit_ARMv8MBL.map -o $(TARGET).axf --entry=Reset_Handler

clean:
	$(call RM,./Objects/*.o)
	$(call RM,$(TARGET)_test.axf)
	$(call RM,$(TARGET).axf)
	$(call RM,./tests/runners/test_mycode_runner.c)
	$(call RM,./*.htm)
	$(call RM,./*.map)

