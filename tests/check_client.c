#include <riack/riack.h>

START_TEST (test_riack_client_new_and_free)
{
  riack_client_t *client;

  client = riack_client_new ();
  ck_assert (client != NULL);

  ck_assert_errno (riack_client_free (NULL), EINVAL);
  ck_assert_errno (riack_client_free (client), ENOTCONN);
}
END_TEST

static TCase *
test_riack_client (void)
{
  TCase *test_client;

  test_client = tcase_create ("Client");
  tcase_add_test (test_client, test_riack_client_new_and_free);

  return test_client;
}
