/**************************************************************************//**
 * @file     IOTKit_ARMv8MBL.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 *           IOTKit_ARMv8MBL Device (configured for IOTKit_ARMv8MBL)
 * @version  V1.0.0
 * @date     18. November 2016
 ******************************************************************************/
/* Copyright (c) 2015 - 2016 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of Arm nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#ifndef IOTKit_ARMv8MBL_H
#define IOTKit_ARMv8MBL_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn
{
/* --------------------  Core_IoT Processor Exceptions Numbers  ------------------- */
  NonMaskableInt_IRQn           = -14,      /*  2 Non Maskable Interrupt */
  HardFault_IRQn                = -13,      /*  3 HardFault Interrupt */




  SVCall_IRQn                   =  -5,      /* 11 SV Call Interrupt */

  PendSV_IRQn                   =  -2,      /* 14 Pend SV Interrupt */
  SysTick_IRQn                  =  -1,      /* 15 System Tick Interrupt */

/* ----------------------  Core_IoT Specific Interrupt Numbers  ------------------- */
  NONSEC_WATCHDOG_RESET_IRQn    =   0,      /* Non-Secure Watchdog Reset Interrupt */
  NONSEC_WATCHDOG_IRQn          =   1,      /* Non-Secure Watchdog Interrupt */
  S32K_TIMER_IRQn               =   2,      /* S32K Timer Interrupt */
  TIMER0_IRQn                   =   3,      /* TIMER 0 Interrupt */
  TIMER1_IRQn                   =   4,      /* TIMER 1 Interrupt */
  DUALTIMER_IRQn                =   5,      /* Dual Timer Interrupt */
  MPC_IRQn                      =   9,      /* MPC Combined (Secure) Interrupt */
  PPC_IRQn                      =   10,     /* PPC Combined (Secure) Interrupt */
  MSC_IRQn                      =   11,     /* MSC Combined (Secure) Interrput */
  BRIDGE_ERROR_IRQn             =   12,     /* Bridge Error Combined (Secure) Interrupt */

/* ----------------------  IOTKIT_IoT Specific Interrupt Numbers  ------------------ */
  UART0RX_IRQn                  =   32,     /* UART 0 RX Interrupt */
  UART0TX_IRQn                  =   33,     /* UART 0 TX Interrupt */
  UART1RX_IRQn                  =   34,     /* UART 1 RX Interrupt */
  UART1TX_IRQn                  =   35,     /* UART 1 TX Interrupt */
  UART2RX_IRQn                  =   36,     /* UART 2 RX Interrupt */
  UART2TX_IRQn                  =   37,     /* UART 2 TX Interrupt */
  UART3RX_IRQn                  =   38,     /* UART 3 RX Interrupt */
  UART3TX_IRQn                  =   39,     /* UART 3 TX Interrupt */
  UART4RX_IRQn                  =   40,     /* UART 4 RX Interrupt */
  UART4TX_IRQn                  =   41,     /* UART 4 TX Interrupt */
  UART0_IRQn                    =   42,     /* UART 0 combined Interrupt */
  UART1_IRQn                    =   43,     /* UART 1 combined Interrupt */
  UART2_IRQn                    =   44,     /* UART 0 combined Interrupt */
  UART3_IRQn                    =   45,     /* UART 1 combined Interrupt */
  UART4_IRQn                    =   46,     /* UART 0 combined Interrupt */
  UARTOVF_IRQn                  =   47,     /* UART 0,1,2,3,4 Overflow Interrupt */
  ETHERNET_IRQn                 =   48,     /* Ethernet Interrupt */
  I2S_IRQn                      =   49,     /* I2S Interrupt */
  TSC_IRQn                      =   50,     /* Touch Screen Interrupt */
  SPI0_IRQn                     =   51,     /* SPI 0 Interrupt */
  SPI1_IRQn                     =   52,     /* SPI 1 Interrupt */
  SPI2_IRQn                     =   53,     /* SPI 2 Interrupt */
  SPI3_IRQn                     =   54,     /* SPI 3 Interrupt */
  SPI4_IRQn                     =   55,     /* SPI 4 Interrupt */
  DMA0_ERROR_IRQn               =   56,     /* DMA 0 Error Interrupt */
  DMA0_TC_IRQn                  =   57,     /* DMA 0 Terminal Count Interrupt */
  DMA0_IRQn                     =   58,     /* DMA 0 Combined Interrupt */
  DMA1_ERROR_IRQn               =   59,     /* DMA 1 Error Interrupt */
  DMA1_TC_IRQn                  =   60,     /* DMA 1 Terminal Count Interrupt */
  DMA1_IRQn                     =   61,     /* DMA 1 Combined Interrupt */
  DMA2_ERROR_IRQn               =   62,     /* DMA 2 Error Interrupt */
  DMA2_TC_IRQn                  =   63,     /* DMA 2 Terminal Count Interrupt */
  DMA2_IRQn                     =   64,     /* DMA 2 Combined Interrupt */
  DMA3_ERROR_IRQn               =   65,     /* DMA 3 Error Interrupt */
  DMA3_TC_IRQn                  =   66,     /* DMA 3 Terminal Count Interrupt */
  DMA3_IRQn                     =   67,     /* DMA 3 Combined Interrupt */
  GPIO0_IRQn                    =   68,     /* GPIO 0 Combined Interrupt */
  GPIO1_IRQn                    =   69,     /* GPIO 1 Combined Interrupt */
  GPIO2_IRQn                    =   70,     /* GPIO 2 Combined Interrupt */
  GPIO3_IRQn                    =   71,     /* GPIO 3 Combined Interrupt */
  GPIO0_0_IRQn                  =   72,     /* All P0 I/O pins used as irq source */
  GPIO0_1_IRQn                  =   73,     /* There are 16 pins in total */
  GPIO0_2_IRQn                  =   74,
  GPIO0_3_IRQn                  =   75,
  GPIO0_4_IRQn                  =   76,
  GPIO0_5_IRQn                  =   77,
  GPIO0_6_IRQn                  =   78,
  GPIO0_7_IRQn                  =   79,
  GPIO0_8_IRQn                  =   80,
  GPIO0_9_IRQn                  =   81,
  GPIO0_10_IRQn                 =   82,
  GPIO0_11_IRQn                 =   83,
  GPIO0_12_IRQn                 =   84,
  GPIO0_13_IRQn                 =   85,
  GPIO0_14_IRQn                 =   86,
  GPIO0_15_IRQn                 =   87,
  GPIO1_0_IRQn                  =   88,     /* All P1 I/O pins used as irq source */
  GPIO1_1_IRQn                  =   89,     /* There are 16 pins in total */
  GPIO1_2_IRQn                  =   90,
  GPIO1_3_IRQn                  =   91,
  GPIO1_4_IRQn                  =   92,
  GPIO1_5_IRQn                  =   93,
  GPIO1_6_IRQn                  =   94,
  GPIO1_7_IRQn                  =   95,
  GPIO1_8_IRQn                  =   96,
  GPIO1_9_IRQn                  =   97,
  GPIO1_10_IRQn                 =   98,
  GPIO1_11_IRQn                 =   99,
  GPIO1_12_IRQn                 =  100,
  GPIO1_13_IRQn                 =  101,
  GPIO1_14_IRQn                 =  102,
  GPIO1_15_IRQn                 =  103,
  GPIO2_0_IRQn                  =  104,     /* All P2 I/O pins used as irq source */
  GPIO2_1_IRQn                  =  105,     /* There are 15 pins in total */
  GPIO2_2_IRQn                  =  106,
  GPIO2_3_IRQn                  =  107,
  GPIO2_4_IRQn                  =  108,
  GPIO2_5_IRQn                  =  109,
  GPIO2_6_IRQn                  =  110,
  GPIO2_7_IRQn                  =  111,
  GPIO2_8_IRQn                  =  112,
  GPIO2_9_IRQn                  =  113,
  GPIO2_10_IRQn                 =  114,
  GPIO2_11_IRQn                 =  116,
  GPIO2_12_IRQn                 =  117,
  GPIO2_13_IRQn                 =  118,
  GPIO2_14_IRQn                 =  119,
  GPIO3_0_IRQn                  =  120,     /* All P3 I/O pins used as irq source */
  GPIO3_1_IRQn                  =  121,     /* There are 4 pins in total */
  GPIO3_2_IRQn                  =  122,
  GPIO3_3_IRQn                  =  123
} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of the IOTKIT_IoT Processor and Core Peripherals  ------- */
#define __ARMv8MBL_REV            0x0000U   /* Core revision r0p0 */
#define __SAUREGION_PRESENT       1U        /* SAU regions are present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          2U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */

