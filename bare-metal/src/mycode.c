#include "mycode.h"
#include <stdio.h>
//#include <arm_cmse.h>
#include "IOTKit_ARMv8MBL.h"                         /* Device, processor and core peripherals */

void mainApp (void){

	  volatile int b = 10;
	  int c;

	  stdout_init();
	  printf("Starting Main App\n\r");

	  c = myfunction(b);

	  printf("The result is: %d \n\r", c);

}

int myfunction (int a){
	volatile int d = 10;

	return (a*d);
}
