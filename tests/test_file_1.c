#include "test_file_1.h"

#include "../src/compiler.h"
#include "../src/debug.h"
#include "../src/vm.h"
#include "minunit.h"

MU_TEST(test_basic_expression) {
  initVM();
  InterpretResult result = interpret("!(5 - 4 > 3 * 2 == !nil)");
  ASSERT_EQ(result, INTERPRET_OK, "TEST");

  /* ASSERT_EQ(p. , 2, "TEST"); */
  freeVM();
}

MU_TEST_SUITE(test_suite_file1) { MU_RUN_TEST(test_basic_expression); }