#include "core_armv8mbl.h"                  /* Processor and core peripherals */
#include "system_IOTKit_ARMv8MBL.h"        /* System Header */


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/
typedef struct
{
  __IOM  uint32_t  DATA;                     /* Offset: 0x000 (R/W) Data Register    */
  __IOM  uint32_t  STATE;                    /* Offset: 0x004 (R/W) Status Register  */
  __IOM  uint32_t  CTRL;                     /* Offset: 0x008 (R/W) Control Register */
  union {
  __IM   uint32_t  INTSTATUS;                /* Offset: 0x00C (R/ ) Interrupt Status Register */
  __OM   uint32_t  INTCLEAR;                 /* Offset: 0x00C ( /W) Interrupt Clear Register  */
    };
  __IOM  uint32_t  BAUDDIV;                  /* Offset: 0x010 (R/W) Baudrate Divider Register */

} IOTKIT_UART_TypeDef;

/* IOTKIT_UART DATA Register Definitions */
#define IOTKIT_UART_DATA_Pos               0                                                  /* IOTKIT_UART_DATA_Pos: DATA Position */
#define IOTKIT_UART_DATA_Msk              (0xFFUL /*<< IOTKIT_UART_DATA_Pos*/)                /* IOTKIT_UART DATA: DATA Mask */

/* IOTKIT_UART STATE Register Definitions */
#define IOTKIT_UART_STATE_RXOR_Pos         3                                                  /* IOTKIT_UART STATE: RXOR Position */
#define IOTKIT_UART_STATE_RXOR_Msk        (0x1UL << IOTKIT_UART_STATE_RXOR_Pos)               /* IOTKIT_UART STATE: RXOR Mask */

#define IOTKIT_UART_STATE_TXOR_Pos         2                                                  /* IOTKIT_UART STATE: TXOR Position */
#define IOTKIT_UART_STATE_TXOR_Msk        (0x1UL << IOTKIT_UART_STATE_TXOR_Pos)               /* IOTKIT_UART STATE: TXOR Mask */

#define IOTKIT_UART_STATE_RXBF_Pos         1                                                  /* IOTKIT_UART STATE: RXBF Position */
#define IOTKIT_UART_STATE_RXBF_Msk        (0x1UL << IOTKIT_UART_STATE_RXBF_Pos)               /* IOTKIT_UART STATE: RXBF Mask */

#define IOTKIT_UART_STATE_TXBF_Pos         0                                                  /* IOTKIT_UART STATE: TXBF Position */
#define IOTKIT_UART_STATE_TXBF_Msk        (0x1UL /*<< IOTKIT_UART_STATE_TXBF_Pos*/)           /* IOTKIT_UART STATE: TXBF Mask */

/* IOTKIT_UART CTRL Register Definitions */
#define IOTKIT_UART_CTRL_HSTM_Pos          6                                                  /* IOTKIT_UART CTRL: HSTM Position */
#define IOTKIT_UART_CTRL_HSTM_Msk         (0x01UL << IOTKIT_UART_CTRL_HSTM_Pos)               /* IOTKIT_UART CTRL: HSTM Mask */

#define IOTKIT_UART_CTRL_RXORIRQEN_Pos     5                                                  /* IOTKIT_UART CTRL: RXORIRQEN Position */
#define IOTKIT_UART_CTRL_RXORIRQEN_Msk    (0x01UL << IOTKIT_UART_CTRL_RXORIRQEN_Pos)          /* IOTKIT_UART CTRL: RXORIRQEN Mask */

#define IOTKIT_UART_CTRL_TXORIRQEN_Pos     4                                                  /* IOTKIT_UART CTRL: TXORIRQEN Position */
#define IOTKIT_UART_CTRL_TXORIRQEN_Msk    (0x01UL << IOTKIT_UART_CTRL_TXORIRQEN_Pos)          /* IOTKIT_UART CTRL: TXORIRQEN Mask */

#define IOTKIT_UART_CTRL_RXIRQEN_Pos       3                                                  /* IOTKIT_UART CTRL: RXIRQEN Position */
#define IOTKIT_UART_CTRL_RXIRQEN_Msk      (0x01UL << IOTKIT_UART_CTRL_RXIRQEN_Pos)            /* IOTKIT_UART CTRL: RXIRQEN Mask */

#define IOTKIT_UART_CTRL_TXIRQEN_Pos       2                                                  /* IOTKIT_UART CTRL: TXIRQEN Position */
#define IOTKIT_UART_CTRL_TXIRQEN_Msk      (0x01UL << IOTKIT_UART_CTRL_TXIRQEN_Pos)            /* IOTKIT_UART CTRL: TXIRQEN Mask */

#define IOTKIT_UART_CTRL_RXEN_Pos          1                                                  /* IOTKIT_UART CTRL: RXEN Position */
#define IOTKIT_UART_CTRL_RXEN_Msk         (0x01UL << IOTKIT_UART_CTRL_RXEN_Pos)               /* IOTKIT_UART CTRL: RXEN Mask */

#define IOTKIT_UART_CTRL_TXEN_Pos          0                                                  /* IOTKIT_UART CTRL: TXEN Position */
#define IOTKIT_UART_CTRL_TXEN_Msk         (0x01UL /*<< IOTKIT_UART_CTRL_TXEN_Pos*/)           /* IOTKIT_UART CTRL: TXEN Mask */

#define IOTKIT_UART_INTSTATUS_RXORIRQ_Pos  3                                                  /* IOTKIT_UART CTRL: RXORIRQ Position */
#define IOTKIT_UART_CTRL_RXORIRQ_Msk      (0x01UL << IOTKIT_UART_INTSTATUS_RXORIRQ_Pos)       /* IOTKIT_UART CTRL: RXORIRQ Mask */

#define IOTKIT_UART_CTRL_TXORIRQ_Pos       2                                                  /* IOTKIT_UART CTRL: TXORIRQ Position */
#define IOTKIT_UART_CTRL_TXORIRQ_Msk      (0x01UL << IOTKIT_UART_CTRL_TXORIRQ_Pos)            /* IOTKIT_UART CTRL: TXORIRQ Mask */

#define IOTKIT_UART_CTRL_RXIRQ_Pos         1                                                  /* IOTKIT_UART CTRL: RXIRQ Position */
#define IOTKIT_UART_CTRL_RXIRQ_Msk        (0x01UL << IOTKIT_UART_CTRL_RXIRQ_Pos)              /* IOTKIT_UART CTRL: RXIRQ Mask */

#define IOTKIT_UART_CTRL_TXIRQ_Pos         0                                                  /* IOTKIT_UART CTRL: TXIRQ Position */
#define IOTKIT_UART_CTRL_TXIRQ_Msk        (0x01UL /*<< IOTKIT_UART_CTRL_TXIRQ_Pos*/)          /* IOTKIT_UART CTRL: TXIRQ Mask */

/* IOTKIT_UART BAUDDIV Register Definitions */
#define IOTKIT_UART_BAUDDIV_Pos            0                                                  /* IOTKIT_UART BAUDDIV: BAUDDIV Position */
#define IOTKIT_UART_BAUDDIV_Msk           (0xFFFFFUL /*<< IOTKIT_UART_BAUDDIV_Pos*/)          /* IOTKIT_UART BAUDDIV: BAUDDIV Mask */


/*----------------------------- Timer (TIMER) -------------------------------*/
typedef struct
{
  __IOM  uint32_t  CTRL;                     /* Offset: 0x000 (R/W) Control Register */
  __IOM  uint32_t  VALUE;                    /* Offset: 0x004 (R/W) Current Value Register */
  __IOM  uint32_t  RELOAD;                   /* Offset: 0x008 (R/W) Reload Value Register */
  union {
  __IM   uint32_t  INTSTATUS;                /* Offset: 0x00C (R/ ) Interrupt Status Register */
  __OM   uint32_t  INTCLEAR;                 /* Offset: 0x00C ( /W) Interrupt Clear Register */
    };

} IOTKIT_TIMER_TypeDef;

/* IOTKIT_TIMER CTRL Register Definitions */
#define IOTKIT_TIMER_CTRL_IRQEN_Pos          3                                                /* IOTKIT_TIMER CTRL: IRQEN Position */
#define IOTKIT_TIMER_CTRL_IRQEN_Msk         (0x01UL << IOTKIT_TIMER_CTRL_IRQEN_Pos)           /* IOTKIT_TIMER CTRL: IRQEN Mask */

