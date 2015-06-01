#include <check.h>

#include <errno.h>
#include <stdlib.h>

#include "riack/platform.h"
#include "tests.h"

#include "check_library.c"

int
main (void)
{
  Suite *suite;
  SRunner *runner;

  int nfailed;

  suite = suite_create ("Riack tests");

  suite_add_tcase (suite, test_riack_library ());

  runner = srunner_create (suite);

  srunner_run_all (runner, CK_ENV);
  nfailed = srunner_ntests_failed (runner);
  srunner_free (runner);

  return (nfailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
