;/**************************************************************************//**
; * @file     startup_IOTKit_ARMv8MBL.s
; * @brief    CMSIS Core Device Startup File for
; *           IOTKit_ARMv8MBL Device
; * @version  V1.0.0
; * @date     18. November 2016
; ******************************************************************************/
;/* Copyright (c) 2015 - 2016 ARM LIMITED
;
;   All rights reserved.
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions are met:
;   - Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;   - Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
;   - Neither the name of Arm nor the names of its contributors may be used
;     to endorse or promote products derived from this software without
;     specific prior written permission.
;   *
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
;   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;   POSSIBILITY OF SUCH DAMAGE.
;   ---------------------------------------------------------------------------*/
;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000C00

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp               ;     Top of Stack
                DCD     Reset_Handler              ;     Reset Handler
                DCD     NMI_Handler                ;     NMI Handler
                DCD     HardFault_Handler          ;     Hard Fault Handler
                DCD     0                          ;     Reserved
                DCD     0                          ;     Reserved
                DCD     0                          ;     Reserved
                DCD     0                          ;     Reserved
                DCD     0                          ;     Reserved
                DCD     0                          ;     Reserved
                DCD     0                          ;     Reserved
                DCD     SVC_Handler                ;     SVCall Handler
                DCD     0                          ;     Reserved
                DCD     0                          ;     Reserved
                DCD     PendSV_Handler             ;     PendSV Handler
                DCD     SysTick_Handler            ;     SysTick Handler

                ; Core IoT Interrupts
                DCD      NONSEC_WATCHDOG_RESET_Handler  ; - 0 Non-Secure Watchdog Reset Handler
                DCD      NONSEC_WATCHDOG_Handler        ; - 1 Non-Secure Watchdog Handler
                DCD      S32K_TIMER_Handler             ; - 2 S32K Timer Handler
                DCD      TIMER0_Handler                 ; - 3 TIMER 0 Handler
                DCD      TIMER1_Handler                 ; - 4 TIMER 1 Handler
                DCD      DUALTIMER_Handler              ; - 5 Dual Timer Handler
                DCD      0                              ; Reserved - 6
                DCD      0                              ; Reserved - 7
                DCD      0                              ; Reserved - 8
                DCD      MPC_Handler                    ; - 9 MPC Combined (Secure) Handler
                DCD      PPC_Handler                    ; - 10 PPC Combined (Secure) Handler
                DCD      MSC_Handler                    ; - 11 MSC Combined (Secure) Handler
                DCD      BRIDGE_ERROR_Handler           ; - 12 Bridge Error Combined (Secure) Handler
                DCD      0                              ; Reserved - 13
                DCD      0                              ; Reserved - 14
                DCD      0                              ; Reserved - 15
                DCD      0                              ; Reserved - 16
                DCD      0                              ; Reserved - 17
                DCD      0                              ; Reserved - 18
                DCD      0                              ; Reserved - 19
                DCD      0                              ; Reserved - 20
                DCD      0                              ; Reserved - 21
                DCD      0                              ; Reserved - 22
                DCD      0                              ; Reserved - 23
                DCD      0                              ; Reserved - 24
                DCD      0                              ; Reserved - 25
                DCD      0                              ; Reserved - 26
                DCD      0                              ; Reserved - 27
                DCD      0                              ; Reserved - 28
                DCD      0                              ; Reserved - 29
                DCD      0                              ; Reserved - 30
                DCD      0                              ; Reserved - 31
                ; External Interrupts
                DCD     UART0RX_Handler           ; 32 UART 0 RX Handler
                DCD     UART0TX_Handler           ; 33 UART 0 TX Handler
                DCD     UART1RX_Handler           ; 34 UART 1 RX Handler
                DCD     UART1TX_Handler           ; 35 UART 1 TX Handler
                DCD     UART2RX_Handler           ; 36 UART 2 RX Handler
                DCD     UART2TX_Handler           ; 37 UART 2 TX Handler
                DCD     UART3RX_Handler           ; 38 UART 2 RX Handler
                DCD     UART3TX_Handler           ; 39 UART 2 TX Handler
                DCD     UART4RX_Handler           ; 40 UART 2 RX Handler
                DCD     UART4TX_Handler           ; 41 UART 2 TX Handler
                DCD     UART0_Handler             ; 42 UART 0 combined Handler
                DCD     UART1_Handler             ; 43 UART 1 combined Handler
                DCD     UART2_Handler             ; 44 UART 0 combined Handler
                DCD     UART3_Handler             ; 45 UART 1 combined Handler
                DCD     UART4_Handler             ; 46 UART 0 combined Handler
                DCD     UARTOVF_Handler           ; 47 UART 0,1,2,3,4 Overflow Handler
                DCD     ETHERNET_Handler          ; 48 Ethernet Handler
                DCD     I2S_Handler               ; 49 I2S Handler
                DCD     TSC_Handler               ; 50 Touch Screen Handler
                DCD     SPI0_Handler              ; 51 SPI 0 Handler
                DCD     SPI1_Handler              ; 52 SPI 1 Handler
                DCD     SPI2_Handler              ; 53 SPI 2 Handler
                DCD     SPI3_Handler              ; 54 SPI 3 Handler
                DCD     SPI4_Handler              ; 55 SPI 4 Handler
                DCD     DMA0_ERROR_Handler        ; 56 DMA 0 Error Handler
                DCD     DMA0_TC_Handler           ; 57 DMA 0 Terminal Count Handler
                DCD     DMA0_Handler              ; 58 DMA 0 Combined Handler
                DCD     DMA1_ERROR_Handler        ; 59 DMA 1 Error Handler
                DCD     DMA1_TC_Handler           ; 60 DMA 1 Terminal Count Handler
                DCD     DMA1_Handler              ; 61 DMA 1 Combined Handler
                DCD     DMA2_ERROR_Handler        ; 62 DMA 2 Error Handler
                DCD     DMA2_TC_Handler           ; 63 DMA 2 Terminal Count Handler
                DCD     DMA2_Handler              ; 64 DMA 2 Combined Handler
                DCD     DMA3_ERROR_Handler        ; 65 DMA 3 Error Handler
                DCD     DMA3_TC_Handler           ; 66 DMA 3 Terminal Count Handler
                DCD     DMA3_Handler              ; 67 DMA 3 Combined Handler
                DCD     GPIO0_Handler             ; 68 GPIO 0 Comboned Handler
                DCD     GPIO1_Handler             ; 69 GPIO 1 Comboned Handler
                DCD     GPIO2_Handler             ; 70 GPIO 2 Comboned Handler
                DCD     GPIO3_Handler             ; 71 GPIO 3 Comboned Handler
                DCD     GPIO0_0_Handler           ; 72,      /* All P0 I/O pins used as irq source    */
                DCD     GPIO0_1_Handler           ; 73,      /* There are 16 pins in total            */
                DCD     GPIO0_2_Handler           ; 74,
                DCD     GPIO0_3_Handler           ; 75,
                DCD     GPIO0_4_Handler           ; 76,
                DCD     GPIO0_5_Handler           ; 77,
                DCD     GPIO0_6_Handler           ; 78,
                DCD     GPIO0_7_Handler           ; 79,
                DCD     GPIO0_8_Handler           ; 80,
                DCD     GPIO0_9_Handler           ; 81,
                DCD     GPIO0_10_Handler          ; 82,
                DCD     GPIO0_11_Handler          ; 83,
                DCD     GPIO0_12_Handler          ; 84,
                DCD     GPIO0_13_Handler          ; 85,
                DCD     GPIO0_14_Handler          ; 86,
                DCD     GPIO0_15_Handler          ; 87,
                DCD     GPIO1_0_Handler           ; 88,      /* All P1 I/O pins used as irq source    */
                DCD     GPIO1_1_Handler           ; 89,      /* There are 16 pins in total            */
                DCD     GPIO1_2_Handler           ; 90,
                DCD     GPIO1_3_Handler           ; 91,
                DCD     GPIO1_4_Handler           ; 92,
                DCD     GPIO1_5_Handler           ; 93,
                DCD     GPIO1_6_Handler           ; 94,
                DCD     GPIO1_7_Handler           ; 95,
                DCD     GPIO1_8_Handler           ; 96,
                DCD     GPIO1_9_Handler           ; 97,
                DCD     GPIO1_10_Handler          ; 98,
                DCD     GPIO1_11_Handler          ; 99,
                DCD     GPIO1_12_Handler          ; 100,
                DCD     GPIO1_13_Handler          ; 101,
                DCD     GPIO1_14_Handler          ; 102,
                DCD     GPIO1_15_Handler          ; 103,
                DCD     GPIO2_0_Handler           ; 104,      /* All P2 I/O pins used as irq source    */
                DCD     GPIO2_1_Handler           ; 105,      /* There are 15 pins in total            */
                DCD     GPIO2_2_Handler           ; 106,
                DCD     GPIO2_3_Handler           ; 107,
                DCD     GPIO2_4_Handler           ; 108,
                DCD     GPIO2_5_Handler           ; 109,
                DCD     GPIO2_6_Handler           ; 110,
                DCD     GPIO2_7_Handler           ; 111,
                DCD     GPIO2_8_Handler           ; 112,
                DCD     GPIO2_9_Handler           ; 113,
                DCD     GPIO2_10_Handler          ; 114,
                DCD     GPIO2_11_Handler          ; 116,
                DCD     GPIO2_12_Handler          ; 117,
                DCD     GPIO2_13_Handler          ; 118,
                DCD     GPIO2_14_Handler          ; 119,
                DCD     GPIO3_0_Handler           ; 120,      /* All P3 I/O pins used as irq source    */
                DCD     GPIO3_1_Handler           ; 121,      /* There are 4 pins in total            */
                DCD     GPIO3_2_Handler           ; 122,
                DCD     GPIO3_3_Handler           ; 123,
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC
; Core IoT Interrupts
                EXPORT NONSEC_WATCHDOG_RESET_Handler   [WEAK] ; - 0 Non-Secure Watchdog Reset Handler
                EXPORT NONSEC_WATCHDOG_Handler         [WEAK] ; - 1 Non-Secure Watchdog Handler
                EXPORT S32K_TIMER_Handler              [WEAK] ; - 2 S32K Timer Handler
                EXPORT TIMER0_Handler                  [WEAK] ; - 3 TIMER 0 Handler
                EXPORT TIMER1_Handler                  [WEAK] ; - 4 TIMER 1 Handler
                EXPORT DUALTIMER_Handler               [WEAK] ; - 5 Dual Timer Handler
                EXPORT MPC_Handler                     [WEAK] ; - 9 MPC Combined (Secure) Handler
                EXPORT PPC_Handler                     [WEAK] ; - 10 PPC Combined (Secure) Handler
                EXPORT MSC_Handler                     [WEAK] ; - 11 MSC Combined (Secure) Handler
                EXPORT BRIDGE_ERROR_Handler            [WEAK] ; - 12 Bridge Error Combined (Secure) Handler