#define IOTKIT_TIMER_CTRL_SELEXTCLK_Pos      2                                                /* IOTKIT_TIMER CTRL: SELEXTCLK Position */
#define IOTKIT_TIMER_CTRL_SELEXTCLK_Msk     (0x01UL << IOTKIT_TIMER_CTRL_SELEXTCLK_Pos)       /* IOTKIT_TIMER CTRL: SELEXTCLK Mask */

#define IOTKIT_TIMER_CTRL_SELEXTEN_Pos       1                                                /* IOTKIT_TIMER CTRL: SELEXTEN Position */
#define IOTKIT_TIMER_CTRL_SELEXTEN_Msk      (0x01UL << IOTKIT_TIMER_CTRL_SELEXTEN_Pos)        /* IOTKIT_TIMER CTRL: SELEXTEN Mask */

#define IOTKIT_TIMER_CTRL_EN_Pos             0                                                /* IOTKIT_TIMER CTRL: EN Position */
#define IOTKIT_TIMER_CTRL_EN_Msk            (0x01UL /*<< IOTKIT_TIMER_CTRL_EN_Pos*/)          /* IOTKIT_TIMER CTRL: EN Mask */

/* IOTKIT_TIMER VAL Register Definitions */
#define IOTKIT_TIMER_VAL_CURRENT_Pos         0                                                /* IOTKIT_TIMER VALUE: CURRENT Position */
#define IOTKIT_TIMER_VAL_CURRENT_Msk        (0xFFFFFFFFUL /*<< IOTKIT_TIMER_VAL_CURRENT_Pos*/)/* IOTKIT_TIMER VALUE: CURRENT Mask */

/* IOTKIT_TIMER RELOAD Register Definitions */
#define IOTKIT_TIMER_RELOAD_VAL_Pos          0                                                /* IOTKIT_TIMER RELOAD: RELOAD Position */
#define IOTKIT_TIMER_RELOAD_VAL_Msk         (0xFFFFFFFFUL /*<< IOTKIT_TIMER_RELOAD_VAL_Pos*/) /* IOTKIT_TIMER RELOAD: RELOAD Mask */

/* IOTKIT_TIMER INTSTATUS Register Definitions */
#define IOTKIT_TIMER_INTSTATUS_Pos           0                                                /* IOTKIT_TIMER INTSTATUS: INTSTATUSPosition */
#define IOTKIT_TIMER_INTSTATUS_Msk          (0x01UL /*<< IOTKIT_TIMER_INTSTATUS_Pos*/)        /* IOTKIT_TIMER INTSTATUS: INTSTATUSMask */

/* IOTKIT_TIMER INTCLEAR Register Definitions */
#define IOTKIT_TIMER_INTCLEAR_Pos            0                                                /* IOTKIT_TIMER INTCLEAR: INTCLEAR Position */
#define IOTKIT_TIMER_INTCLEAR_Msk           (0x01UL /*<< IOTKIT_TIMER_INTCLEAR_Pos*/)         /* IOTKIT_TIMER INTCLEAR: INTCLEAR Mask */


/*------------- Timer (TIM) --------------------------------------------------*/
typedef struct
{
  __IOM uint32_t T1LOAD;                     /* Offset: 0x000 (R/W) Timer 1 Load */
  __IM  uint32_t T1VALUE;                    /* Offset: 0x004 (R/ ) Timer 1 Counter Current Value */
  __IOM uint32_t T1CTRL;                     /* Offset: 0x008 (R/W) Timer 1 Control */
  __OM  uint32_t T1INTCLR;                   /* Offset: 0x00C ( /W) Timer 1 Interrupt Clear */
  __IM  uint32_t T1RIS;                      /* Offset: 0x010 (R/ ) Timer 1 Raw Interrupt Status */
  __IM  uint32_t T1MIS;                      /* Offset: 0x014 (R/ ) Timer 1 Masked Interrupt Status */
  __IOM uint32_t T1BGLOAD;                   /* Offset: 0x018 (R/W) Background Load Register */
        uint32_t RESERVED0;
  __IOM uint32_t T2LOAD;                     /* Offset: 0x020 (R/W) Timer 2 Load */
  __IM  uint32_t T2VALUE;                    /* Offset: 0x024 (R/ ) Timer 2 Counter Current Value */
  __IOM uint32_t T2CTRL;                     /* Offset: 0x028 (R/W) Timer 2 Control */
  __OM  uint32_t T2INTCLR;                   /* Offset: 0x02C ( /W) Timer 2 Interrupt Clear */
  __IM  uint32_t T2RIS;                      /* Offset: 0x030 (R/ ) Timer 2 Raw Interrupt Status */
  __IM  uint32_t T2MIS;                      /* Offset: 0x034 (R/ ) Timer 2 Masked Interrupt Status */
  __IOM uint32_t T2BGLOAD;                   /* Offset: 0x038 (R/W) Background Load Register */
        uint32_t RESERVED1[945];
  __IOM uint32_t ITCR;                       /* Offset: 0xF00 (R/W) Integration Test Control Register */
  __OM  uint32_t ITOP;                       /* Offset: 0xF04 ( /W) Integration Test Output Set Register */
} IOTKIT_DUALTIMER_BOTH_TypeDef;


typedef struct
{
  __IOM uint32_t LOAD;                       /* Offset: 0x000 (R/W) Timer Load */
  __IM  uint32_t VALUE;                      /* Offset: 0x000 (R/W) Timer Counter Current Value */
  __IOM uint32_t CTRL;                       /* Offset: 0x000 (R/W) Timer Control */
  __OM  uint32_t INTCLR;                     /* Offset: 0x000 (R/W) Timer Interrupt Clear */
  __IM  uint32_t RIS;                        /* Offset: 0x000 (R/W) Timer Raw Interrupt Status */
  __IM  uint32_t MIS;                        /* Offset: 0x000 (R/W) Timer Masked Interrupt Status */
  __IOM uint32_t BGLOAD;                     /* Offset: 0x000 (R/W) Background Load Register */
} IOTKIT_DUALTIMER_SINGLE_TypeDef;

/* IOTKIT_DUALTIMER_SINGLE LOAD Register Definitions */
#define IOTKIT_DUALTIMER_LOAD_Pos             0                                               /* IOTKIT_DUALTIMER LOAD: LOAD Position */
#define IOTKIT_DUALTIMER_LOAD_Msk            (0xFFFFFFFFUL /*<< IOTKIT_DUALTIMER_LOAD_Pos*/)  /* IOTKIT_DUALTIMER LOAD: LOAD Mask */

/* IOTKIT_DUALTIMER_SINGLE VALUE Register Definitions */
#define IOTKIT_DUALTIMER_VALUE_Pos            0                                               /* IOTKIT_DUALTIMER VALUE: VALUE Position */
#define IOTKIT_DUALTIMER_VALUE_Msk           (0xFFFFFFFFUL /*<< IOTKIT_DUALTIMER_VALUE_Pos*/) /* IOTKIT_DUALTIMER VALUE: VALUE Mask */

/* IOTKIT_DUALTIMER_SINGLE CTRL Register Definitions */
#define IOTKIT_DUALTIMER_CTRL_EN_Pos          7                                               /* IOTKIT_DUALTIMER CTRL_EN: CTRL Enable Position */
#define IOTKIT_DUALTIMER_CTRL_EN_Msk         (0x1UL << IOTKIT_DUALTIMER_CTRL_EN_Pos)          /* IOTKIT_DUALTIMER CTRL_EN: CTRL Enable Mask */

#define IOTKIT_DUALTIMER_CTRL_MODE_Pos        6                                               /* IOTKIT_DUALTIMER CTRL_MODE: CTRL MODE Position */
#define IOTKIT_DUALTIMER_CTRL_MODE_Msk       (0x1UL << IOTKIT_DUALTIMER_CTRL_MODE_Pos)        /* IOTKIT_DUALTIMER CTRL_MODE: CTRL MODE Mask */

#define IOTKIT_DUALTIMER_CTRL_INTEN_Pos       5                                               /* IOTKIT_DUALTIMER CTRL_INTEN: CTRL Int Enable Position */
#define IOTKIT_DUALTIMER_CTRL_INTEN_Msk      (0x1UL << IOTKIT_DUALTIMER_CTRL_INTEN_Pos)       /* IOTKIT_DUALTIMER CTRL_INTEN: CTRL Int Enable Mask */

#define IOTKIT_DUALTIMER_CTRL_PRESCALE_Pos    2                                               /* IOTKIT_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Position */
#define IOTKIT_DUALTIMER_CTRL_PRESCALE_Msk   (0x3UL << IOTKIT_DUALTIMER_CTRL_PRESCALE_Pos)    /* IOTKIT_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Mask */

