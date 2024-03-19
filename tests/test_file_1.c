#include "test_file_1.h"
#include "minunit.h"

MU_TEST(test_file1) {
  ASSERT_EQ_INT(5, 5);
  ASSERT_STREQ("World!", "World!");
}

MU_TEST_SUITE(test_suite_file1) { MU_RUN_TEST(test_file1); }
