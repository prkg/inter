#include "test_file_2.h"
#include "minunit.h"

#include <stdio.h>

MU_TEST(test_file2) {
  char errBuf[200];
  int expected = 1234;
  int real = 1233;
  int maxAllowedAbsErr = 2;

  (void)sprintf(errBuf,
                "Expected = %u  -  Real = %u, maximal allowed error = %u\n",
                expected, real, maxAllowedAbsErr);
  ASSERT_NEAR_INT(expected, real, maxAllowedAbsErr, errBuf);
}

MU_TEST_SUITE(test_suite_file2) { MU_RUN_TEST(test_file2); }