; External Interrupts
                EXPORT UART0RX_Handler             [WEAK] ; 32 UART 0 RX Handler
                EXPORT UART0TX_Handler             [WEAK] ; 33 UART 0 TX Handler
                EXPORT UART1RX_Handler             [WEAK] ; 34 UART 1 RX Handler
                EXPORT UART1TX_Handler             [WEAK] ; 35 UART 1 TX Handler
                EXPORT UART2RX_Handler             [WEAK] ; 36 UART 2 RX Handler
                EXPORT UART2TX_Handler             [WEAK] ; 37 UART 2 TX Handler
                EXPORT UART3RX_Handler             [WEAK] ; 38 UART 2 RX Handler
                EXPORT UART3TX_Handler             [WEAK] ; 39 UART 2 TX Handler
                EXPORT UART4RX_Handler             [WEAK] ; 40 UART 2 RX Handler
                EXPORT UART4TX_Handler             [WEAK] ; 41 UART 2 TX Handler
                EXPORT UART0_Handler               [WEAK] ; 42 UART 0 combined Handler
                EXPORT UART1_Handler               [WEAK] ; 43 UART 1 combined Handler
                EXPORT UART2_Handler               [WEAK] ; 44 UART 0 combined Handler
                EXPORT UART3_Handler               [WEAK] ; 45 UART 1 combined Handler
                EXPORT UART4_Handler               [WEAK] ; 46 UART 0 combined Handler
                EXPORT UARTOVF_Handler             [WEAK] ; 47 UART 0,1,2,3,4 Overflow Handler
                EXPORT ETHERNET_Handler            [WEAK] ; 48 Ethernet Handler
                EXPORT I2S_Handler                 [WEAK] ; 49 I2S Handler
                EXPORT TSC_Handler                 [WEAK] ; 50 Touch Screen Handler
                EXPORT SPI0_Handler                [WEAK] ; 51 SPI 0 Handler
                EXPORT SPI1_Handler                [WEAK] ; 52 SPI 1 Handler
                EXPORT SPI2_Handler                [WEAK] ; 53 SPI 2 Handler
                EXPORT SPI3_Handler                [WEAK] ; 54 SPI 3 Handler
                EXPORT SPI4_Handler                [WEAK] ; 55 SPI 4 Handler
                EXPORT DMA0_ERROR_Handler          [WEAK] ; 56 DMA 0 Error Handler
                EXPORT DMA0_TC_Handler             [WEAK] ; 57 DMA 0 Terminal Count Handler
                EXPORT DMA0_Handler                [WEAK] ; 58 DMA 0 Combined Handler
                EXPORT DMA1_ERROR_Handler          [WEAK] ; 59 DMA 1 Error Handler
                EXPORT DMA1_TC_Handler             [WEAK] ; 60 DMA 1 Terminal Count Handler
                EXPORT DMA1_Handler                [WEAK] ; 61 DMA 1 Combined Handler
                EXPORT DMA2_ERROR_Handler          [WEAK] ; 62 DMA 2 Error Handler
                EXPORT DMA2_TC_Handler             [WEAK] ; 63 DMA 2 Terminal Count Handler
                EXPORT DMA2_Handler                [WEAK] ; 64 DMA 2 Combined Handler
                EXPORT DMA3_ERROR_Handler          [WEAK] ; 65 DMA 3 Error Handler
                EXPORT DMA3_TC_Handler             [WEAK] ; 66 DMA 3 Terminal Count Handler
                EXPORT DMA3_Handler                [WEAK] ; 67 DMA 3 Combined Handler
                EXPORT GPIO0_Handler               [WEAK] ; 68 GPIO 0 Comboned Handler
                EXPORT GPIO1_Handler               [WEAK] ; 69 GPIO 1 Comboned Handler
                EXPORT GPIO2_Handler               [WEAK] ; 70 GPIO 2 Comboned Handler
                EXPORT GPIO3_Handler               [WEAK] ; 71 GPIO 3 Comboned Handler
                EXPORT GPIO0_0_Handler             [WEAK] ; 72,      /* All P0 I/O pins used as irq source    */
                EXPORT GPIO0_1_Handler             [WEAK] ; 73,      /* There are 16 pins in total            */
                EXPORT GPIO0_2_Handler             [WEAK] ; 74,
                EXPORT GPIO0_3_Handler             [WEAK] ; 75,
                EXPORT GPIO0_4_Handler             [WEAK] ; 76,
                EXPORT GPIO0_5_Handler             [WEAK] ; 77,
                EXPORT GPIO0_6_Handler             [WEAK] ; 78,
                EXPORT GPIO0_7_Handler             [WEAK] ; 79,
                EXPORT GPIO0_8_Handler             [WEAK] ; 80,
                EXPORT GPIO0_9_Handler             [WEAK] ; 81,
                EXPORT GPIO0_10_Handler            [WEAK] ; 82,
                EXPORT GPIO0_11_Handler            [WEAK] ; 83,
                EXPORT GPIO0_12_Handler            [WEAK] ; 84,
                EXPORT GPIO0_13_Handler            [WEAK] ; 85,
                EXPORT GPIO0_14_Handler            [WEAK] ; 86,
                EXPORT GPIO0_15_Handler            [WEAK] ; 87,
                EXPORT GPIO1_0_Handler             [WEAK] ; 88,      /* All P1 I/O pins used as irq source    */
                EXPORT GPIO1_1_Handler             [WEAK] ; 89,      /* There are 16 pins in total            */
                EXPORT GPIO1_2_Handler             [WEAK] ; 90,
                EXPORT GPIO1_3_Handler             [WEAK] ; 91,
                EXPORT GPIO1_4_Handler             [WEAK] ; 92,
                EXPORT GPIO1_5_Handler             [WEAK] ; 93,
                EXPORT GPIO1_6_Handler             [WEAK] ; 94,
                EXPORT GPIO1_7_Handler             [WEAK] ; 95,
                EXPORT GPIO1_8_Handler             [WEAK] ; 96,
                EXPORT GPIO1_9_Handler             [WEAK] ; 97,
                EXPORT GPIO1_10_Handler            [WEAK] ; 98,
                EXPORT GPIO1_11_Handler            [WEAK] ; 99,
                EXPORT GPIO1_12_Handler            [WEAK] ; 100,
                EXPORT GPIO1_13_Handler            [WEAK] ; 101,
                EXPORT GPIO1_14_Handler            [WEAK] ; 102,
                EXPORT GPIO1_15_Handler            [WEAK] ; 103,
                EXPORT GPIO2_0_Handler             [WEAK] ; 104,      /* All P2 I/O pins used as irq source    */
                EXPORT GPIO2_1_Handler             [WEAK] ; 105,      /* There are 15 pins in total            */
                EXPORT GPIO2_2_Handler             [WEAK] ; 106,
                EXPORT GPIO2_3_Handler             [WEAK] ; 107,
                EXPORT GPIO2_4_Handler             [WEAK] ; 108,
                EXPORT GPIO2_5_Handler             [WEAK] ; 109,
                EXPORT GPIO2_6_Handler             [WEAK] ; 110,
                EXPORT GPIO2_7_Handler             [WEAK] ; 111,
                EXPORT GPIO2_8_Handler             [WEAK] ; 112,
                EXPORT GPIO2_9_Handler             [WEAK] ; 113,
                EXPORT GPIO2_10_Handler            [WEAK] ; 114,
                EXPORT GPIO2_11_Handler            [WEAK] ; 116,
                EXPORT GPIO2_12_Handler            [WEAK] ; 117,
                EXPORT GPIO2_13_Handler            [WEAK] ; 118,
                EXPORT GPIO2_14_Handler            [WEAK] ; 119,
                EXPORT GPIO3_1_Handler             [WEAK] ; 121,      /* There are 4 pins in total            */
                EXPORT GPIO3_2_Handler             [WEAK] ; 122,
                EXPORT GPIO3_3_Handler             [WEAK] ; 123,