#define IOTKIT_DUALTIMER_CTRL_SIZE_Pos        1                                               /* IOTKIT_DUALTIMER CTRL_SIZE: CTRL SIZE Position */
#define IOTKIT_DUALTIMER_CTRL_SIZE_Msk       (0x1UL << IOTKIT_DUALTIMER_CTRL_SIZE_Pos)        /* IOTKIT_DUALTIMER CTRL_SIZE: CTRL SIZE Mask */

#define IOTKIT_DUALTIMER_CTRL_ONESHOOT_Pos    0                                               /* IOTKIT_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define IOTKIT_DUALTIMER_CTRL_ONESHOOT_Msk   (0x1UL /*<< IOTKIT_DUALTIMER_CTRL_ONESHOOT_Pos*/)/* IOTKIT_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Mask */

/* IOTKIT_DUALTIMER_SINGLE INTCLR Register Definitions */
#define IOTKIT_DUALTIMER_INTCLR_Pos           0                                               /* IOTKIT_DUALTIMER INTCLR: INT Clear Position */
#define IOTKIT_DUALTIMER_INTCLR_Msk          (0x1UL /*<< IOTKIT_DUALTIMER_INTCLR_Pos*/)       /* IOTKIT_DUALTIMER INTCLR: INT Clear  Mask */

/* IOTKIT_DUALTIMER_SINGLE RIS Register Definitions */
#define IOTKIT_DUALTIMER_RIS_Pos              0                                               /* IOTKIT_DUALTIMER RAWINTSTAT: Raw Int Status Position */
#define IOTKIT_DUALTIMER_RIS_Msk             (0x1UL /*<< IOTKIT_DUALTIMER_RAWINTSTAT_Pos*/)   /* IOTKIT_DUALTIMER RAWINTSTAT: Raw Int Status Mask */

/* IOTKIT_DUALTIMER_SINGLE MIS Register Definitions */
#define IOTKIT_DUALTIMER_MIS_Pos              0                                               /* IOTKIT_DUALTIMER MASKINTSTAT: Mask Int Status Position */
#define IOTKIT_DUALTIMER_MIS_Msk             (0x1UL /*<< IOTKIT_DUALTIMER_MASKINTSTAT_Pos*/)  /* IOTKIT_DUALTIMER MASKINTSTAT: Mask Int Status Mask */

/* IOTKIT_DUALTIMER_SINGLE BGLOAD Register Definitions */
#define IOTKIT_DUALTIMER_BGLOAD_Pos           0                                               /* IOTKIT_DUALTIMER BGLOAD: Background Load Position */
#define IOTKIT_DUALTIMER_BGLOAD_Msk          (0xFFFFFFFFUL /*<< IOTKIT_DUALTIMER_BGLOAD_Pos*/)/* IOTKIT_DUALTIMER BGLOAD: Background Load Mask */


/*-------------------- General Purpose Input Output (GPIO) -------------------*/
typedef struct
{
  __IOM  uint32_t DATA;                      /* Offset: 0x000 (R/W) DATA Register */
  __IOM  uint32_t DATAOUT;                   /* Offset: 0x004 (R/W) Data Output Latch Register */
         uint32_t RESERVED0[2];
  __IOM  uint32_t OUTENSET;                  /* Offset: 0x010 (R/W) Output Enable Set Register */
  __IOM  uint32_t OUTENCLR;                  /* Offset: 0x014 (R/W) Output Enable Clear Register */
  __IOM  uint32_t ALTFUNCSET;                /* Offset: 0x018 (R/W) Alternate Function Set Register */
  __IOM  uint32_t ALTFUNCCLR;                /* Offset: 0x01C (R/W) Alternate Function Clear Register */
  __IOM  uint32_t INTENSET;                  /* Offset: 0x020 (R/W) Interrupt Enable Set Register */
  __IOM  uint32_t INTENCLR;                  /* Offset: 0x024 (R/W) Interrupt Enable Clear Register */
  __IOM  uint32_t INTTYPESET;                /* Offset: 0x028 (R/W) Interrupt Type Set Register */
  __IOM  uint32_t INTTYPECLR;                /* Offset: 0x02C (R/W) Interrupt Type Clear Register */
  __IOM  uint32_t INTPOLSET;                 /* Offset: 0x030 (R/W) Interrupt Polarity Set Register */
  __IOM  uint32_t INTPOLCLR;                 /* Offset: 0x034 (R/W) Interrupt Polarity Clear Register */
  union {
  __IM   uint32_t INTSTATUS;                 /* Offset: 0x038 (R/ ) Interrupt Status Register */
  __OM   uint32_t INTCLEAR;                  /* Offset: 0x038 ( /W) Interrupt Clear Register */
    };
         uint32_t RESERVED1[241];
  __IOM  uint32_t LB_MASKED[256];            /* Offset: 0x400 - 0x7FC Lower byte Masked Access Register (R/W) */
  __IOM  uint32_t UB_MASKED[256];            /* Offset: 0x800 - 0xBFC Upper byte Masked Access Register (R/W) */
} IOTKIT_GPIO_TypeDef;

/* IOTKIT_GPIO DATA Register Definitions */
#define IOTKIT_GPIO_DATA_Pos            0                                                     /* IOTKIT_GPIO DATA: DATA Position */
#define IOTKIT_GPIO_DATA_Msk           (0xFFFFUL /*<< IOTKIT_GPIO_DATA_Pos*/)                 /* IOTKIT_GPIO DATA: DATA Mask */

/* IOTKIT_GPIO DATAOUT Register Definitions */
#define IOTKIT_GPIO_DATAOUT_Pos         0                                                     /* IOTKIT_GPIO DATAOUT: DATAOUT Position */
#define IOTKIT_GPIO_DATAOUT_Msk        (0xFFFFUL /*<< IOTKIT_GPIO_DATAOUT_Pos*/)              /* IOTKIT_GPIO DATAOUT: DATAOUT Mask */

/* IOTKIT_GPIO OUTENSET Register Definitions */
#define IOTKIT_GPIO_OUTENSET_Pos        0                                                     /* IOTKIT_GPIO OUTEN: OUTEN Position */
#define IOTKIT_GPIO_OUTENSET_Msk       (0xFFFFUL /*<< IOTKIT_GPIO_OUTEN_Pos*/)                /* IOTKIT_GPIO OUTEN: OUTEN Mask */

/* IOTKIT_GPIO OUTENCLR Register Definitions */
#define IOTKIT_GPIO_OUTENCLR_Pos        0                                                     /* IOTKIT_GPIO OUTEN: OUTEN Position */
#define IOTKIT_GPIO_OUTENCLR_Msk       (0xFFFFUL /*<< IOTKIT_GPIO_OUTEN_Pos*/)                /* IOTKIT_GPIO OUTEN: OUTEN Mask */

/* IOTKIT_GPIO ALTFUNCSET Register Definitions */
#define IOTKIT_GPIO_ALTFUNCSET_Pos      0                                                     /* IOTKIT_GPIO ALTFUNC: ALTFUNC Position */
#define IOTKIT_GPIO_ALTFUNCSET_Msk     (0xFFFFUL /*<< IOTKIT_GPIO_ALTFUNC_Pos*/)              /* IOTKIT_GPIO ALTFUNC: ALTFUNC Mask */

/* IOTKIT_GPIO ALTFUNCCLR Register Definitions */
#define IOTKIT_GPIO_ALTFUNCCLR_Pos      0                                                     /* IOTKIT_GPIO ALTFUNC: ALTFUNC Position */
#define IOTKIT_GPIO_ALTFUNCCLR_Msk     (0xFFFFUL /*<< IOTKIT_GPIO_ALTFUNC_Pos*/)              /* IOTKIT_GPIO ALTFUNC: ALTFUNC Mask */

/* IOTKIT_GPIO INTENSET Register Definitions */
#define IOTKIT_GPIO_INTENSET_Pos        0                                                     /* IOTKIT_GPIO INTEN: INTEN Position */
#define IOTKIT_GPIO_INTENSET_Msk       (0xFFFFUL /*<< IOTKIT_GPIO_INTEN_Pos*/)                /* IOTKIT_GPIO INTEN: INTEN Mask */

/* IOTKIT_GPIO INTENCLR Register Definitions */
#define IOTKIT_GPIO_INTENCLR_Pos        0                                                     /* IOTKIT_GPIO INTEN: INTEN Position */
#define IOTKIT_GPIO_INTENCLR_Msk       (0xFFFFUL /*<< IOTKIT_GPIO_INTEN_Pos*/)                /* IOTKIT_GPIO INTEN: INTEN Mask */

