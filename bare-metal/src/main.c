#include "mycode.h"

#ifdef UNIT_TEST
	int mainTest (void);
#endif

int main (void) {

	#ifdef UNIT_TEST
		mainTest();
	#else
		mainApp();
	#endif

}