; Core IoT Interrupts
NONSEC_WATCHDOG_RESET_Handler  ; - 0 Non-Secure Watchdog Reset Handler
NONSEC_WATCHDOG_Handler        ; - 1 Non-Secure Watchdog Handler
S32K_TIMER_Handler             ; - 2 S32K Timer Handler
TIMER0_Handler                 ; - 3 TIMER 0 Handler
TIMER1_Handler                 ; - 4 TIMER 1 Handler
DUALTIMER_Handler              ; - 5 Dual Timer Handler
MPC_Handler                    ; - 9 MPC Combined (Secure) Handler
PPC_Handler                    ; - 10 PPC Combined (Secure) Handler
MSC_Handler                    ; - 11 MSC Combined (Secure) Handler
BRIDGE_ERROR_Handler           ; - 12 Bridge Error Combined (Secure) Handler
; External Interrupts
UART0RX_Handler           ; 32 UART 0 RX Handler
UART0TX_Handler           ; 33 UART 0 TX Handler
UART1RX_Handler           ; 34 UART 1 RX Handler
UART1TX_Handler           ; 35 UART 1 TX Handler
UART2RX_Handler           ; 36 UART 2 RX Handler
UART2TX_Handler           ; 37 UART 2 TX Handler
UART3RX_Handler           ; 38 UART 2 RX Handler
UART3TX_Handler           ; 39 UART 2 TX Handler
UART4RX_Handler           ; 40 UART 2 RX Handler
UART4TX_Handler           ; 41 UART 2 TX Handler
UART0_Handler             ; 42 UART 0 combined Handler
UART1_Handler             ; 43 UART 1 combined Handler
UART2_Handler             ; 44 UART 0 combined Handler
UART3_Handler             ; 45 UART 1 combined Handler
UART4_Handler             ; 46 UART 0 combined Handler
UARTOVF_Handler           ; 47 UART 0,1,2,3,4 Overflow Handler
ETHERNET_Handler          ; 48 Ethernet Handler
I2S_Handler               ; 49 I2S Handler
TSC_Handler               ; 50 Touch Screen Handler
SPI0_Handler              ; 51 SPI 0 Handler
SPI1_Handler              ; 52 SPI 1 Handler
SPI2_Handler              ; 53 SPI 2 Handler
SPI3_Handler              ; 54 SPI 3 Handler
SPI4_Handler              ; 55 SPI 4 Handler
DMA0_ERROR_Handler        ; 56 DMA 0 Error Handler
DMA0_TC_Handler           ; 57 DMA 0 Terminal Count Handler
DMA0_Handler              ; 58 DMA 0 Combined Handler
DMA1_ERROR_Handler        ; 59 DMA 1 Error Handler
DMA1_TC_Handler           ; 60 DMA 1 Terminal Count Handler
DMA1_Handler              ; 61 DMA 1 Combined Handler
DMA2_ERROR_Handler        ; 62 DMA 2 Error Handler
DMA2_TC_Handler           ; 63 DMA 2 Terminal Count Handler
DMA2_Handler              ; 64 DMA 2 Combined Handler
DMA3_ERROR_Handler        ; 65 DMA 3 Error Handler
DMA3_TC_Handler           ; 66 DMA 3 Terminal Count Handler
DMA3_Handler              ; 67 DMA 3 Combined Handler
GPIO0_Handler             ; 68 GPIO 0 Comboned Handler
GPIO1_Handler             ; 69 GPIO 1 Comboned Handler
GPIO2_Handler             ; 70 GPIO 2 Comboned Handler
GPIO3_Handler             ; 71 GPIO 3 Comboned Handler
GPIO0_0_Handler           ; 72,      /* All P0 I/O pins used as irq source    */
GPIO0_1_Handler           ; 73,      /* There are 16 pins in total            */
GPIO0_2_Handler           ; 74,
GPIO0_3_Handler           ; 75,
GPIO0_4_Handler           ; 76,
GPIO0_5_Handler           ; 77,
GPIO0_6_Handler           ; 78,
GPIO0_7_Handler           ; 79,
GPIO0_8_Handler           ; 80,
GPIO0_9_Handler           ; 81,
GPIO0_10_Handler          ; 82,
GPIO0_11_Handler          ; 83,
GPIO0_12_Handler          ; 84,
GPIO0_13_Handler          ; 85,
GPIO0_14_Handler          ; 86,
GPIO0_15_Handler          ; 87,
GPIO1_0_Handler           ; 88,      /* All P1 I/O pins used as irq source    */
GPIO1_1_Handler           ; 89,      /* There are 16 pins in total            */
GPIO1_2_Handler           ; 90,
GPIO1_3_Handler           ; 91,
GPIO1_4_Handler           ; 92,
GPIO1_5_Handler           ; 93,
GPIO1_6_Handler           ; 94,
GPIO1_7_Handler           ; 95,
GPIO1_8_Handler           ; 96,
GPIO1_9_Handler           ; 97,
GPIO1_10_Handler          ; 98,
GPIO1_11_Handler          ; 99,
GPIO1_12_Handler          ; 100,
GPIO1_13_Handler          ; 101,
GPIO1_14_Handler          ; 102,
GPIO1_15_Handler          ; 103,
GPIO2_0_Handler           ; 104,      /* All P2 I/O pins used as irq source    */
GPIO2_1_Handler           ; 105,      /* There are 15 pins in total            */
GPIO2_2_Handler           ; 106,
GPIO2_3_Handler           ; 107,
GPIO2_4_Handler           ; 108,
GPIO2_5_Handler           ; 109,
GPIO2_6_Handler           ; 110,
GPIO2_7_Handler           ; 111,
GPIO2_8_Handler           ; 112,
GPIO2_9_Handler           ; 113,
GPIO2_10_Handler          ; 114,
GPIO2_11_Handler          ; 116,
GPIO2_12_Handler          ; 117,
GPIO2_13_Handler          ; 118,
GPIO2_14_Handler          ; 119,
GPIO3_0_Handler           ; 120,      /* All P3 I/O pins used as irq source    */
GPIO3_1_Handler           ; 121,      /* There are 4 pins in total            */
GPIO3_2_Handler           ; 122,
GPIO3_3_Handler           ; 123,
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