/* IOTKIT_GPIO INTTYPESET Register Definitions */
#define IOTKIT_GPIO_INTTYPESET_Pos      0                                                     /* IOTKIT_GPIO INTTYPE: INTTYPE Position */
#define IOTKIT_GPIO_INTTYPESET_Msk     (0xFFFFUL /*<< IOTKIT_GPIO_INTTYPE_Pos*/)              /* IOTKIT_GPIO INTTYPE: INTTYPE Mask */

/* IOTKIT_GPIO INTTYPECLR Register Definitions */
#define IOTKIT_GPIO_INTTYPECLR_Pos      0                                                     /* IOTKIT_GPIO INTTYPE: INTTYPE Position */
#define IOTKIT_GPIO_INTTYPECLR_Msk     (0xFFFFUL /*<< IOTKIT_GPIO_INTTYPE_Pos*/)              /* IOTKIT_GPIO INTTYPE: INTTYPE Mask */

/* IOTKIT_GPIO INTPOLSET Register Definitions */
#define IOTKIT_GPIO_INTPOLSET_Pos       0                                                     /* IOTKIT_GPIO INTPOL: INTPOL Position */
#define IOTKIT_GPIO_INTPOLSET_Msk      (0xFFFFUL /*<< IOTKIT_GPIO_INTPOL_Pos*/)               /* IOTKIT_GPIO INTPOL: INTPOL Mask */

/* IOTKIT_GPIO INTPOLCLR Register Definitions */
#define IOTKIT_GPIO_INTPOLCLR_Pos       0                                                     /* IOTKIT_GPIO INTPOL: INTPOL Position */
#define IOTKIT_GPIO_INTPOLCLR_Msk      (0xFFFFUL /*<< IOTKIT_GPIO_INTPOL_Pos*/)               /* IOTKIT_GPIO INTPOL: INTPOL Mask */

/* IOTKIT_GPIO INTCLEAR Register Definitions */
#define IOTKIT_GPIO_INTSTATUS_Pos       0                                                     /* IOTKIT_GPIO INTSTATUS: INTSTATUS Position */
#define IOTKIT_GPIO_INTCLEAR_Msk       (0xFFUL /*<< IOTKIT_GPIO_INTSTATUS_Pos*/)              /* IOTKIT_GPIO INTSTATUS: INTSTATUS Mask */

/* IOTKIT_GPIO INTCLEAR Register Definitions */
#define IOTKIT_GPIO_INTCLEAR_Pos        0                                                     /* IOTKIT_GPIO INTCLEAR: INTCLEAR Position */
#define IOTKIT_GPIO_INTCLEAR_Msk       (0xFFUL /*<< IOTKIT_GPIO_INTCLEAR_Pos*/)               /* IOTKIT_GPIO INTCLEAR: INTCLEAR Mask */

/* IOTKIT_GPIO MASKLOWBYTE Register Definitions */
#define IOTKIT_GPIO_MASKLOWBYTE_Pos     0                                                     /* IOTKIT_GPIO MASKLOWBYTE: MASKLOWBYTE Position */
#define IOTKIT_GPIO_MASKLOWBYTE_Msk    (0x00FFUL /*<< IOTKIT_GPIO_MASKLOWBYTE_Pos*/)          /* IOTKIT_GPIO MASKLOWBYTE: MASKLOWBYTE Mask */

/* IOTKIT_GPIO MASKHIGHBYTE Register Definitions */
#define IOTKIT_GPIO_MASKHIGHBYTE_Pos    0                                                     /* IOTKIT_GPIO MASKHIGHBYTE: MASKHIGHBYTE Position */
#define IOTKIT_GPIO_MASKHIGHBYTE_Msk   (0xFF00UL /*<< IOTKIT_GPIO_MASKHIGHBYTE_Pos*/)         /* IOTKIT_GPIO MASKHIGHBYTE: MASKHIGHBYTE Mask */


/*------------- System Control (SYSCON) --------------------------------------*/
typedef struct
{
  __IOM  uint32_t REMAP;                     /* Offset: 0x000 (R/W) Remap Control Register */
  __IOM  uint32_t PMUCTRL;                   /* Offset: 0x004 (R/W) PMU Control Register */
  __IOM  uint32_t RESETOP;                   /* Offset: 0x008 (R/W) Reset Option Register */
  __IOM  uint32_t EMICTRL;                   /* Offset: 0x00C (R/W) EMI Control Register */
  __IOM  uint32_t RSTINFO;                   /* Offset: 0x010 (R/W) Reset Information Register */
} IOTKIT_SYSCON_TypeDef;

/* IOTKIT_SYSCON REMAP Register Definitions */
#define IOTKIT_SYSCON_REMAP_Pos                 0
#define IOTKIT_SYSCON_REMAP_Msk                (0x1UL /*<< IOTKIT_SYSCON_REMAP_Pos*/)         /* IOTKIT_SYSCON MEME_CTRL: REMAP Mask */

/* IOTKIT_SYSCON PMUCTRL Register Definitions */
#define IOTKIT_SYSCON_PMUCTRL_EN_Pos            0
#define IOTKIT_SYSCON_PMUCTRL_EN_Msk           (0x1UL /*<< IOTKIT_SYSCON_PMUCTRL_EN_Pos*/)    /* IOTKIT_SYSCON PMUCTRL: PMUCTRL ENABLE Mask */

/* IOTKIT_SYSCON LOCKUPRST Register Definitions */
#define IOTKIT_SYSCON_LOCKUPRST_RESETOP_Pos     0
#define IOTKIT_SYSCON_LOCKUPRST_RESETOP_Msk    (0x1UL /*<< IOTKIT_SYSCON_LOCKUPRST_RESETOP_Pos*/)/* IOTKIT_SYSCON SYS_CTRL: LOCKUP RESET ENABLE Mask */

/* IOTKIT_SYSCON EMICTRL Register Definitions */
#define IOTKIT_SYSCON_EMICTRL_SIZE_Pos         24
#define IOTKIT_SYSCON_EMICTRL_SIZE_Msk         (0x1UL << IOTKIT_SYSCON_EMICTRL_SIZE_Pos)      /* IOTKIT_SYSCON EMICTRL: SIZE Mask */

#define IOTKIT_SYSCON_EMICTRL_TACYC_Pos        16
#define IOTKIT_SYSCON_EMICTRL_TACYC_Msk        (0x7UL << IOTKIT_SYSCON_EMICTRL_TACYC_Pos)     /* IOTKIT_SYSCON EMICTRL: TURNAROUNDCYCLE Mask */

#define IOTKIT_SYSCON_EMICTRL_WCYC_Pos          8
#define IOTKIT_SYSCON_EMICTRL_WCYC_Msk         (0x3UL << IOTKIT_SYSCON_EMICTRL_WCYC_Pos)      /* IOTKIT_SYSCON EMICTRL: WRITECYCLE Mask */

#define IOTKIT_SYSCON_EMICTRL_RCYC_Pos          0
#define IOTKIT_SYSCON_EMICTRL_RCYC_Msk         (0x7UL /*<< IOTKIT_SYSCON_EMICTRL_RCYC_Pos*/)  /* IOTKIT_SYSCON EMICTRL: READCYCLE Mask */

/* IOTKIT_SYSCON RSTINFO Register Definitions */
#define IOTKIT_SYSCON_RSTINFO_LOCKUPRESET_Pos   2
#define IOTKIT_SYSCON_RSTINFO_LOCKUPRESET_Msk  (0x1UL << IOTKIT_SYSCON_RSTINFO_LOCKUPRESET_Pos) /* IOTKIT_SYSCON RSTINFO: LOCKUPRESET Mask */

#define IOTKIT_SYSCON_RSTINFO_WDOGRESETREQ_Pos  1
#define IOTKIT_SYSCON_RSTINFO_WDOGRESETREQ_Msk (0x1UL << IOTKIT_SYSCON_RSTINFO_WDOGRESETREQ_Pos) /* IOTKIT_SYSCON RSTINFO: WDOGRESETREQ Mask */

#define IOTKIT_SYSCON_RSTINFO_SYSRESETREQ_Pos   0
#define IOTKIT_SYSCON_RSTINFO_SYSRESETREQ_Msk  (0x1UL /*<< IOTKIT_SYSCON_RSTINFO_SYSRESETREQ_Pos*/) /* IOTKIT_SYSCON RSTINFO: SYSRESETREQ Mask */


