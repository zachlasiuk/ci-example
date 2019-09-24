#include "mycode.h"
#include "unity.h"

/* sometimes you may want to get at local data in a module.
 * for example: If you plan to pass by reference, this could be useful
 * however, it should often be avoided */
int Counter;

void setUp(void)
{
  /* This is run before EACH TEST */
  Counter = 10;
}

void tearDown(void)
{
}

void test_myfunction_test1(void)
{
    /* This should be true because setUp set this up for us before this test */
    TEST_ASSERT_EQUAL_INT(100, myfunction(Counter));

    /* This should be true because we can still change our answer */
    Counter = 20;
    TEST_ASSERT_EQUAL_INT(200, myfunction(Counter));
}

void test_myfunction_test2(void)
{
    /* This should be true again because setup was rerun before this test (and after we changed it to 0x1234) */
    TEST_ASSERT_EQUAL_INT(100, myfunction(Counter));
}

void test_myfunction_test3(void)
{
    /* This should be true again because setup was rerun before this test (and after we changed it to 0x1234) */
    TEST_ASSERT_EQUAL_INT(101, myfunction(Counter));
}

void test_mainApp_test(void)
{
	TEST_IGNORE();
}


