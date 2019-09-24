/*-----------------------------------------------------------------------------
 * Name:    stdout_USART.c
 * Purpose: STDOUT USART Template
 * Rev.:    1.0.0
 *-----------------------------------------------------------------------------*/
 
/* Copyright (c) 2013 - 2015 ARM LIMITED

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

#include "Device.h"                     // Keil.V2M-MPS2::Board Support:Common
#include "RTE_Components.h"             // Component selection

 
//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

 
// <h>STDOUT USART Interface
 
//   <o>Baudrate
#define USART_BAUDRATE          115200
 
// </h>
 
/**
  Initialize stdout

  \return          0 on success, or -1 on error.
*/
int stdout_init (void);
int stdout_init (void) {

#ifdef RTE_Compiler_IO_STDOUT_User
  SystemCoreClockUpdate();

  CMSDK_GPIO1->ALTFUNCSET |= ((1ul <<  0) |          /* configure GPIO pin    */
                              (1ul <<  1) );

  CMSDK_UART0->BAUDDIV = SystemCoreClock / USART_BAUDRATE;
  CMSDK_UART0->CTRL    = ((1ul <<  0) |              /* TX enable */
                          (1ul <<  1) );             /* RX enable */
#endif
  return (0);
}


/**
  Put a character to the stdout

  \param[in]   ch  Character to output
  \return          The character written, or -1 on write error.
*/
int stdout_putchar (int ch);
int stdout_putchar (int ch) {

#ifdef RTE_Compiler_IO_STDOUT_User
  while ( (CMSDK_UART0->STATE & (1ul << 0))); /* Wait if Transmit Holding register is full */
  CMSDK_UART0->DATA = (unsigned int)ch;
#endif
  return (ch);
}