/*------------- PrimeCell Single Master DMA (PL081) -------------------------*/
typedef struct
{
  __IM   uint32_t IntStatus;                 /* Offset: 0x000 (R/ ) Interrupt Status Register */
  __IM   uint32_t IntTCStatus;               /* Offset: 0x004 (R/ ) Interrupt Terminal Count Status Register */
  __OM   uint32_t IntTCClear;                /* Offset: 0x008 (W/ ) Interrupt Terminal Count Clear Register */
  __IM   uint32_t IntErrorStatus;            /* Offset: 0x00C (R/ ) Interrupt Error Status Register */
  __OM   uint32_t IntErrClr;                 /* Offset: 0x010 (W/ ) Interrupt Error Clear Register */
  __IM   uint32_t RawIntTCStatus;            /* Offset: 0x014 (R/ ) Raw Interrupt Terminal Count Status Register */
  __IM   uint32_t RawIntErrorStatus;         /* Offset: 0x018 (R/ ) Raw Error Interrupt Status Register */
  __IM   uint32_t EnbldChns;                 /* Offset: 0x01C (R/ ) Enabled Channel Register */
  __IOM  uint32_t SoftBReq;                  /* Offset: 0x020 (R/W) Software Burst Request Register */
  __IOM  uint32_t SoftSReq;                  /* Offset: 0x024 (R/W) Software Single Request Register */
  __IOM  uint32_t SoftLBReq;                 /* Offset: 0x028 (R/W) Software Last Burst Request Register */
  __IOM  uint32_t SoftLSReq;                 /* Offset: 0x02C (R/W) Software Last Single Request Register */
  __IOM  uint32_t Configuration;             /* Offset: 0x030 (R/W) Configuration Register */
  __IOM  uint32_t Sync;                      /* Offset: 0x034 (R/W) Synchronization Register */
         uint32_t RESERVED0[50];
  __IOM  uint32_t C0SrcAddr;                 /* Offset: 0x100 (R/W) Channel Source Address Registers */
  __IOM  uint32_t C0DestAddr;                /* Offset: 0x104 (R/W) Channel Destination Address Registers */
  __IOM  uint32_t C0LLI;                     /* Offset: 0x108 (R/W) Channel Linked List Item Register */
  __IOM  uint32_t C0Control;                 /* Offset: 0x10C (R/W) Channel Control Register */
  __IOM  uint32_t C0Configuration;           /* Offset: 0x110 (R/W) Channel Configuration Register */
         uint32_t RESERVED1[3];
  __IOM  uint32_t C1SrcAddr;                 /* Offset: 0x120 (R/W) Channel Source Address Register */
  __IOM  uint32_t C1DestAddr;                /* Offset: 0x124 (R/W) Channel Destination Address Register */
  __IOM  uint32_t C1LLI;                     /* Offset: 0x128 (R/W) Channel Linked List Item Register */
  __IOM  uint32_t C1Control;                 /* Offset: 0x12C (R/W) Channel Control Registers on page */
  __IOM  uint32_t C1Configuration;           /* Offset: 0x130 (R/W) Channel Configuration Register */
} IOTKIT_PL081_TypeDef;


/*------------------- Watchdog ----------------------------------------------*/
typedef struct
{
  __IOM  uint32_t LOAD;                     /* Offset: 0x000 (R/W) Watchdog Load Register */
  __IM   uint32_t VALUE;                    /* Offset: 0x004 (R/ ) Watchdog Value Register */
  __IOM  uint32_t CTRL;                     /* Offset: 0x008 (R/W) Watchdog Control Register */
  __OM   uint32_t INTCLR;                   /* Offset: 0x00C ( /W) Watchdog Clear Interrupt Register */
  __IM   uint32_t RAWINTSTAT;               /* Offset: 0x010 (R/ ) Watchdog Raw Interrupt Status Register */
  __IM   uint32_t MASKINTSTAT;              /* Offset: 0x014 (R/ ) Watchdog Interrupt Status Register */
         uint32_t RESERVED0[762];
  __IOM  uint32_t LOCK;                     /* Offset: 0xC00 (R/W) Watchdog Lock Register */
         uint32_t RESERVED1[191];
  __IOM  uint32_t ITCR;                     /* Offset: 0xF00 (R/W) Watchdog Integration Test Control Register */
  __OM   uint32_t ITOP;                     /* Offset: 0xF04 ( /W) Watchdog Integration Test Output Set Register */
} IOTKIT_WATCHDOG_TypeDef;

/* IOTKIT_WATCHDOG LOAD Register Definitions */
#define IOTKIT_Watchdog_LOAD_Pos               0                                              /* IOTKIT_Watchdog LOAD: LOAD Position */
#define IOTKIT_Watchdog_LOAD_Msk              (0xFFFFFFFFUL /*<< IOTKIT_Watchdog_LOAD_Pos*/)  /* IOTKIT_Watchdog LOAD: LOAD Mask */

/* IOTKIT_WATCHDOG VALUE Register Definitions */
#define IOTKIT_Watchdog_VALUE_Pos              0                                              /* IOTKIT_Watchdog VALUE: VALUE Position */
#define IOTKIT_Watchdog_VALUE_Msk             (0xFFFFFFFFUL /*<< IOTKIT_Watchdog_VALUE_Pos*/) /* IOTKIT_Watchdog VALUE: VALUE Mask */

/* IOTKIT_WATCHDOG CTRL Register Definitions */
#define IOTKIT_Watchdog_CTRL_RESEN_Pos         1                                              /* IOTKIT_Watchdog CTRL_RESEN: Enable Reset Output Position */
#define IOTKIT_Watchdog_CTRL_RESEN_Msk        (0x1UL << IOTKIT_Watchdog_CTRL_RESEN_Pos)       /* IOTKIT_Watchdog CTRL_RESEN: Enable Reset Output Mask */

#define IOTKIT_Watchdog_CTRL_INTEN_Pos         0                                              /* IOTKIT_Watchdog CTRL_INTEN: Int Enable Position */
#define IOTKIT_Watchdog_CTRL_INTEN_Msk        (0x1UL /*<< IOTKIT_Watchdog_CTRL_INTEN_Pos*/)   /* IOTKIT_Watchdog CTRL_INTEN: Int Enable Mask */

/* IOTKIT_WATCHDOG INTCLR Register Definitions */
#define IOTKIT_Watchdog_INTCLR_Pos             0                                              /* IOTKIT_Watchdog INTCLR: Int Clear Position */
#define IOTKIT_Watchdog_INTCLR_Msk            (0x1UL /*<< IOTKIT_Watchdog_INTCLR_Pos*/)       /* IOTKIT_Watchdog INTCLR: Int Clear Mask */

/* IOTKIT_WATCHDOG RAWINTSTAT Register Definitions */
#define IOTKIT_Watchdog_RAWINTSTAT_Pos         0                                              /* IOTKIT_Watchdog RAWINTSTAT: Raw Int Status Position */
#define IOTKIT_Watchdog_RAWINTSTAT_Msk        (0x1UL /*<< IOTKIT_Watchdog_RAWINTSTAT_Pos*/)   /* IOTKIT_Watchdog RAWINTSTAT: Raw Int Status Mask */

/* IOTKIT_WATCHDOG MASKINTSTAT Register Definitions */
#define IOTKIT_Watchdog_MASKINTSTAT_Pos        0                                              /* IOTKIT_Watchdog MASKINTSTAT: Mask Int Status Position */
#define IOTKIT_Watchdog_MASKINTSTAT_Msk       (0x1UL /*<< IOTKIT_Watchdog_MASKINTSTAT_Pos*/)  /* IOTKIT_Watchdog MASKINTSTAT: Mask Int Status Mask */

/* IOTKIT_WATCHDOG LOCK Register Definitions */
#define IOTKIT_Watchdog_LOCK_Pos               0                                              /* IOTKIT_Watchdog LOCK: LOCK Position */
#define IOTKIT_Watchdog_LOCK_Msk              (0x1UL /*<< IOTKIT_Watchdog_LOCK_Pos*/)         /* IOTKIT_Watchdog LOCK: LOCK Mask */

/* IOTKIT_WATCHDOG INTEGTESTEN Register Definitions */
#define IOTKIT_Watchdog_INTEGTESTEN_Pos        0                                              /* IOTKIT_Watchdog INTEGTESTEN: Integration Test Enable Position */
#define IOTKIT_Watchdog_INTEGTESTEN_Msk       (0x1UL /*<< IOTKIT_Watchdog_INTEGTESTEN_Pos*/)  /* IOTKIT_Watchdog INTEGTESTEN: Integration Test Enable Mask */

/* IOTKIT_WATCHDOG INTEGTESTOUTSET Register Definitions */
#define IOTKIT_Watchdog_INTEGTESTOUTSET_Pos    1                                              /* IOTKIT_Watchdog INTEGTESTOUTSET: Integration Test Output Set Position */
#define IOTKIT_Watchdog_INTEGTESTOUTSET_Msk   (0x1UL /*<< IOTKIT_Watchdog_INTEGTESTOUTSET_Pos*/) /* IOTKIT_Watchdog INTEGTESTOUTSET: Integration Test Output Set Mask */


/*------------------- Memory Protection Controller -----------------------------*/
typedef struct
{
  __IOM  uint32_t CTRL;                     /* Offset: 0x000 (R/W) Control Register */
         uint32_t RESERVED0[3];
  __IM   uint32_t BLK_MAX;                  /* Offset: 0x010 (R/ ) Block Maximum Register */
  __IM   uint32_t BLK_CFG;                  /* Offset: 0x014 (R/ ) Block Configuration Register */
  __IOM  uint32_t BLK_IDX;                  /* Offset: 0x018 (R/W) Block Index Register */
  __IOM  uint32_t BLK_LUT;                  /* Offset: 0x01C (R/W) Block Lookup Tabe Register */
  __IM   uint32_t INT_STAT;                 /* Offset: 0x020 (R/ ) Interrupt Status Register */
  __OM   uint32_t INT_CLEAR;                /* Offset: 0x024 ( /W) Interrupt Clear Register */
  __IOM  uint32_t INT_EN;                   /* Offset: 0x028 (R/W) Interrupt Enable Register */
  __IM   uint32_t INT_INFO1;                /* Offset: 0x02C (R/ ) Interrupt Info1 Register */
  __IM   uint32_t INT_INFO2;                /* Offset: 0x030 (R/ ) Interrupt Info2 Register */
  __OM   uint32_t INT_SET;                  /* Offset: 0x034 ( /W) Interrupt Set Register */
} IOTKIT_MPC_TypeDef;


/*------------------- Secure Privilege Control Block -----------------------------*/
typedef struct
{
         uint32_t RESERVED0[4U];
  __IOM  uint32_t SECRESPCFG;               /* Offset: 0x010 (R/W) Security Violation Response Configuration Register */
  __IOM  uint32_t NSCCFG;                   /* Offset: 0x014 (R/W) Non Secure Callable Configuration for IDAU */
         uint32_t RESERVED1[1U];
  __IM   uint32_t SECMPCINTSTATUS;          /* Offset: 0x01C (R/ ) Secure MPC Interrupt Status */
  __IM   uint32_t SECPPCINTSTAT;            /* Offset: 0x020 (R/ ) Secure PPC Interrupt Status */
  __OM   uint32_t SECPPCINTCLR;             /* Offset: 0x024 ( /W) Secure PPC Interrupt Clear */
  __IOM  uint32_t SECPPCINTEN;              /* Offset: 0x028 (R/W) Secure PPC Interrupt Enable */
         uint32_t RESERVED2[1U];
  __IM   uint32_t SECMSCINTSTAT;            /* Offset: 0x030 (R/ ) Secure MSC Interrupt Status */
  __OM   uint32_t SECMSCINTCLR;             /* Offset: 0x034 ( /W) Secure MSC Interrupt Clear */
  __IOM  uint32_t SECMSCINTEN;              /* Offset: 0x038 (R/W) Secure MSC Interrupt Enable */
         uint32_t RESERVED3[1U];
  __IM   uint32_t BRGINTSTAT;               /* Offset: 0x040 (R/ ) Bridge Buffer Error Interrupt Status */
  __OM   uint32_t BRGINTCLR;                /* Offset: 0x044 ( /W) Bridge Buffer Error Interrupt Clear */
  __IOM  uint32_t BRGINTEN;                 /* Offset: 0x048 (R/W) Bridge Buffer Error Interrupt Enable */
         uint32_t RESERVED4[1U];
  __IOM  uint32_t AHBNSPPC[4U];             /* Offset: 0x050 (R/W) Non-Secure Access AHB slave Peripheral Protection Control */
  __IOM  uint32_t AHBNSPPCEXP[4U];          /* Offset: 0x060 (R/W) Expansion Non_Secure Access AHB slave Peripheral Protection Control */
  __IOM  uint32_t APBNSPPC[4U];             /* Offset: 0x070 (R/W) Non-Secure Access APB slave Peripheral Protection Control */
  __IOM  uint32_t APBNSPPCEXP[4U];          /* Offset: 0x080 (R/W) Expansion Non_Secure Access APB slave Peripheral Protection Control */
  __IM   uint32_t AHBSPPPC[4U];             /* Offset: 0x090 (R/ ) Secure Unprivileged Access AHB slave Peripheral Protection Control */
  __IOM  uint32_t AHBSPPPCEXP[4U];          /* Offset: 0x0A0 (R/W) Expansion Secure Unprivileged Access AHB slave Peripheral Protection Control */
  __IOM  uint32_t APBSPPPC[4U];             /* Offset: 0x0B0 (R/W) Secure Unprivileged Access APB slave Peripheral Protection Control */
  __IOM  uint32_t APBSPPPCEXP[4U];          /* Offset: 0x0C0 (R/W) Expansion Secure Unprivileged Access APB slave Peripheral Protection Control */
  __IM   uint32_t NSMSCEXP;                 /* Offset: 0x0D0 (R/ ) Expansion MSC Non-Secure Configuration */
}IOTKIT_SPC_TypeDef;


/*------------------- Non-Secure Privilege Control Block -----------------------------*/
typedef struct
{
         uint32_t RESERVED0[36U];
  __IOM  uint32_t AHBNSPPPC[4U];            /* Offset: 0x090 (R/W)  read-write 0x0000_0000 Non-Secure Unprivileged Access AHB slave Peripheral Protection Control */
  __IOM  uint32_t AHBNSPPPCEXP[4U];         /* Offset: 0x0A0 (R/W)  read-write 0x0000_0000 Expansion 0 Non-Secure Unprivileged Access AHB slave Peripheral Protection Control */
  __IOM  uint32_t APBNSPPPC[4U];            /* Offset: 0x0B0 (R/W)  read-write 0x0000_0000 Non-Secure Unprivileged Access APB slave Peripheral Protection Control */
  __IOM  uint32_t APBNSPPPCEXP[4U];         /* Offset: 0x0C0 (R/W)  read-write 0x0000_0000 Expansion 0 Non-Secure Unprivileged Access APB slave Peripheral Protection Control */
} IOTKIT_NSPC_TypeDef;


/* --------------------  End of section using anonymous unions  ------------------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif




/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

/* --- peripherals */
#define IOTKIT_TIMER0_BASE       (0x40000000UL)
#define IOTKIT_TIMER1_BASE       (0x40001000UL)
#define IOTKIT_DUALTIMER_BASE    (0x40002000UL)
#define IOTKIT_DUALTIMER_1_BASE  (IOTKIT_DUALTIMER_BASE)
#define IOTKIT_DUALTIMER_2_BASE  (IOTKIT_DUALTIMER_BASE + 0x20UL)
#define IOTKIT_WATCHDOG_BASE     (0x40081000UL)

/* --- peripherals */
#define IOTKIT_GPIO0_BASE        (0x40100000UL)
#define IOTKIT_GPIO1_BASE        (0x40101000UL)
#define IOTKIT_GPIO2_BASE        (0x40102000UL)
#define IOTKIT_GPIO3_BASE        (0x40103000UL)

#define IOTKIT_DMA0_BASE         (0x40110000UL)
#define IOTKIT_DMA1_BASE         (0x40111000UL)
#define IOTKIT_DMA2_BASE         (0x40112000UL)
#define IOTKIT_DMA3_BASE         (0x40113000UL)

#define IOTKIT_UART0_BASE        (0x40200000UL)
#define IOTKIT_UART1_BASE        (0x40201000UL)
#define IOTKIT_UART2_BASE        (0x40202000UL)
#define IOTKIT_UART3_BASE        (0x40203000UL)
#define IOTKIT_UART4_BASE        (0x40204000UL)

#define IOTKIT_SYSCTRL_BASE      (0x40116000UL)

#define IOTKIT_NSPC_BASE         (0x40080000UL)
#define IOTKIT_SPC_BASE          (0x50080000UL)
#define IOTKIT_MPCSSRAM1_BASE    (0x58007000UL)
#define IOTKIT_MPCSSRAM2_BASE    (0x58008000UL)
#define IOTKIT_MPCSSRAM3_BASE    (0x58009000UL)

/* ================================================================================ */
/* ================          Secure Peripheral memory map          ================ */
/* ================================================================================ */

/* --- peripherals */
#define IOTKIT_SECURE_TIMER0_BASE       (0x50000000UL)
#define IOTKIT_SECURE_TIMER1_BASE       (0x50001000UL)
#define IOTKIT_SECURE_DUALTIMER_BASE    (0x50002000UL)
#define IOTKIT_SECURE_DUALTIMER_1_BASE  (IOTKIT_SECURE_DUALTIMER_BASE)
#define IOTKIT_SECURE_DUALTIMER_2_BASE  (IOTKIT_SECURE_DUALTIMER_BASE + 0x20UL)

/* AHB peripherals */
#define IOTKIT_SECURE_GPIO0_BASE        (0x50100000UL)
#define IOTKIT_SECURE_GPIO1_BASE        (0x50101000UL)
#define IOTKIT_SECURE_GPIO2_BASE        (0x50102000UL)
#define IOTKIT_SECURE_GPIO3_BASE        (0x50103000UL)

#define IOTKIT_SECURE_DMA0_BASE         (0x50110000UL)
#define IOTKIT_SECURE_DMA1_BASE         (0x50111000UL)
#define IOTKIT_SECURE_DMA2_BASE         (0x50112000UL)
#define IOTKIT_SECURE_DMA3_BASE         (0x50113000UL)

#define IOTKIT_SECURE_UART0_BASE        (0x50200000UL)
#define IOTKIT_SECURE_UART1_BASE        (0x50201000UL)
#define IOTKIT_SECURE_UART2_BASE        (0x50202000UL)
#define IOTKIT_SECURE_UART3_BASE        (0x50203000UL)
#define IOTKIT_SECURE_UART4_BASE        (0x50204000UL)

#define IOTKIT_SECURE_SYSCTRL_BASE      (0x50116000UL)


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */
#define IOTKIT_TIMER0            ((IOTKIT_TIMER_TypeDef             *) IOTKIT_TIMER0_BASE      )
#define IOTKIT_TIMER1            ((IOTKIT_TIMER_TypeDef             *) IOTKIT_TIMER1_BASE      )
#define IOTKIT_DUALTIMER         ((IOTKIT_DUALTIMER_BOTH_TypeDef    *) IOTKIT_DUALTIMER_BASE   )
#define IOTKIT_DUALTIMER1        ((IOTKIT_DUALTIMER_SINGLE_TypeDef  *) IOTKIT_DUALTIMER_1_BASE )
#define IOTKIT_DUALTIMER2        ((IOTKIT_DUALTIMER_SINGLE_TypeDef  *) IOTKIT_DUALTIMER_2_BASE )
#define IOTKIT_WATCHDOG          ((IOTKIT_WATCHDOG_TypeDef          *) IOTKIT_WATCHDOG_BASE    )

#define IOTKIT_GPIO0             ((IOTKIT_GPIO_TypeDef              *) IOTKIT_GPIO0_BASE       )
#define IOTKIT_GPIO1             ((IOTKIT_GPIO_TypeDef              *) IOTKIT_GPIO1_BASE       )
#define IOTKIT_GPIO2             ((IOTKIT_GPIO_TypeDef              *) IOTKIT_GPIO2_BASE       )
#define IOTKIT_GPIO3             ((IOTKIT_GPIO_TypeDef              *) IOTKIT_GPIO3_BASE       )

#define IOTKIT_DMA0              ((IOTKIT_PL081_TypeDef             *) IOTKIT_DMA0_BASE       )
#define IOTKIT_DMA1              ((IOTKIT_PL081_TypeDef             *) IOTKIT_DMA1_BASE       )
#define IOTKIT_DMA2              ((IOTKIT_PL081_TypeDef             *) IOTKIT_DMA2_BASE       )
#define IOTKIT_DMA3              ((IOTKIT_PL081_TypeDef             *) IOTKIT_DMA3_BASE       )

#define IOTKIT_UART0             ((IOTKIT_UART_TypeDef              *) IOTKIT_UART0_BASE       )
#define IOTKIT_UART1             ((IOTKIT_UART_TypeDef              *) IOTKIT_UART1_BASE       )
#define IOTKIT_UART2             ((IOTKIT_UART_TypeDef              *) IOTKIT_UART2_BASE       )
#define IOTKIT_UART3             ((IOTKIT_UART_TypeDef              *) IOTKIT_UART3_BASE       )
#define IOTKIT_UART4             ((IOTKIT_UART_TypeDef              *) IOTKIT_UART4_BASE       )

#define IOTKIT_SYSCON            ((IOTKIT_SYSCON_TypeDef            *) IOTKIT_SYSCTRL_BASE     )

#define IOTKIT_NSPC              ((IOTKIT_NSPC_TypeDef              *) IOTKIT_NSPC_BASE        )
#define IOTKIT_SPC               ((IOTKIT_SPC_TypeDef               *) IOTKIT_SPC_BASE         )
#define IOTKIT_MPCSSRAM1         ((IOTKIT_MPC_TypeDef               *) IOTKIT_MPCSSRAM1_BASE   )
#define IOTKIT_MPCSSRAM2         ((IOTKIT_MPC_TypeDef               *) IOTKIT_MPCSSRAM2_BASE   )
#define IOTKIT_MPCSSRAM3         ((IOTKIT_MPC_TypeDef               *) IOTKIT_MPCSSRAM3_BASE   )


#define IOTKIT_SECURE_TIMER0     ((IOTKIT_TIMER_TypeDef             *) IOTKIT_SECURE_TIMER0_BASE      )
#define IOTKIT_SECURE_TIMER1     ((IOTKIT_TIMER_TypeDef             *) IOTKIT_SECURE_TIMER1_BASE      )
#define IOTKIT_SECURE_DUALTIMER  ((IOTKIT_DUALTIMER_BOTH_TypeDef    *) IOTKIT_SECURE_DUALTIMER_BASE   )
#define IOTKIT_SECURE_DUALTIMER1 ((IOTKIT_DUALTIMER_SINGLE_TypeDef  *) IOTKIT_SECURE_DUALTIMER_1_BASE )
#define IOTKIT_SECURE_DUALTIMER2 ((IOTKIT_DUALTIMER_SINGLE_TypeDef  *) IOTKIT_SECURE_DUALTIMER_2_BASE )
#define IOTKIT_SECURE_WATCHDOG   ((IOTKIT_WATCHDOG_TypeDef          *) IOTKIT_SECURE_WATCHDOG_BASE    )

#define IOTKIT_SECURE_GPIO0      ((IOTKIT_GPIO_TypeDef              *) IOTKIT_SECURE_GPIO0_BASE       )
#define IOTKIT_SECURE_GPIO1      ((IOTKIT_GPIO_TypeDef              *) IOTKIT_SECURE_GPIO1_BASE       )
#define IOTKIT_SECURE_GPIO2      ((IOTKIT_GPIO_TypeDef              *) IOTKIT_SECURE_GPIO2_BASE       )
#define IOTKIT_SECURE_GPIO3      ((IOTKIT_GPIO_TypeDef              *) IOTKIT_SECURE_GPIO3_BASE       )

#define IOTKIT_SECURE_DMA0       ((IOTKIT_PL081_TypeDef             *) IOTKIT_SECURE_DMA0_BASE        )
#define IOTKIT_SECURE_DMA1       ((IOTKIT_PL081_TypeDef             *) IOTKIT_SECURE_DMA1_BASE        )
#define IOTKIT_SECURE_DMA2       ((IOTKIT_PL081_TypeDef             *) IOTKIT_SECURE_DMA2_BASE        )
#define IOTKIT_SECURE_DMA3       ((IOTKIT_PL081_TypeDef             *) IOTKIT_SECURE_DMA3_BASE        )

#define IOTKIT_SECURE_UART0      ((IOTKIT_UART_TypeDef              *) IOTKIT_SECURE_UART0_BASE       )
#define IOTKIT_SECURE_UART1      ((IOTKIT_UART_TypeDef              *) IOTKIT_SECURE_UART1_BASE       )
#define IOTKIT_SECURE_UART2      ((IOTKIT_UART_TypeDef              *) IOTKIT_SECURE_UART2_BASE       )
#define IOTKIT_SECURE_UART3      ((IOTKIT_UART_TypeDef              *) IOTKIT_SECURE_UART3_BASE       )
#define IOTKIT_SECURE_UART4      ((IOTKIT_UART_TypeDef              *) IOTKIT_SECURE_UART4_BASE       )

#define IOTKIT_SECURE_SYSCON     ((IOTKIT_SYSCON_TypeDef            *) IOTKIT_SECURE_SYSCTRL_BASE     )

#ifdef __cplusplus
}
#endif

#endif  /* IOTKit_ARMv8MBL_H */
